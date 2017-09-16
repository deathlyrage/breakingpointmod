
BP_DetectedWeapons = [];

if !(BP_FastBoot) then
{
	[BP_DetectedWeapons,["CHILD:900:%1:",1],"CustomStreamStart"] call BPServer_fnc_callExtensionArray;
};

publicVariable "BP_DetectedWeapons";
