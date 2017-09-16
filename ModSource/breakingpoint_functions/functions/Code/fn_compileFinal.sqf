/*
        Author: Killzone_Kid

        Description:
        Recompiles existing code to final

        Parameter(s):
        _this select 0: STRING 
            - name of the variable containing code
            - variables containing no code are ignored

        _this select 1: NAMESPACE (Optional)
            - namespace of the variable containing code
            - if no namespace provided missionNamespace is assumed
            
        Returns: BOOL
            - true on success 
            - false on failure

        Example 1:
            myCode = {
                hint "This is my code!"
            };
            //recompile myCode to final
            ["myCode"] call BIS_fnc_compileFinal;
        
        Example 2:
            with uiNamespace do {
                myCode2 = {
                    hint "This is my code too!"
                }
            };
            //recompile myCode2 to final and alert on success
            if (["myCode2",uiNamespace] call BIS_fnc_compileFinal) then {
                hint "Success!"
            };
*/
    
private ["_code","_arr"];
params [["_var","",[""]],["_ns",missionNamespace,[missionNamespace]]];
_code = _ns getVariable [_var, 0];
if (typeName _code != typeName {}) exitWith {false};
_arr = toArray str _code;
_arr set [0,32];
_arr set [count _arr - 1,32];
_code = compileFinal toString _arr;
_ns setVariable [_var, _code];
true