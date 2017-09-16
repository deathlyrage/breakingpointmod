
BP_DetectedScripts = [];

if !(BP_FastBoot) then
{
	_scripts = [];
	[_scripts,["CHILD:900:%1:",4],"CustomStreamStart"] call BPServer_fnc_callExtensionArray;	
	
	{ 0 = BP_DetectedScripts pushBack (_x select 0); } count _scripts;
};

publicVariable "BP_DetectedScripts";