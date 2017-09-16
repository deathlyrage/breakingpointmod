disableSerialization;
if !(cadetMode) then 
{

	_scrambleRadius = 500;
	_display = _this select 0;	
	_mapCtrl = _display displayctrl 561;	 
	ctrlMapAnimClear _mapCtrl;
	_WP0position = getWPPos [player, 0];

	_UnitPos = [((_WP0position  select 0) + (random (_scrambleRadius*2)) - _scrambleRadius),  ((_WP0position select 1) + (random (_scrambleRadius*2)) - _scrambleRadius)];	 
		 
	_mapCtrl ctrlMapAnimAdd [0, 3, _UnitPos]; 
	ctrlMapAnimCommit _mapCtrl;
};
