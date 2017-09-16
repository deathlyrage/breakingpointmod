
BP_DetectedMagazines = [];

if !(BP_FastBoot) then
{
	[BP_DetectedMagazines,["CHILD:900:%1:",2],"CustomStreamStart"] call BPServer_fnc_callExtensionArray;
};

publicVariable "BP_DetectedMagazines";