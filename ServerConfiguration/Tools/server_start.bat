@echo off
TITLE BreakingPoint Server Starter

:::::::::::::::::::::::::::::::
:::: General Settings
:::::::::::::::::::::::::::::::
:: The port you want the server to use (default: 2302).
set server_port=2302
:: The name of the folder your server configs are stored in.
set server_profile=ServerConfig
:: Main server configuration file
set server_config=%server_profile%\config.cfg
:: Server network configuration file
set server_basic=%server_profile%\basic.cfg

:::::::::::::::::::::::::::::::
:::: Mod Settings
:::::::::::::::::::::::::::::::
:: Separate each mod folder with a ;
:: Example: server_clientMods=@BreakingPoint;@SomeGreatMod;
:: Client side mod list
set server_clientMods=@BreakingPoint;
:: Server side mod list, separate each mod folder with a ;
set server_serverMods=@BreakingPointServer;

::You do not need to edit past this point!
::You do not need to edit past this point!
::You do not need to edit past this point!

:start_loop
CLS
echo. Launching BreakingPoint server now!
start /wait arma3server_x64.exe -port=%server_port% "-config=%server_config%" "-cfg=%server_basic%" "-profiles=%server_profile%" -name=%server_profile% "-mod=%server_clientMods%" "-servermod=%server_serverMods%" -noSound -autoInit

echo. Server closed, restarting in 10 seconds.
timeout /t 10
goto start_loop

exit
