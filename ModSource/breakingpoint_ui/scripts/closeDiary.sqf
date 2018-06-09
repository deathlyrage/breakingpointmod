disableSerialization;
sleep 0.1;
for [{_i = 0},{_i<1000},{_i = _i + 1}] do 
{
	_display = findDisplay 140;
	_display closeDisplay 0;
	_display closeDisplay 1;
	_display closeDisplay 2;
};
true;
