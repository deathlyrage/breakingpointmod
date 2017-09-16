/*
	Author: Jiri Wainar

	Description:
	Return object height defined by it's bounding box and ev. offset/fix.

	Parameter(s):
	_this:object 	- input/evaluated object

	Returns:
	_height:scalar	- height of the evaluated object

	Example:
	_height = _object call BIS_fnc_objectHeight;
*/

private["_bbox","_objHeight","_objHeightAdj","_class"];

if (isNil {_this}) exitWith
{
	["Object is nil!"] call BIS_fnc_error;
	0
};

if (isNull _this) exitWith
{
	["Object is null!"] call BIS_fnc_error;
	0
};

_class = toLower (typeOf _this);

_objHeightAdj = switch (_class) do
{
	//ammo box style
	case "box_east_support_f";
	case "box_ind_support_f";
	case "box_nato_support_f";
	case "box_east_ammoord_f";
	case "box_ind_ammoord_f";
	case "box_nato_ammoord_f";
	case "box_east_ammo_f";
	case "box_ind_ammo_f";
	case "box_nato_ammo_f": {-0.10};

	//weapon box style
	case "box_east_wpslaunch_f";
	case "box_ind_wpslaunch_f";
	case "box_nato_wpslaunch_f";
	case "box_east_wpsspecial_f";
	case "box_ind_wpsspecial_f";
	case "box_nato_wpsspecial_f";
	case "box_ind_wps_f";
	case "box_east_wps_f";
	case "box_nato_wps_f": {-0.08};


	case "land_campingtable_f";
	case "land_campingtable_small_f": {0.0};

	default {-0.0};
};

_bbox = boundingBoxReal _this;

_objHeight = ((_bbox select 1) select 2) - ((_bbox select 0) select 2);
_objHeight = _objHeight + _objHeightAdj;

_objHeight