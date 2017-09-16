# Breaking Point Mod

Breaking Point Mod is a total conversion mod for Arma 3. Source is provided for the community to improve the mod and host their own servers. Released under the [Arma Public Share Like Licence](https://www.bistudio.com/community/licenses/arma-public-license-share-alike) (APL-SA).

## Objectives & Goals

* Provide a better version of the mod for people still playing. While the developers focus work on the standalone version.
* Compatibility with Arma  Updates / New Maps / DLC etc.
* Move Away from Breaking Point Launcher / The Zombie Infection Specific Code & Requirements. This removes a time / money cost and allows the official developers to spend all their time working on the standalone game.
* Intergrate Launcher Features (Legion System, Viewing Faction Points and Stats into the Main Game)
* Cross Platform Support ( Windows, Mac, Linux ) / This allows for hosting dedicated servers on Linux with a cheaper server cost.
* Release a Official Update with all these fixes. Submit a pull request with improvements and we will merge that into the game.

## Conflicts & Problems

* Fragmentation: Everyone using a custom version of Breaking Point and hosting vastly different servers and configurations. If we can work together and merge fixes into Breaking Point as a community.

## Server Configuration
## Prerequisites

* These steps assume you already know how to setup/install a MySQL database and basic ArmA server yourself, so do this first.
* Make sure you install the Visual C++ 2015 Redistributables from microsoft.
	* https://www.microsoft.com/en-gb/download/details.aspx?id=48145

## Configuration

* Download the BreakingPoint Client + Server files to your server (A batch file will be included in a tools folder for steam cmd users).
	##### If downloading using the steam client and uploading to your server.
	* Subscribe to the following mods on the workshop and copy each to your ArmA server directory.
	* Make sure the folders have the correct names on your server (@BreakingPoint and @BreakingPointServer).
	* BreakingPoint Client: http://steamcommunity.com/sharedfiles/filedetails/?id=426629791
	* BreakingPoint Server: http://steamcommunity.com/sharedfiles/filedetails/?id=1133182382
	
	##### If using the provided batch tool.
	* Copy the batch file to your server directory (or wherever you like), open it and make the following changes.
	* Make sure you set the correct username and password for steam (The workshop disallows downloads if you're not using a account that owns ArmA 3).
	```
	set steam_username=MySteamUser
	set steam_password=MySteamPassword
	```
	* Make sure you set the correct path to your SteamCMD install.
	```
	set "steamcmd_dir=C:\Path\To\SteamCMD"
	```
	* Make sure you set the correct path to your ArmA server directory.
	```
	set "arma_serverdir=C:\Path\To\Server\"
	```
	* Save the file once all the above changes have been made, remember to keep the quotes around the file path settings or you will get errors
	* Double click the batch file and will do everything else for you (you may need to input a steam guard code as you would when using the steam client).

* Import the included breakingpoint.sql file from the SQL folder to a clean database and make sure you have a sql account that has full access to that database.
* Copy the ServerConfig folder to your ArmA server directory.
* Open the BreakingPointExt.ini in ServerConfig and change the database ip, name, username, password and port to the ones you setup earlier.
	```
	[DATABASE]
	ip = 127.0.0.1
	port = 3306
	database = breakingpointmod
	username = root
	password = 
	```
* Copy the included server_start.bat file from the Tools folder to your server directory and edit as necessary (The defaults provided will work for a 32Bit server running on port 2302).
* Double click the batch file and wait for the server to start, if everything went successfully you should see the server start and a console displayed saying the following.
	```
	Starting Connection To Databases...
	Database Connection Success (Game DB)
	```

## Credits/Notable mentions.
* DeathlyRage - For tirelessly working hard over the years to maintain and develop such a high quality mod.
* KamikazeXeX - Writing the server configuration guide and providing the tools for server owners to use.
* The BP Community - For standing by BreakingPoint over the years helping to keep the mod alive.

