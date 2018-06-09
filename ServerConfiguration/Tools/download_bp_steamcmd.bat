@echo off
TITLE BreakingPoint Steam CMD Downloader

:: Set your steam username and password.
set steam_username=
set steam_password=

:: Set the path to your steam cmd installation
set "steamcmd_dir=C:\Path\To\SteamCMD"
:: Set your ArmA server directory.
set "arma_serverdir=C:\Path\To\Server\"

:: Do no edit past this point!
:: Do no edit past this point!
:: Do no edit past this point!
:: Do no edit past this point!
if exist "%arma_serverdir%\@BreakingPoint" (
	rmdir /s /q "%arma_serverdir%\@BreakingPoint"
)

::Downloading Breaking Point
echo. Downloading BreakingPoint from the Steam Workshop
%steamcmd_dir%\steamcmd.exe +@ShutdownOnFailedCommand 1 +@NoPromptForsteam_password 1 +login %steam_username% %steam_password% +workshop_download_item 107410 426629791 +quit
xcopy /i /s /y "%steamcmd_dir%\steamapps\workshop\content\107410\426629791" %arma_serverdir%\@BreakingPoint

::Downloading Breaking Point Server
echo. Downloading BreakingPointServer from the Steam Workshop
%steamcmd_dir%\steamcmd.exe +@ShutdownOnFailedCommand 1 +@NoPromptForsteam_password 1 +login %steam_username% %steam_password% +workshop_download_item 107410 1133182382 +quit
xcopy /i /s /y "%steamcmd_dir%\steamapps\workshop\content\107410\1133182382" %arma_serverdir%\@BreakingPointServer

echo ----------------------------------------
echo Download Complete
echo ----------------------------------------
timeout /t 2
exit