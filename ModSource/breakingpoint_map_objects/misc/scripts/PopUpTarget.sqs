_target= _this select 0
_target setdammage 0

?_target animationPhase "terc" > 0: goto "end"
_target animate["terc",1]
?nopop: goto "end"
~3
?nopop: goto "end"
?alive _target: _target animate["terc",0]

#end
exit