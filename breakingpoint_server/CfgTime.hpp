/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgTime
{	
	class Base
	{
		date[] = {8,12,2035};
	};

	class Altis : Base
	{
		first[] = {7,00};
		second[] = {14,30};
	};
	
	class Stratis : Base
	{
		first[] = {7,00};
		second[] = {14,30};
	};
	
	class newhaven : Base
	{
		first[] = {7,00};
		second[] = {13,30};
	};

	class Esseker : Base
	{
		first[] = {7,00};
		second[] = {15,00};
	};
	
	class Thirsk : Base
	{
		first[] = {9,45};
		second[] = {11,30};
	};
	
	class ThirskW : Thirsk {};
	
	class Chernarus : Base
	{
		first[] = {7,30};
		second[] = {14,00};
	};
	
	class namalsk : Base
	{
		first[] = {7,0};
		second[] = {15,0};
	};
	
	class Tanoa : Base
	{
		first[] = {5,30};
		second[] = {16,30};
	};
};