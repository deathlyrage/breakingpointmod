/*
Navicat MySQL Data Transfer

Source Server         : s1.theforsakensurvivors.co.uk
Source Server Version : 50716
Source Host           : s1.theforsakensurvivors.co.uk:3306
Source Database       : a3bp_cherno

Target Server Type    : MYSQL
Target Server Version : 50716
File Encoding         : 65001

Date: 2017-09-16 02:06:59
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for buildings
-- ----------------------------
DROP TABLE IF EXISTS `buildings`;
CREATE TABLE `buildings` (
  `id` int(8) NOT NULL AUTO_INCREMENT,
  `player_id` varchar(40) NOT NULL,
  `unique_id` varchar(60) NOT NULL,
  `building_id` varchar(30) NOT NULL,
  `building_name` varchar(40) NOT NULL DEFAULT 'Unknown',
  `worldspace` varchar(60) NOT NULL DEFAULT '[]',
  `lock` varchar(4) NOT NULL DEFAULT '0000',
  `explosive` tinyint(1) NOT NULL DEFAULT '0',
  `reinforcement` int(1) NOT NULL DEFAULT '0',
  `instance_id` bigint(20) NOT NULL DEFAULT '1',
  `lastupdated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_index` (`building_id`,`instance_id`),
  KEY `worldspace` (`worldspace`),
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of buildings
-- ----------------------------

-- ----------------------------
-- Table structure for clans
-- ----------------------------
DROP TABLE IF EXISTS `clans`;
CREATE TABLE `clans` (
  `id` mediumint(8) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `tag` varchar(8) NOT NULL,
  `description` varchar(512) NOT NULL,
  `owner_id` mediumint(8) NOT NULL DEFAULT '-1',
  `website` varchar(128) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of clans
-- ----------------------------

-- ----------------------------
-- Table structure for clans_invites
-- ----------------------------
DROP TABLE IF EXISTS `clans_invites`;
CREATE TABLE `clans_invites` (
  `id` mediumint(8) NOT NULL AUTO_INCREMENT,
  `legion_id` mediumint(8) NOT NULL,
  `source_id` mediumint(8) NOT NULL,
  `target_id` mediumint(8) NOT NULL,
  `invite_hash` varchar(128) NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of clans_invites
-- ----------------------------

-- ----------------------------
-- Table structure for combat_log
-- ----------------------------
DROP TABLE IF EXISTS `combat_log`;
CREATE TABLE `combat_log` (
  `id` int(8) NOT NULL AUTO_INCREMENT,
  `player_id` varchar(40) NOT NULL,
  `player_name` varchar(40) NOT NULL DEFAULT 'Unknown',
  `character_id` varchar(40) NOT NULL DEFAULT '0',
  `instance` tinyint(5) NOT NULL DEFAULT '0',
  `lastupdated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of combat_log
-- ----------------------------

-- ----------------------------
-- Table structure for deployable
-- ----------------------------
DROP TABLE IF EXISTS `deployable`;
CREATE TABLE `deployable` (
  `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `class_name` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `uq1_deployable` (`class_name`)
) ENGINE=InnoDB AUTO_INCREMENT=42 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of deployable
-- ----------------------------
INSERT INTO `deployable` VALUES ('41', 'BP_BarrelFuel');
INSERT INTO `deployable` VALUES ('39', 'BP_BarrelWater');
INSERT INTO `deployable` VALUES ('11', 'BP_Cache1');
INSERT INTO `deployable` VALUES ('13', 'BP_Cache1_Hunter');
INSERT INTO `deployable` VALUES ('15', 'BP_Cache1_Nomad');
INSERT INTO `deployable` VALUES ('12', 'BP_Cache1_Outlaw');
INSERT INTO `deployable` VALUES ('14', 'BP_Cache1_Ranger');
INSERT INTO `deployable` VALUES ('16', 'BP_Cache1_Survivalist');
INSERT INTO `deployable` VALUES ('5', 'BP_CamoNet');
INSERT INTO `deployable` VALUES ('17', 'BP_Chest');
INSERT INTO `deployable` VALUES ('21', 'BP_Chest_Hunter');
INSERT INTO `deployable` VALUES ('20', 'BP_Chest_Nomad');
INSERT INTO `deployable` VALUES ('19', 'BP_Chest_Outlaw');
INSERT INTO `deployable` VALUES ('18', 'BP_Chest_Ranger');
INSERT INTO `deployable` VALUES ('22', 'BP_Chest_Survivalist');
INSERT INTO `deployable` VALUES ('1', 'BP_Crate1');
INSERT INTO `deployable` VALUES ('7', 'BP_Crate1_Hunter');
INSERT INTO `deployable` VALUES ('9', 'BP_Crate1_Nomad');
INSERT INTO `deployable` VALUES ('6', 'BP_Crate1_Outlaw');
INSERT INTO `deployable` VALUES ('8', 'BP_Crate1_Ranger');
INSERT INTO `deployable` VALUES ('10', 'BP_Crate1_Survivalist');
INSERT INTO `deployable` VALUES ('29', 'BP_GunCabinet');
INSERT INTO `deployable` VALUES ('33', 'BP_GunCabinet_Hunter');
INSERT INTO `deployable` VALUES ('32', 'BP_GunCabinet_Nomad');
INSERT INTO `deployable` VALUES ('31', 'BP_GunCabinet_Outlaw');
INSERT INTO `deployable` VALUES ('30', 'BP_GunCabinet_Ranger');
INSERT INTO `deployable` VALUES ('34', 'BP_GunCabinet_Survivalist');
INSERT INTO `deployable` VALUES ('23', 'BP_Refrigerator');
INSERT INTO `deployable` VALUES ('27', 'BP_Refrigerator_Hunter');
INSERT INTO `deployable` VALUES ('26', 'BP_Refrigerator_Nomad');
INSERT INTO `deployable` VALUES ('25', 'BP_Refrigerator_Outlaw');
INSERT INTO `deployable` VALUES ('24', 'BP_Refrigerator_Ranger');
INSERT INTO `deployable` VALUES ('28', 'BP_Refrigerator_Survivalist');
INSERT INTO `deployable` VALUES ('3', 'BP_RockStash');
INSERT INTO `deployable` VALUES ('2', 'BP_Safe');
INSERT INTO `deployable` VALUES ('37', 'BP_Stove');
INSERT INTO `deployable` VALUES ('35', 'BP_Television');
INSERT INTO `deployable` VALUES ('4', 'BP_Tent');

-- ----------------------------
-- Table structure for instance
-- ----------------------------
DROP TABLE IF EXISTS `instance`;
CREATE TABLE `instance` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `world_id` smallint(5) unsigned NOT NULL DEFAULT '1',
  `inventory` varchar(2048) NOT NULL DEFAULT '[]',
  `backpack` varchar(2048) NOT NULL DEFAULT '[]',
  PRIMARY KEY (`id`),
  KEY `fk1_instance` (`world_id`),
  CONSTRAINT `instance_ibfk_1` FOREIGN KEY (`world_id`) REFERENCES `world` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=100 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of instance
-- ----------------------------
INSERT INTO `instance` VALUES ('1', '1', '[]', '[]');
INSERT INTO `instance` VALUES ('2', '1', '[]', '[]');
INSERT INTO `instance` VALUES ('3', '12', '[]', '[]');
INSERT INTO `instance` VALUES ('4', '1', '[]', '[]');
INSERT INTO `instance` VALUES ('5', '2', '[]', '[]');
INSERT INTO `instance` VALUES ('6', '3', '[]', '[]');
INSERT INTO `instance` VALUES ('7', '6', '[]', '[]');
INSERT INTO `instance` VALUES ('8', '5', '[]', '[]');
INSERT INTO `instance` VALUES ('9', '12', '[]', '[]');
INSERT INTO `instance` VALUES ('10', '12', '[]', '[]');
INSERT INTO `instance` VALUES ('11', '12', '[]', '[]');
INSERT INTO `instance` VALUES ('12', '12', '[]', '[]');
INSERT INTO `instance` VALUES ('13', '12', '[]', '[]');
INSERT INTO `instance` VALUES ('14', '3', '[]', '[]');
INSERT INTO `instance` VALUES ('15', '5', '[]', '[]');
INSERT INTO `instance` VALUES ('16', '1', '[]', '[]');
INSERT INTO `instance` VALUES ('17', '3', '[]', '[]');
INSERT INTO `instance` VALUES ('18', '3', '[]', '[]');
INSERT INTO `instance` VALUES ('19', '6', '[]', '[]');
INSERT INTO `instance` VALUES ('20', '5', '[]', '[]');
INSERT INTO `instance` VALUES ('21', '2', '[]', '[]');
INSERT INTO `instance` VALUES ('22', '5', '[]', '[]');
INSERT INTO `instance` VALUES ('23', '1', '[]', '[]');
INSERT INTO `instance` VALUES ('24', '1', '[]', '[]');
INSERT INTO `instance` VALUES ('25', '6', '[]', '[]');
INSERT INTO `instance` VALUES ('26', '9', '[]', '[]');
INSERT INTO `instance` VALUES ('27', '9', '[]', '[]');
INSERT INTO `instance` VALUES ('28', '8', '[]', '[]');
INSERT INTO `instance` VALUES ('29', '6', '[]', '[]');
INSERT INTO `instance` VALUES ('30', '5', '[]', '[]');
INSERT INTO `instance` VALUES ('31', '2', '[]', '[]');
INSERT INTO `instance` VALUES ('32', '4', '[]', '[]');
INSERT INTO `instance` VALUES ('33', '6', '[]', '[]');
INSERT INTO `instance` VALUES ('34', '6', '[]', '[]');
INSERT INTO `instance` VALUES ('35', '6', '[]', '[]');
INSERT INTO `instance` VALUES ('36', '6', '[]', '[]');
INSERT INTO `instance` VALUES ('37', '8', '[]', '[]');
INSERT INTO `instance` VALUES ('38', '8', '[]', '[]');
INSERT INTO `instance` VALUES ('39', '9', '[]', '[]');
INSERT INTO `instance` VALUES ('40', '9', '[]', '[]');
INSERT INTO `instance` VALUES ('41', '8', '[]', '[]');
INSERT INTO `instance` VALUES ('42', '8', '[]', '[]');
INSERT INTO `instance` VALUES ('43', '8', '[]', '[]');
INSERT INTO `instance` VALUES ('44', '8', '[]', '[]');
INSERT INTO `instance` VALUES ('99', '12', '[]', '[]');

-- ----------------------------
-- Table structure for instance_deployable
-- ----------------------------
DROP TABLE IF EXISTS `instance_deployable`;
CREATE TABLE `instance_deployable` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `unique_id` varchar(60) NOT NULL,
  `deployable_id` smallint(5) unsigned NOT NULL,
  `owner_id` int(10) unsigned NOT NULL,
  `player_id` varchar(128) NOT NULL,
  `instance_id` bigint(20) unsigned NOT NULL DEFAULT '1',
  `worldspace` varchar(60) NOT NULL DEFAULT '[0,[0,0,0]]',
  `inventory` varchar(2048) NOT NULL DEFAULT '[]',
  `last_updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `created` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Hitpoints` varchar(500) NOT NULL DEFAULT '[]',
  `Fuel` double NOT NULL DEFAULT '0',
  `Damage` double NOT NULL DEFAULT '0',
  `lock` varchar(4) NOT NULL,
  `building_id` mediumint(8) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `idx1_instance_deployable` (`deployable_id`),
  KEY `idx2_instance_deployable` (`owner_id`),
  KEY `idx3_instance_deployable` (`instance_id`),
  CONSTRAINT `instance_deployable_ibfk_1` FOREIGN KEY (`instance_id`) REFERENCES `instance` (`id`),
  CONSTRAINT `instance_deployable_ibfk_3` FOREIGN KEY (`deployable_id`) REFERENCES `deployable` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of instance_deployable
-- ----------------------------

-- ----------------------------
-- Table structure for instance_traps
-- ----------------------------
DROP TABLE IF EXISTS `instance_traps`;
CREATE TABLE `instance_traps` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `unique_id` varchar(60) NOT NULL,
  `classname` varchar(100) NOT NULL,
  `worldspace` varchar(60) NOT NULL,
  `instance_id` bigint(20) NOT NULL,
  `created` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of instance_traps
-- ----------------------------

-- ----------------------------
-- Table structure for instance_vehicle
-- ----------------------------
DROP TABLE IF EXISTS `instance_vehicle`;
CREATE TABLE `instance_vehicle` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `instance_id` bigint(20) unsigned NOT NULL DEFAULT '1',
  `unique_id` varchar(60) NOT NULL,
  `classname` varchar(60) NOT NULL,
  `worldspace` varchar(60) NOT NULL DEFAULT '[0,[0,0,0]]',
  `inventory` varchar(2048) NOT NULL DEFAULT '[]',
  `parts` varchar(1024) NOT NULL DEFAULT '[]',
  `fuel` double NOT NULL DEFAULT '0',
  `damage` double NOT NULL DEFAULT '0',
  `last_updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `created` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`id`),
  KEY `idx3_instance_vehicle` (`instance_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of instance_vehicle
-- ----------------------------

-- ----------------------------
-- Table structure for kill_log
-- ----------------------------
DROP TABLE IF EXISTS `kill_log`;
CREATE TABLE `kill_log` (
  `id` int(8) NOT NULL AUTO_INCREMENT,
  `player_id` varchar(40) NOT NULL,
  `player_name` varchar(40) NOT NULL DEFAULT 'Unknown',
  `killer_id` varchar(40) NOT NULL,
  `killer_name` varchar(40) NOT NULL DEFAULT 'Unknown',
  `distance` mediumint(5) NOT NULL DEFAULT '0',
  `weapon` varchar(40) NOT NULL DEFAULT 'Unknown',
  `instance` tinyint(5) NOT NULL DEFAULT '0',
  `lastupdated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of kill_log
-- ----------------------------

-- ----------------------------
-- Table structure for profile
-- ----------------------------
DROP TABLE IF EXISTS `profile`;
CREATE TABLE `profile` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `unique_id` varchar(128) NOT NULL,
  `name` varchar(64) NOT NULL DEFAULT '',
  `guid` varchar(32) NOT NULL DEFAULT '',
  `vac` tinyint(1) NOT NULL DEFAULT '0',
  `vac_updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `market` varchar(1024) NOT NULL DEFAULT '[]',
  `clan` int(4) NOT NULL DEFAULT '0',
  `ranger` int(6) NOT NULL DEFAULT '0',
  `outlaw` int(6) NOT NULL DEFAULT '0',
  `hunter` int(6) NOT NULL DEFAULT '0',
  `nomad` int(6) NOT NULL DEFAULT '0',
  `survivalist` int(6) NOT NULL DEFAULT '0',
  `engineer` int(6) NOT NULL DEFAULT '0',
  `undead` int(6) NOT NULL DEFAULT '0',
  `survival_attempts` int(3) unsigned NOT NULL DEFAULT '1',
  `total_survival_time` int(5) unsigned NOT NULL DEFAULT '0',
  `total_survivor_kills` int(4) unsigned NOT NULL DEFAULT '0',
  `total_zombie_kills` int(5) unsigned NOT NULL DEFAULT '0',
  `total_headshots` int(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `uq_profile` (`unique_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of profile
-- ----------------------------

-- ----------------------------
-- Table structure for storage_log
-- ----------------------------
DROP TABLE IF EXISTS `storage_log`;
CREATE TABLE `storage_log` (
  `id` int(8) NOT NULL AUTO_INCREMENT,
  `player_id` varchar(40) NOT NULL,
  `player_name` varchar(40) NOT NULL DEFAULT 'Unknown',
  `deployable_id` varchar(60) NOT NULL,
  `deployable_name` varchar(40) NOT NULL DEFAULT 'Unknown',
  `owner_id` varchar(40) NOT NULL,
  `instance` tinyint(5) NOT NULL DEFAULT '0',
  `lastupdated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of storage_log
-- ----------------------------

-- ----------------------------
-- Table structure for survivor
-- ----------------------------
DROP TABLE IF EXISTS `survivor`;
CREATE TABLE `survivor` (
  `id` int(8) unsigned NOT NULL AUTO_INCREMENT,
  `unique_id` varchar(128) NOT NULL,
  `world_id` smallint(5) unsigned NOT NULL DEFAULT '1',
  `worldspace` varchar(60) NOT NULL DEFAULT '[]',
  `inventory` varchar(4096) NOT NULL DEFAULT '[]',
  `backpack` varchar(2048) NOT NULL DEFAULT '[]',
  `medical` varchar(255) NOT NULL DEFAULT '[false,false,false,false,false,false,false,0,12000,[],[0,0],0]',
  `is_dead` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `state` varchar(128) NOT NULL DEFAULT '["","aidlpercmstpsnonwnondnon_player_idlesteady04",36]',
  `survivor_kills` int(3) unsigned NOT NULL DEFAULT '0',
  `zombie_kills` int(4) unsigned NOT NULL DEFAULT '0',
  `headshots` int(4) unsigned NOT NULL DEFAULT '0',
  `survival_time` int(3) unsigned NOT NULL DEFAULT '0',
  `last_updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `start_time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `class` int(6) NOT NULL DEFAULT '-1',
  `dog` varchar(255) NOT NULL DEFAULT '[]',
  `lastserver` int(50) NOT NULL DEFAULT '0',
  `activeserver` int(50) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `idx1_main` (`unique_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of survivor
-- ----------------------------

-- ----------------------------
-- Table structure for vehicle
-- ----------------------------
DROP TABLE IF EXISTS `vehicle`;
CREATE TABLE `vehicle` (
  `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `class_name` varchar(100) DEFAULT NULL,
  `damage_min` decimal(4,3) NOT NULL DEFAULT '0.100',
  `damage_max` decimal(4,3) NOT NULL DEFAULT '0.700',
  `fuel_min` decimal(4,3) NOT NULL DEFAULT '0.200',
  `fuel_max` decimal(4,3) NOT NULL DEFAULT '0.800',
  `limit_min` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `limit_max` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `parts` varchar(1024) DEFAULT NULL,
  `inventory` varchar(2048) NOT NULL DEFAULT '[]',
  PRIMARY KEY (`id`),
  UNIQUE KEY `uq1_vehicle` (`class_name`),
  KEY `idx1_vehicle` (`class_name`)
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=utf8 COMMENT='a';

-- ----------------------------
-- Records of vehicle
-- ----------------------------
INSERT INTO `vehicle` VALUES ('1', 'BP_MRAP_01', '0.300', '0.500', '0.000', '0.000', '1', '2', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1],[\"HitGlass5\",1],[\"HitGlass6\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('2', 'BP_MRAP_03_F', '0.300', '0.500', '0.000', '0.000', '1', '2', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1],[\"HitGlass5\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('3', 'BP_Offroad_03_armed_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",1],[\"HitGlass1\",1],[\"HitGlass2\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('4', 'BP_Quadbike_01', '0.300', '0.500', '0.000', '0.000', '5', '8', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",0.5],[\"HitRFWheel\",0.5],[\"HitRF2Wheel\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('5', 'BP_Old_Bicycle', '1.000', '1.000', '0.000', '0.000', '5', '8', '[]', '[]');
INSERT INTO `vehicle` VALUES ('6', 'BP_Offroad_01_armed_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",0.5],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",0.5],[\"HitGlass1\",1],[\"HitGlass2\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('7', 'BP_Offroad_02_armed_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",0.5],[\"HitRFWheel\",0.5],[\"HitRF2Wheel\",1],[\"HitGlass1\",1],[\"HitGlass2\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('8', 'BP_SUV_01_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",0.5],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",0.5],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1],[\"HitGlass5\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('9', 'BP_SUV_02_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",0.5],[\"HitRFWheel\",0.5],[\"HitRF2Wheel\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1],[\"HitGlass5\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('10', 'BP_Hatchback_01_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",0.5],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",0.5],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('11', 'BP_Hatchback_02_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",0.5],[\"HitRFWheel\",0.5],[\"HitRF2Wheel\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('12', 'BP_Hatchback_01_sport_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",0.5],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",0.5],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('13', 'BP_Hatchback_02_sport_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",0.5],[\"HitRFWheel\",0.5],[\"HitRF2Wheel\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('14', 'BP_Heli_Light_01', '0.200', '0.400', '0.000', '0.000', '1', '1', '[[\"HitHRotor\",1],[\"HitVRotor\",1],[\"HitHull\",1],[\"HitAvionics\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('15', 'BP_Heli_Light_02_unarmed', '0.200', '0.400', '0.000', '0.000', '1', '1', '[[\"HitHRotor\",1],[\"HitVRotor\",1],[\"HitHull\",1],[\"HitAvionics\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1],[\"HitGlass5\",1],[\"HitGlass6\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('16', 'BP_Heli_Transport_02', '0.200', '0.400', '0.000', '0.000', '1', '1', '[[\"HitHRotor\",1],[\"HitVRotor\",1],[\"HitHull\",1],[\"HitAvionics\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1],[\"HitGlass5\",1],[\"HitGlass6\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('17', 'BP_Heli_Transport_01', '0.200', '0.400', '0.000', '0.000', '1', '1', '[[\"HitHRotor\",1],[\"HitVRotor\",1],[\"HitHull\",1],[\"HitAvionics\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1],[\"HitGlass5\",1],[\"HitGlass6\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('18', 'BP_Boat_Civil_01_police_F', '0.300', '0.500', '0.000', '0.000', '2', '4', '[[\"HitHull\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('19', 'BP_Boat_Transport_01_F', '0.300', '0.500', '0.000', '0.000', '3', '6', '[[\"HitBody\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('20', 'BP_Truck_02_covered_F', '0.300', '0.500', '0.000', '0.000', '2', '3', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",1],[\"HitLMWheel\",1],[\"HitRMWheel\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('21', 'BP_Truck_02_transport_F', '0.300', '0.500', '0.000', '0.000', '2', '3', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",1],[\"HitLMWheel\",1],[\"HitRMWheel\",1],[\"HitGlass1\",1],[\"HitGlass2\",1],[\"HitGlass3\",1],[\"HitGlass4\",1]]', '[]');
INSERT INTO `vehicle` VALUES ('22', 'BP_Van_01_Fuel_F', '0.300', '0.500', '0.000', '0.000', '3', '5', '[[\"HitLFWheel\",1],[\"HitLF2Wheel\",1],[\"HitRFWheel\",1],[\"HitRF2Wheel\",1],[\"HitGlass1\",1]]', '[]');

-- ----------------------------
-- Table structure for v_player
-- ----------------------------
DROP TABLE IF EXISTS `v_player`;
CREATE TABLE `v_player` (
  `player_name` varchar(64) DEFAULT NULL,
  `humanity` int(6) DEFAULT NULL,
  `alive_survivor_id` int(8) unsigned DEFAULT NULL,
  `alive_survivor_world_id` smallint(5) unsigned DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of v_player
-- ----------------------------

-- ----------------------------
-- Table structure for v_vehicle
-- ----------------------------
DROP TABLE IF EXISTS `v_vehicle`;
CREATE TABLE `v_vehicle` (
  `instance_vehicle_id` bigint(20) unsigned DEFAULT NULL,
  `vehicle_id` smallint(5) unsigned DEFAULT NULL,
  `instance_id` bigint(20) unsigned DEFAULT NULL,
  `world_id` smallint(5) unsigned DEFAULT NULL,
  `class_name` varchar(100) DEFAULT NULL,
  `worldspace` varchar(60) DEFAULT NULL,
  `inventory` varchar(2048) DEFAULT NULL,
  `parts` varchar(1024) DEFAULT NULL,
  `damage` double DEFAULT NULL,
  `fuel` double DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of v_vehicle
-- ----------------------------

-- ----------------------------
-- Table structure for world
-- ----------------------------
DROP TABLE IF EXISTS `world`;
CREATE TABLE `world` (
  `id` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL DEFAULT '0',
  `max_x` mediumint(9) DEFAULT '0',
  `max_y` mediumint(9) DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `uq_world` (`name`),
  KEY `idx1_world` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of world
-- ----------------------------
INSERT INTO `world` VALUES ('1', 'altis', '50000', '50000');
INSERT INTO `world` VALUES ('2', 'stratis', '50000', '50000');
INSERT INTO `world` VALUES ('3', 'thirsk', '50000', '50000');
INSERT INTO `world` VALUES ('4', 'bornholm', '50000', '50000');
INSERT INTO `world` VALUES ('5', 'newhaven', '50000', '50000');
INSERT INTO `world` VALUES ('6', 'esseker', '12700', '12700');
INSERT INTO `world` VALUES ('8', 'chernarus', '14700', '15360');
INSERT INTO `world` VALUES ('9', 'namalsk', '50000', '50000');
INSERT INTO `world` VALUES ('11', 'legion', '50000', '50000');
INSERT INTO `world` VALUES ('12', 'tanoa', '50000', '50000');

-- ----------------------------
-- Table structure for world_vehicle
-- ----------------------------
DROP TABLE IF EXISTS `world_vehicle`;
CREATE TABLE `world_vehicle` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `vehicle_id` smallint(5) unsigned NOT NULL DEFAULT '1',
  `world_id` smallint(5) unsigned NOT NULL DEFAULT '1',
  `worldspace` varchar(60) NOT NULL DEFAULT '[]',
  `description` varchar(1024) DEFAULT NULL,
  `chance` decimal(4,3) unsigned NOT NULL DEFAULT '0.000',
  `last_modified` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `idx1_world_vehicle` (`vehicle_id`),
  KEY `idx2_world_vehicle` (`world_id`),
  CONSTRAINT `world_vehicle_ibfk_1` FOREIGN KEY (`vehicle_id`) REFERENCES `vehicle` (`id`),
  CONSTRAINT `world_vehicle_ibfk_2` FOREIGN KEY (`world_id`) REFERENCES `world` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=936 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of world_vehicle
-- ----------------------------
INSERT INTO `world_vehicle` VALUES ('1', '1', '1', '[271.158,[6261.87,16864.8,0.00130463]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('2', '2', '1', '[106.374,[14092.5,11559.9,-0.107578]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('3', '3', '1', '[358.214,[3173.26,21712,0.0797215]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('4', '4', '1', '[89.5481,[17682.6,17402,0.232323]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('5', '4', '1', '[232.269,[21531.7,18355.9,0.0890255]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('6', '4', '1', '[11.5578,[17177.2,10537.6,-0.146423]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('7', '4', '1', '[127.614,[26863.3,23829.5,0.534178]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('8', '4', '1', '[49.2644,[20652.5,6930.36,0.0564957]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('9', '5', '1', '[67.3805,[7939.56,16360.1,0.0822296]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('10', '5', '1', '[129.297,[4585.16,21352.8,0.0331421]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('11', '5', '1', '[317.236,[4741.35,17170.2,0.0201111]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('12', '5', '1', '[93.5403,[7069.97,11511.1,0.222422]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('13', '5', '1', '[93.4648,[11759,15723.7,0.206139]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('14', '6', '1', '[222.335,[14574.4,16724,0.00485802]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('15', '6', '1', '[161.003,[20267.2,8776.32,0.00915146]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('16', '6', '1', '[88.8702,[9343.9,20260.8,0.457115]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('17', '7', '1', '[44.8014,[14569.9,16887.9,0.00656509]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('18', '7', '1', '[264.191,[5085.03,10822.4,0.637257]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('19', '7', '1', '[320.351,[26829.7,23179.5,0.182907]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('20', '8', '1', '[225.867,[14568,16871.3,-0.00587845]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('21', '8', '1', '[85.8429,[18824.7,16358.9,0.182066]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('22', '8', '1', '[179.802,[4852.24,16133.1,0.546837]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('23', '9', '1', '[45.2504,[14531,16844.3,-0.00599098]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('24', '9', '1', '[130.39,[10722,12298.4,0.136753]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('25', '9', '1', '[183.656,[10379.5,19087.9,0.467827]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('26', '10', '1', '[224.498,[14542.5,16840.8,0.0390072]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('27', '10', '1', '[156.57,[18090.2,15292.7,0.410803]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('28', '10', '1', '[130.659,[9578.26,16020.3,0.344124]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('29', '11', '1', '[224.182,[14469.3,16796.8,0.0420799]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('30', '11', '1', '[313.328,[20115.3,11787.2,0.249905]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('31', '11', '1', '[205.892,[25497.9,21363.9,0.148329]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('32', '12', '1', '[225.248,[14511.5,16814.9,0.0427132]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('33', '12', '1', '[242.824,[19509.5,13227,0.320545]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('34', '12', '1', '[42.065,[7211.9,16527.9,0.436142]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('35', '13', '1', '[314.27,[14542.9,16752.3,0.0420189]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('36', '13', '1', '[135.045,[13927.4,18923.8,0.365582]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('37', '13', '1', '[76.0341,[9509.59,11609.8,0.483319]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('38', '14', '1', '[359.997,[23079.5,7297.76,0.00638199]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('39', '14', '1', '[0.0101101,[17550.1,13239,0.00538826]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('40', '14', '1', '[0.0655504,[8422.79,18206.9,0.00238037]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('41', '14', '1', '[359.891,[12876.8,16739,0.0144577]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('42', '15', '1', '[0.185543,[12496.2,15195.5,0.0384979]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('43', '15', '1', '[0.262107,[14156.4,21254.5,0.000190735]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('44', '15', '1', '[1.43006,[23483.7,21144.6,0.00576782]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('45', '16', '1', '[0.778824,[20596.8,20073.2,-0.0453644]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('46', '16', '1', '[0.719071,[9907.22,19422.8,-0.047699]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('47', '16', '1', '[0.826322,[11578.6,11905.4,-0.0428886]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('48', '17', '1', '[359.971,[12833.3,16736.2,0.0766602]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('49', '17', '1', '[359.921,[20798.2,7226.04,0.0212593]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('50', '19', '1', '[286.95,[16812.6,15712.4,0.316313]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('51', '19', '1', '[65.6457,[16808.6,12209.4,0.0931941]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('52', '19', '1', '[194.972,[7201.34,11061.3,0.225093]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('53', '19', '1', '[39.1077,[9430.64,22214.6,1.0243]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('54', '19', '1', '[278.193,[23278.2,24205.7,-1.83846]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('55', '19', '1', '[283.316,[23303.9,24200.7,-1.64825]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('56', '20', '1', '[293.629,[18491.3,14252,-0.0442657]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('57', '21', '1', '[354.994,[5408.15,17888.8,0.00524139]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('58', '22', '1', '[347.86,[14119.7,16436.1,0.0346012]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('59', '1', '3', '[182.416,[2370.63,4699.73,-0.00923729]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('60', '2', '3', '[116.819,[3628.63,4700.15,-0.042696]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('61', '3', '3', '[184.132,[2545.86,3860.52,0.0779305]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('62', '4', '3', '[27.3278,[3467.68,3439.02,0.0628357]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('63', '5', '3', '[25.8181,[1688.18,1917.68,0.107521]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('64', '6', '3', '[302.256,[2703.63,2020.7,0.0313721]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('65', '7', '3', '[155.984,[1172.99,4014.88,0.0154877]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('66', '8', '3', '[183.389,[1498.2,2199.48,-0.00637817]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('67', '9', '3', '[275.038,[1444.92,1954.37,-0.00634384]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('68', '10', '3', '[286.278,[1216.64,1986.09,0.0418282]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('69', '11', '3', '[209.582,[1199.26,2176.53,0.0416183]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('70', '12', '3', '[28.8072,[1192.9,2144.92,0.0408936]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('71', '13', '3', '[14.072,[1592.33,2056.27,0.0409622]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('72', '14', '3', '[359.966,[1625.26,2944.5,0.00622177]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('73', '14', '3', '[359.957,[1642.05,2937.23,0.00621796]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('74', '14', '3', '[359.956,[631.279,2419.88,0.0062809]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('75', '14', '3', '[359.954,[631.275,2438.07,0.00627327]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('76', '14', '3', '[0.0322575,[4098.71,2522.42,0.00982094]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('77', '14', '3', '[0.0421454,[4080.67,2522.79,0.00914192]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('78', '14', '3', '[0.0487093,[3947.82,1387.62,0.00629425]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('79', '14', '3', '[0.0513747,[2145,1021.23,0.00680351]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('80', '14', '3', '[359.943,[2145.23,1039.54,0.00671196]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('81', '19', '3', '[95.9462,[3481.07,4620.28,3.47193]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('82', '20', '3', '[87.5979,[694.72,1724.44,-0.0746098]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('83', '21', '3', '[359.71,[1775.86,3632.17,-0.0170135]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('84', '22', '3', '[3.27745,[2686.77,2899.11,0.03339]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('85', '1', '2', '[59.4915,[5534.87,4722.08,0.0267334]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('86', '2', '2', '[288.633,[3766.03,7991.55,0.0131247]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('87', '3', '2', '[52.4365,[2818.06,3712.16,-0.111053]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('88', '4', '2', '[337.321,[2651.05,1269.84,0.101822]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('89', '5', '2', '[59.4452,[4801.19,4389.46,0.30574]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('90', '6', '2', '[189.552,[4505.45,6788.78,0.0286407]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('91', '7', '2', '[277.86,[6045.51,5599.84,0.00786972]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('92', '8', '2', '[81.759,[4986.61,5420.77,0.0184937]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('93', '9', '2', '[323.564,[4161.74,3313.19,0.0193634]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('94', '10', '2', '[319.411,[2056.06,2691.74,0.0906634]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('95', '11', '2', '[64.8688,[2771.56,5731.38,0.214904]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('96', '12', '2', '[127.782,[2025.97,2704.81,0.0440435]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('97', '13', '2', '[318.725,[3026.23,5932.68,0.189284]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('98', '19', '2', '[342.155,[7146.46,5975.24,0.473345]]', null, '0.000', null);
INSERT INTO `world_vehicle` VALUES ('99', '20', '2', '[216.621,[3237.25,5779.33,-0.0429859]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('100', '21', '2', '[282.516,[2109.79,5874.51,-0.0201616]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('101', '22', '2', '[12.972,[2071.38,5492.41,0.0312223]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('102', '14', '2', '[359.996,[2177.39,5757.65,0.00625277]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('103', '14', '2', '[359.972,[3352.37,2907.38,0.00971985]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('104', '14', '2', '[359.974,[5027.17,5903.25,0.0145416]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('123', '18', '1', '[229.909,[5062.81,9923.79,-1.88915]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('124', '18', '1', '[39.6026,[3607.99,10932.8,-1.91341]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('125', '18', '1', '[143.197,[3320.98,14085.7,-1.64877]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('126', '18', '1', '[278.193,[23278.2,24205.7,-1.83846]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('127', '18', '5', '[185.068,[5058.64,582.636,0.00162292]] ', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('128', '18', '5', '[308.738,[5343.63,5504.34,1.67327]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('129', '19', '5', '[102.416,[5307.28,3041.01,0.00190735]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('130', '19', '5', '[244.759,[1407.82,1076.19,3.27262]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('131', '19', '5', '[171.376,[1902.8,3880.02,0.00164878]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('132', '19', '5', '[278.236,[388.006,5443.97,0.13752]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('133', '19', '5', '[303.412,[8926.32,3949.56,0.00163686]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('134', '8', '5', '[261.065,[3297.68,8537.6,0.49313]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('135', '8', '5', '[178.582,[3206.26,8232.72,0.00143862]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('136', '9', '5', '[119.31,[6259.79,4187.85,0.0015049]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('137', '9', '5', '[13.3416,[3640.53,415.744,0.167599]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('138', '8', '5', '[122.1,[6327.09,4411.81,0.00144196]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('139', '8', '5', '[42.7485,[3548.77,2826.71,0.00147629]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('140', '9', '5', '[288.778,[6567.41,4358.1,0.433987]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('141', '13', '5', '[175.344,[4148.94,7176.94,0.00140953]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('142', '14', '5', '[2.92272,[5390.75,739.856,0.00151253]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('143', '15', '5', '[120.453,[5177.18,1461.62,0.00143814]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('144', '17', '5', '[145.201,[9437.4,4228.22,0.0014267]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('145', '17', '5', '[356.892,[9106.79,8599.37,0.0014267]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('146', '16', '5', '[120.418,[5191.36,1667.27,0.00143814]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('147', '1', '5', '[267.96,[5350.42,723.673,0.16704]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('148', '1', '5', '[88.6672,[9347.51,838.864,0.191212]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('149', '1', '5', '[93.9907,[4257.48,1376.27,0.00148582]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('150', '2', '5', '[317.015,[1143.97,7076.4,0.00115633]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('151', '2', '5', '[327.303,[7935.77,8650.87,0.00176907]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('152', '6', '5', '[176.924,[3206.89,8379.86,0.00145149]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('153', '6', '5', '[205.515,[6081.52,4222.69,0.946859]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('154', '7', '5', '[79.7982,[957.841,8037.2,0.00143433]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('155', '7', '5', '[181.943,[2023.45,5130.1,0.0821686]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('156', '4', '5', '[108.472,[2059.65,6861.56,0.00153542]]', null, '1.000', null);
INSERT INTO `world_vehicle` VALUES ('157', '4', '5', '[300.628,[2308.32,1739.33,0.00137329]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('158', '4', '5', '[183.915,[7617.71,6577.69,0.0014267]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('159', '5', '5', '[350.649,[1417.62,2374.15,0.671283]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('160', '5', '5', '[81.211,[6930.45,6326.79,0.00143814]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('161', '5', '5', '[280.578,[7862.97,5616.59,0.00143814]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('162', '8', '5', '[172.074,[3326.99,8586.41,0.0014267]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('163', '8', '5', '[267.781,[3826.78,5399.43,0.00138092]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('164', '8', '5', '[181.367,[4074.02,4958.24,0.00143814]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('165', '9', '5', '[267.96,[5350.42,723.673,0.16704]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('166', '9', '5', '[206.868,[6067.63,4220.76,0.789948]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('167', '20', '5', '[2.60677,[2846.15,412.347,0.00151443]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('168', '21', '5', '[358.048,[1793.4,685.362,0.402206]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('169', '21', '5', '[230.743,[5412.67,3609.75,0.00162315]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('170', '22', '5', '[312.44,[3565.22,2836.44,0.00149727]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('171', '8', '5', '[91.3419,[5310.44,1640.07,0.00143814]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('172', '9', '5', '[88.8672,[5310.33,1648.14,0.00143814]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('173', '9', '5', '[90.8049,[5310.12,1656.07,0.00143814]] ', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('174', '13', '5', '[86.6728,[5309.03,1582.13,0.00143623]] ', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('175', '16', '5', '[91.0349,[2031.87,5128.51,0.00143433]] ', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('176', '3', '5', '[197.632,[2074.08,6860.9,0.00150585]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('177', '20', '5', '[357.393,[2035.54,5064.62,0.0821686]]', null, '0.500', null);
INSERT INTO `world_vehicle` VALUES ('179', '2', '1', '[259.815,[2165.4,11585.6,0.00172997]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('180', '1', '1', '[314.087,[14315.6,19008.4,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('181', '1', '1', '[288.069,[10196.1,15905.4,0.00147247]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('182', '3', '1', '[181.644,[12760.7,16372.5,0.387627]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('183', '3', '1', '[207.382,[21391.9,16214.6,0.00120354]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('184', '3', '1', '[224.142,[3881.07,13754.4,0.295624]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('185', '3', '1', '[227.848,[3776.61,13491.1,0.00135422]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('186', '4', '1', '[45.0534,[25590.6,21369,0.00145149]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('187', '4', '1', '[290.703,[5148.35,14674.3,0.00143719]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('188', '4', '1', '[128.325,[3848.33,11897.2,0.00173187]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('189', '4', '1', '[2.0183,[9038.26,12334.2,0.00141716]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('190', '5', '1', '[347.166,[9049.18,15713.6,0.00146484]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('191', '5', '1', '[341.588,[4256.91,11588.2,0.0018425]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('192', '5', '1', '[57.3035,[8355.59,13297.1,0.00156403]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('193', '6', '1', '[269.948,[14634.5,20867.2,0.131809]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('194', '6', '1', '[266.592,[3695.43,12065.2,0.558218]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('195', '6', '1', '[308.579,[5719.34,15128.1,0.193171]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('196', '7', '1', '[317.181,[16950.3,12731.1,0.195984]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('197', '7', '1', '[312.372,[3490.61,13040.3,0.00147676]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('198', '7', '1', '[44.0819,[3646.07,11511.6,0.00144148]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('199', '8', '1', '[35.9871,[21758,7623.85,0.141047]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('200', '8', '1', '[6.9945,[4039.17,11831,0.0015831]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('201', '8', '1', '[307.81,[4061.11,11701.1,0.462395]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('202', '8', '1', '[38.4117,[8391.78,15938.5,0.00146484]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('203', '9', '1', '[280.484,[20808.2,6748.55,0.380417]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('204', '9', '1', '[155.054,[7294.04,13972.6,0.00195313]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('205', '9', '1', '[251.096,[3555.66,12526.1,0.323391]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('206', '9', '1', '[118.679,[4049.92,11768.1,0.0014267]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('207', '10', '1', '[320.836,[19947.5,11449.4,0.00138474]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('208', '10', '1', '[53.4402,[18705,16545.7,0.277466]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('209', '10', '1', '[301.579,[4076.93,11715.4,0.280273]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('210', '10', '1', '[109.936,[3741.79,11101.3,0.147733]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('211', '11', '1', '[334.314,[12522.5,14266.3,0.500421]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('212', '11', '1', '[88.9216,[10296.2,19146.3,0.00154114]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('213', '11', '1', '[101.902,[9198.41,12092.3,0.00147247]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('214', '11', '1', '[134.015,[3571.38,13041.7,0.696373]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('215', '12', '1', '[45.0534,[23199.9,19930,0.156793]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('216', '12', '1', '[259.179,[8480.99,18263.6,0.00146484]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('217', '12', '1', '[237.601,[5288.91,14576.5,0.192928]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('218', '13', '1', '[154.45,[12646.7,14343.4,0.144979]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('219', '13', '1', '[161.177,[9405.68,16019.2,0.164864]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('223', '14', '1', '[267.446,[20899.9,14626.7,0.0014534]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('224', '15', '1', '[123.755,[26784.2,24669.4,0.001194]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('225', '16', '1', '[267.967,[3732.4,12976.3,19.4923]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('226', '20', '1', '[318.575,[4530.88,21329.3,0.0010376]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('227', '20', '1', '[70.3183,[3070.03,12156.1,0.00127029]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('228', '20', '1', '[322.555,[8899.42,15549.6,0.00151062]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('229', '21', '1', '[44.0591,[5905.83,15397.9,0.00145531]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('230', '21', '1', '[90.1993,[6084.94,16273.6,0.00143814]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('231', '22', '1', '[60.5142,[20243,8801.85,0.00151825]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('232', '22', '1', '[229.05,[21114.5,16943.4,0.00136375]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('233', '22', '1', '[275.241,[5778.73,20067.2,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('234', '22', '1', '[357.307,[6276.74,16198.5,0.00143814]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('236', '1', '4', '[347.748,[3491.83,12587.7,0.00163269]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('238', '1', '4', '[267.56,[3402.14,14150,0.00138855]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('240', '1', '4', '[72.6025,[2107.44,8100.96,0.00143623]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('242', '1', '4', '[244.122,[6240.92,6271.83,0.00132751]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('244', '1', '4', '[72.6025,[2107.44,8100.96,0.00143623]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('246', '1', '4', '[225.208,[4161.37,12799.4,0.00151062]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('248', '1', '4', '[185.281,[7714.45,5552.45,0.0014267]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('250', '1', '4', '[259.625,[15518.8,5513.28,0.00138855]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('252', '2', '4', '[21.8591,[2512.38,16935.2,0.0014267]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('254', '2', '4', '[86.8018,[5185.53,6860.66,0.00165558]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('256', '2', '4', '[280.231,[7850.92,13650.9,0.00140381]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('258', '2', '4', '[161.841,[1984.59,9037.21,0.00144386]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('260', '2', '4', '[12.2878,[3261.94,10093.8,0.00157166]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('262', '2', '4', '[133.792,[9711.31,1961.7,0.00130653]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('264', '2', '4', '[162.198,[11064.9,11022.4,0.0014267]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('266', '3', '4', '[268.464,[12387.8,2684.98,0.00120544]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('268', '3', '4', '[286.132,[11805.1,1326.17,0.00152493]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('270', '3', '4', '[11.707,[11110.5,1419.19,0.0014677]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('272', '3', '4', '[8.97895,[14004.9,645.69,0.00150728]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('274', '3', '4', '[301.188,[14759.7,1440.74,0.00131702]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('276', '3', '4', '[350.353,[16864.5,2753.66,0.00154495]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('278', '3', '4', '[179.825,[13979.2,4486.32,0.0014801]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('280', '3', '4', '[350.378,[2627.04,13826.6,0.00141144]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('282', '3', '4', '[124.514,[5399.03,18596.7,0.00063324]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('284', '3', '4', '[57.9539,[12713.6,12832.9,0.00165939]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('286', '3', '4', '[76.7355,[13026.3,10137.3,0.170807]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('288', '3', '4', '[9.18015,[17953.1,9685.43,0.158554]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('290', '4', '4', '[271.137,[1902.72,10713.5,0.00144577]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('292', '4', '4', '[162.66,[2014.29,11128.1,0.00148296]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('294', '4', '4', '[169.831,[7711.87,10517,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('296', '4', '4', '[271.414,[18100.8,8730.23,0.00126672]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('298', '4', '4', '[88.0956,[17297.9,5235.36,0.584886]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('300', '4', '4', '[154.198,[14728.7,6624.71,0.001091]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('302', '4', '4', '[18.2153,[12216.5,5248,0.00132751]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('304', '4', '4', '[133.605,[4579.84,16070.2,0.00138855]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('306', '4', '4', '[255.396,[5381.82,7101.33,0.00151062]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('308', '4', '4', '[332.229,[11795.8,11520.8,0.00157928]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('310', '4', '4', '[85.579,[12083.8,4642.13,0.00148773]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('312', '4', '4', '[88.5613,[7981.17,5138.75,0.00128174]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('314', '4', '4', '[110.451,[3110,5549.94,0.00145626]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('316', '5', '4', '[64.7457,[3939.37,18397.1,0.00147247]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('318', '5', '4', '[144.916,[14877.5,6127.48,0.00154114]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('320', '5', '4', '[188.035,[13413.1,5419.92,0.00170135]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('322', '5', '4', '[197.947,[11385.4,7500.25,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('324', '5', '4', '[93.4779,[9833.11,7985.35,0.00132751]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('326', '5', '4', '[252.633,[7331.62,12774.8,0.00186157]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('328', '5', '4', '[181.61,[5296.19,13535.6,0.00167084]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('330', '5', '4', '[261.135,[3910.41,14452.9,0.00123596]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('332', '5', '4', '[74.8478,[6122.34,5695.4,0.00121689]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('334', '5', '4', '[77.6375,[3716.82,14338.7,0.00141144]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('336', '5', '4', '[144.438,[9955.13,4171.96,0.00157547]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('338', '5', '4', '[164.733,[12949.7,7002.55,0.00151825]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('340', '5', '4', '[165.522,[1391.33,7263.46,0.00135708]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('342', '6', '4', '[350.764,[1716.03,6915.95,0.00143242]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('344', '6', '4', '[182.507,[1297.67,8282.01,0.00145531]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('346', '6', '4', '[108.511,[5355.36,5713.55,0.154022]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('348', '6', '4', '[159.909,[3430.54,8272.75,0.437141]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('350', '6', '4', '[159.204,[1766.81,13191.4,0.00170708]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('352', '6', '4', '[201.215,[10234.2,4741.65,0.00144577]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('354', '6', '4', '[8.64311,[9587.14,9268.54,0.00125885]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('356', '6', '4', '[0.127415,[12018.1,1578.4,0.00129128]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('358', '6', '4', '[99.0282,[16433.9,1695.25,0.00147295]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('360', '6', '4', '[181.141,[1801.54,14531.6,0.00159073]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('362', '6', '4', '[94.9751,[4210.12,18892.8,0.00167084]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('364', '6', '4', '[34.6728,[7562.45,10464.1,0.453133]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('366', '6', '4', '[110.451,[3115.69,5572.76,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('368', '6', '4', '[165.479,[1395.32,7263.5,0.00112724]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('370', '7', '4', '[232.486,[2730.5,6243.16,0.00158691]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('372', '7', '4', '[19.579,[4129.94,5584.6,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('374', '7', '4', '[278.141,[3212.44,6739.73,0.00144577]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('376', '7', '4', '[98.2873,[3311.9,8378.36,0.416656]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('378', '7', '4', '[91.3302,[2790.8,11676.2,0.00127411]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('380', '7', '4', '[180.507,[8080.23,4793.47,0.00124741]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('382', '7', '4', '[103.062,[9704.7,5829.13,0.0014267]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('384', '7', '4', '[280.541,[12073,1018.36,0.00151253]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('386', '7', '4', '[169.221,[15649.3,2885.67,0.00139141]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('388', '7', '4', '[82.236,[16521.7,3341.03,0.00143909]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('390', '7', '4', '[227.319,[3641.57,17435.7,0.0012207]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('392', '7', '4', '[33.9067,[4374.86,19895.7,0.00249386]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('394', '7', '4', '[292.236,[17254.9,5127.12,0.520941]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('396', '8', '4', '[188.071,[1420.44,7552.87,0.739653]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('398', '8', '4', '[185.256,[4677.25,6541.69,0.180408]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('400', '8', '4', '[341.606,[3271.47,8262.04,0.392891]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('402', '8', '4', '[112.151,[5247.9,5891.13,0.730694]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('404', '8', '4', '[232.763,[6550.8,5802.07,0.419914]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('406', '8', '4', '[83.7853,[6283.71,5848.76,0.565815]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('408', '8', '4', '[87.1032,[1924.17,10871.7,0.001441]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('410', '8', '4', '[166.45,[1590.67,13065.5,0.107481]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('412', '8', '4', '[283.503,[6821.2,6016.31,0.177139]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('414', '8', '4', '[78.6866,[9441.8,5622.57,0.525284]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('416', '8', '4', '[59.1862,[16829.9,4117.77,0.00146294]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('418', '8', '4', '[237.503,[4722.56,19762,0.00137615]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('420', '8', '4', '[134.171,[17621.1,5119.06,0.140468]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('422', '8', '4', '[77.8696,[1389.88,7252.73,0.00133038]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('424', '9', '4', '[140.655,[1493.54,12772.2,0.166287]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('426', '9', '4', '[86.5087,[1389.78,13134.9,0.555908]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('428', '9', '4', '[336.289,[1941.74,12738.4,0.146091]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('430', '9', '4', '[175.681,[5261.02,12341.2,0.501297]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('432', '9', '4', '[229.953,[6667.04,5937.37,0.52697]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('434', '9', '4', '[101.263,[9161.35,5476.58,0.402252]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('436', '9', '4', '[10.2546,[9351.25,5691.45,0.00122833]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('438', '9', '4', '[167.858,[12420.3,3051.24,0.611568]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('440', '9', '4', '[1.95282,[12681.8,3978.69,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('442', '9', '4', '[252.351,[15497.8,852.819,0.00111675]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('444', '9', '4', '[264.489,[2541.72,15837.6,0.0014801]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('446', '9', '4', '[277.682,[12867.4,10187.3,0.138481]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('448', '9', '4', '[261.691,[17532.2,4790.4,0.14846]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('450', '9', '4', '[313.543,[16468.6,9529.03,0.00141525]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('452', '10', '4', '[175.402,[5401.19,12488.5,0.160469]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('454', '10', '4', '[155.355,[1658.11,7843.1,0.611458]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('456', '10', '4', '[159.589,[1569.02,7867.48,0.0012207]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('458', '10', '4', '[243.905,[1965.76,11834.7,0.00151634]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('460', '10', '4', '[12.35,[5124.12,12252,1.41295]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('462', '10', '4', '[265.469,[6349.62,5855.62,0.438496]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('464', '10', '4', '[133.28,[9318.2,6034.59,0.475731]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('466', '10', '4', '[177.18,[12459.4,2868.52,0.719662]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('468', '10', '4', '[15.8337,[7377.59,5873.58,0.00144577]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('470', '10', '4', '[319.203,[4804.04,18781.7,0.545956]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('472', '10', '4', '[96.0041,[4688.67,19386.9,0.00153542]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('474', '10', '4', '[358.795,[13208.9,10091.7,0.164474]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('476', '10', '4', '[169.818,[18128.3,9675.65,0.527472]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('478', '10', '4', '[190.947,[17102,5071.33,0.676323]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('480', '11', '4', '[175.402,[5401.19,12488.5,0.160469]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('482', '11', '4', '[270.821,[1260.11,7299.14,0.797578]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('484', '11', '4', '[264.848,[1741.73,7495.78,0.597439]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('486', '11', '4', '[160.003,[3372.27,8317.35,0.38353]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('488', '11', '4', '[163.037,[2111.38,11349.8,0.0014801]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('490', '11', '4', '[193.808,[6530.7,5897.65,0.124641]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('492', '11', '4', '[229.492,[14550.4,761.906,0.00142908]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('494', '11', '4', '[233.365,[12151.6,5566.88,0.00163269]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('496', '11', '4', '[146.967,[2741.59,17041.5,0.00150299]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('498', '11', '4', '[119.783,[4979.79,19114.6,0.00121117]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('500', '11', '4', '[266.635,[4939.29,16806.5,0.785645]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('502', '11', '4', '[1.04491,[11714.9,14728.1,0.00181913]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('504', '11', '4', '[89.3388,[13438.5,12300.6,0.00143051]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('506', '11', '4', '[180.206,[18130.9,8027.56,0.166811]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('508', '12', '4', '[165.377,[4445.99,19753,0.00130272]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('510', '12', '4', '[266.897,[4935.98,16859.9,0.73613]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('512', '12', '4', '[174.567,[4880.17,16738.5,0.540596]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('514', '12', '4', '[322.212,[6162.36,17196.7,0.00145912]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('516', '12', '4', '[14.4129,[11456.2,14478,0.00150681]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('518', '12', '4', '[340.351,[12913.7,10173.2,0.189926]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('520', '12', '4', '[132.013,[11346.3,15139.9,0.00117016]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('522', '12', '4', '[330.737,[14833.2,10013.7,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('524', '12', '4', '[83.5517,[17698.3,10211.7,0.511557]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('526', '12', '4', '[167.716,[15607.1,5114.38,0.00152588]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('528', '12', '4', '[111.231,[3127.42,5522.25,0.00143909]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('530', '12', '4', '[90.5668,[17928.2,8045.22,0.621769]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('532', '12', '4', '[153.03,[7753.16,10536,0.508446]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('534', '13', '4', '[91.181,[4891.9,17071,0.22007]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('536', '13', '4', '[247.648,[5648.68,14217.4,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('538', '13', '4', '[46.2585,[6098.52,17527.3,0.693107]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('540', '13', '4', '[225.698,[7287.61,16278.6,0.00136566]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('542', '13', '4', '[47.1962,[11722.9,14414.3,0.00167656]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('544', '13', '4', '[134.987,[11731.6,14185.5,0.00129128]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('546', '13', '4', '[320.225,[16260.1,8533.63,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('548', '13', '4', '[114.978,[17820.8,10044,0.425413]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('550', '13', '4', '[95.7992,[17138.6,5443.95,0.00156975]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('552', '13', '4', '[278.525,[14913.4,3868.68,0.00138474]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('554', '13', '4', '[284.371,[17980.3,7856.27,0.83477]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('556', '13', '4', '[164.139,[7654.97,10504,0.438545]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('558', '13', '4', '[25.2222,[7545.5,10499.9,0.593582]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('560', '13', '4', '[159.541,[18045.3,7908.35,0.425515]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('562', '14', '4', '[87.9076,[13851.4,10689.1,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('564', '14', '4', '[90.4195,[13836.9,10643.3,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('566', '14', '4', '[179.798,[9292.9,2577.58,0.00153732]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('568', '14', '4', '[87.9904,[1515.83,12891.1,0.00143814]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('570', '14', '4', '[333.728,[4051.19,19965.7,0.00172997]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('572', '15', '4', '[350.581,[14524.3,5086.61,0.00143814]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('574', '15', '4', '[348.637,[14487.3,5074.04,0.00143814]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('576', '15', '4', '[91.6978,[6607.89,8234.51,0.00153351]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('578', '15', '4', '[271.051,[17956.5,9961.22,0.00126076]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('580', '15', '4', '[279.518,[11075.4,14763.5,0.00145721]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('582', '16', '4', '[120.356,[2969.65,5453.39,0.00143814]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('584', '16', '4', '[215.141,[3402.25,5305.36,0.00147057]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('586', '16', '4', '[290.923,[9656.79,2483.55,0.00137329]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('588', '16', '4', '[57.0677,[17655.7,5539.08,0.00143862]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('590', '16', '4', '[230.773,[5462.45,12545.8,0.00136566]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('592', '17', '4', '[24.4586,[3163.98,5316.17,0.00144577]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('594', '17', '4', '[17.6695,[3222.46,5293.96,0.00144005]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('596', '17', '4', '[182.823,[9293.39,2576.44,0.00153732]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('598', '17', '4', '[155.09,[10972.3,10975,0.00128937]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('600', '17', '4', '[85.4432,[1598.31,7297.69,0.00144005]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('602', '18', '4', '[179.749,[1007.67,7499.09,1.71437]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('604', '18', '4', '[121.983,[17143.2,2582.46,0.00156653]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('606', '18', '4', '[355.963,[17716.5,4886.49,0.00227392]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('608', '18', '4', '[59.1327,[18034.9,8094.02,0.00158525]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('610', '18', '4', '[0.767264,[17826.7,10224.9,0.00190401]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('612', '18', '4', '[81.2798,[15563.8,11154.1,0.001495]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('614', '18', '4', '[6.33306,[4262.57,4288.46,0.00345945]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('616', '19', '4', '[7.3992,[18352.2,6011.36,0.00184667]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('618', '19', '4', '[250.471,[18151.7,7855.68,0.00135708]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('620', '19', '4', '[270.636,[16772.9,10562.4,0.00274718]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('622', '19', '4', '[351.73,[11507.9,14993,0.965291]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('624', '19', '4', '[83.7162,[6363.91,17355.7,0.00078702]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('626', '19', '4', '[91.0301,[5094.57,19351.1,0.00288367]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('628', '19', '4', '[351.488,[1192.56,13380.5,0.00300074]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('630', '20', '4', '[171.186,[3776.13,10674.6,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('632', '20', '4', '[180.383,[2808.99,7417.15,0.00178909]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('634', '20', '4', '[337.622,[3316.17,18896.4,0.0014801]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('636', '20', '4', '[312.569,[5086.79,19362,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('638', '20', '4', '[330.996,[15374.9,6823.46,0.00121307]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('640', '20', '4', '[187.82,[4137.43,6307.33,0.00127029]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('642', '20', '4', '[193.106,[1887.94,9004.43,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('644', '20', '4', '[192.203,[9569.67,9333.43,0.00167084]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('646', '21', '4', '[5.56208,[2098.65,8975.69,0.00146866]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('648', '21', '4', '[154.768,[9646.74,2098.54,0.00174522]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('650', '21', '4', '[181.024,[1514.15,12917.9,0.00141907]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('652', '21', '4', '[258.379,[15468.1,5603.96,0.00161362]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('654', '21', '4', '[149.373,[4923.48,12978.7,0.00140381]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('656', '21', '4', '[158.359,[6635.64,8274.18,0.0017395]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('658', '21', '4', '[222.703,[8382.96,8273.4,0.00178528]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('660', '21', '4', '[241.234,[7131.89,15402.4,0.00141144]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('662', '22', '4', '[27.1018,[3084.2,5516.45,0.00143909]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('664', '22', '4', '[241.808,[2195.43,9041.37,0.00143814]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('666', '22', '4', '[276.202,[12474.2,3036.74,0.747665]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('668', '22', '4', '[87.3855,[3118.16,10017.9,0.00137329]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('670', '22', '4', '[169.835,[1675.84,7615.47,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('672', '22', '4', '[294.049,[6395.36,5832.79,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('674', '22', '4', '[36.3959,[9707.87,5702.77,0.00165558]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('676', '22', '4', '[275.728,[12340.6,2968.18,0.716923]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('678', '22', '4', '[358.935,[17631.5,5357.28,0.00134254]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('680', '22', '4', '[311.694,[17882.3,7989.6,0.00146294]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('681', '1', '6', '[175.886,[10890.2,5378.44,0.00142074]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('683', '2', '6', '[174.155,[11969.4,7952.77,0.00150776]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('685', '3', '6', '[358.822,[11958.2,7915.47,0.00143909]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('687', '3', '6', '[222.69,[9069.26,5695.74,0.00131607]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('689', '4', '6', '[2.02999,[3256.67,7207.4,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('691', '5', '6', '[332.197,[1855.81,7786.5,0.00157166]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('693', '6', '6', '[206.49,[2732.54,6149.65,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('695', '6', '6', '[183.922,[10044.9,5487.75,0.00143814]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('697', '7', '6', '[152.029,[3313.51,7348.74,0.00157166]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('699', '7', '6', '[278.697,[10067.3,5492.78,0.00137854]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('701', '8', '6', '[357.001,[11978.2,7988.08,0.00143909]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('703', '8', '6', '[201.123,[2741.06,6145.14,0.0014267]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('705', '8', '6', '[167.721,[7986.91,5574,0.00199127]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('707', '8', '6', '[1.13996,[2786.48,4802.59,0.00134277]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('709', '9', '6', '[13.2568,[2707,6086.5,0.00157928]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('711', '9', '6', '[136.67,[2679.29,4692.43,0.00201416]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('713', '9', '6', '[355.88,[8378.63,5895.66,0.00138855]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('715', '10', '6', '[352.048,[11991.7,7985.22,0.00148582]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('717', '10', '6', '[180.88,[9054.5,5684.77,0.00133514]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('719', '11', '6', '[255.886,[11802.9,7873.46,0.00141907]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('721', '11', '6', '[313.43,[3536.07,6906.71,0.00157166]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('723', '11', '6', '[159.486,[9523.21,5475.63,0.00162697]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('725', '12', '6', '[168.687,[2054.08,7778.23,0.00140381]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('727', '12', '6', '[179,[9837.92,5577.34,0.00145531]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('729', '13', '6', '[149.743,[10129.3,7949.33,0.00145721]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('731', '13', '6', '[173.331,[10051.5,5501.49,0.00139523]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('733', '14', '6', '[319.419,[8677.56,5418.48,0.00145149]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('735', '16', '6', '[93.6155,[10453.7,4823.08,0.00147152]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('737', '17', '6', '[186.406,[9998.66,4767.6,0.00143909]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('739', '18', '6', '[311.929,[10646.4,5507.77,0.00143278]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('741', '18', '6', '[311.294,[10832.4,5339.3,0.00131679]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('743', '19', '6', '[273.881,[10573.2,5432.35,0.00152433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('745', '19', '6', '[311.403,[10694.8,5433.04,0.00143886]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('747', '19', '6', '[311.321,[10649.3,5296,0.00197101]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('749', '20', '6', '[119.806,[8086.94,5386.87,0.00166345]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('751', '21', '6', '[[358.72,[2655.44,4476.17,0.00167847]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('753', '22', '6', '[165.81,[10156.1,7936.34,0.00151825]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('755', '22', '6', '[356.618,[8048.93,5900.65,0.00161743]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('757', '22', '6', '[323.98,[10119.8,7933.48,0.00141907]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('759', '1', '6', '[359.996,[9566.01,4765.47,0.080862]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('761', '1', '6', '[131.251,[3938.89,9288.27,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('763', '1', '6', '[157.498,[6037.26,11135.9,0.00183105]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('765', '1', '6', '[358.863,[9532.11,4766.88,0.182859]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('767', '2', '6', '[355.785,[9515.65,4768.69,0.128586]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('769', '2', '6', '[359.337,[9549.93,4767.06,0.168596]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('771', '2', '6', '[97.0051,[5031.84,10294.7,0.00152588]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('773', '2', '6', '[130.228,[3947.68,9298.7,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('775', '3', '6', '[2.34458,[7617.06,10146.7,0.00153732]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('777', '4', '6', '[90.314,[6257.94,6169.02,0.00136566]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('779', '4', '6', '[265.698,[9061.41,7922.6,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('781', '4', '6', '[129.789,[3908.84,9288.32,0.0014801]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('783', '5', '6', '[260.24,[5110.56,4706.35,0.00146484]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('785', '5', '6', '[350.111,[10147.8,9934.74,0.00135994]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('787', '5', '6', '[2.34458,[7616.42,10172.6,0.00142288]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('789', '6', '6', '[180.954,[10116.8,9932.09,0.00153446]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('791', '6', '6', '[132.687,[3923.06,9281.8,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('793', '7', '6', '[356.811,[8982.65,7874.46,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('795', '7', '6', '[277.4,[6258.65,6082.04,0.00149536]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('797', '8', '6', '[185.823,[9533.35,4803.67,0.00141954]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('799', '8', '6', '[347.53,[5049.3,4680.65,0.00137329]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('801', '8', '6', '[201.811,[4013.82,9225.16,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('803', '8', '6', '[91.3147,[2652,4752.89,0.00160217]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('805', '9', '6', '[177.305,[9543.83,4803.5,0.00143242]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('807', '9', '6', '[94.4222,[7385.59,5352.31,0.00131607]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('809', '9', '6', '[221.316,[4004.74,9229.92,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('811', '9', '6', '[93.3289,[6229.84,6082.46,0.00136566]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('813', '10', '6', '[[0.950759,[10108,5645.78,0.00148344]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('815', '10', '6', '[179.804,[9552.42,4802.81,0.00143003]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('817', '10', '6', '[180.439,[4785.17,5190.13,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('819', '10', '6', '[294.358,[6395.08,6157.41,0.00160599]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('821', '11', '6', '[88.9736,[10095.4,5646.51,0.00147724]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('823', '11', '6', '[192.069,[4812.64,5186.59,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('825', '11', '6', '[33.5682,[6388.74,6193.43,0.00162506]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('827', '12', '6', '[82.5699,[4848.14,5138.41,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('829', '12', '6', '[316.186,[10099.2,9888.87,0.00133514]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('831', '13', '6', '[285.416,[4755.75,4696.04,0.00165558]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('833', '13', '6', '[168.841,[10139.6,9934.67,0.00146103]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('835', '14', '6', '[95.5068,[1210.29,10235.8,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('837', '15', '6', '[317.677,[4737.76,4677.17,0.0015564]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('839', '16', '6', '[82.1285,[4958.08,5155.86,0.00171661]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('841', '18', '6', '[270.956,[9978,5429.21,3.17232]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('843', '19', '6', '[87.2309,[9979.53,5409.02,0.877645]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('845', '20', '6', '[0.0248805,[8970.64,7888.41,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('847', '21', '6', '[176.956,[10127.3,9934,0.00145435]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('849', '22', '6', '[218.201,[3989.38,9267.45,0.165222]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('851', '3', '6', '[341.682,[2741.55,11264.1,0.00146484]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('853', '3', '6', '[341.682,[2741.55,11264.1,0.00146484]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('855', '4', '6', '[91.7057,[2678.73,4753.33,0.00146484]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('857', '4', '6', '[188.278,[2884.61,6123.43,0.0014801]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('859', '5', '6', '[182.62,[2703.2,4594,0.00120544]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('861', '5', '6', '[206.224,[3195.03,6080.03,0.00154114]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('863', '5', '6', '[71.6221,[3425.81,6976.33,0.00151062]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('865', '5', '6', '[41.7829,[1979.28,7785.79,0.0017395]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('867', '5', '6', '[337.025,[4873.12,5086.05,0.00140381]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('869', '6', '6', '[53.0504,[2681.48,4685.7,0.00170898]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('871', '7', '6', '[135.063,[3217.42,5997.79,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('873', '7', '6', '[201.495,[2717.07,6129.26,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('875', '8', '6', '[345.998,[2657.71,4471.82,0.00160217]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('877', '8', '6', '[139.801,[5138.87,5200.27,0.00152588]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('879', '9', '6', '[313.905,[3530.56,6912.69,0.00160217]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('881', '10', '6', '[93.4309,[3273.69,7229.57,0.00146484]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('883', '11', '6', '[169.868,[2053.43,7778.08,0.00140381]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('885', '12', '6', '[290.696,[3129.63,6113.99,0.00154114]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('887', '12', '6', '[86.9141,[4893.06,5140.01,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('889', '13', '6', '[329.786,[1855.88,7787.18,0.00151062]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('891', '5', '6', '[110.932,[6177.62,6864.82,0.0015564]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('893', '5', '6', '[163.364,[7076.19,9328.27,0.00146484]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('895', '13', '6', '[329.786,[1855.88,7787.18,0.00151062]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('897', '13', '6', '[177.043,[7235.76,9415.62,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('899', '9', '6', '[80.9802,[7094.68,9274.21,0.00149536]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('901', '9', '6', '[311.781,[6278.62,7015.64,0.00143433]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('903', '4', '6', '[95.4663,[7643.48,6971.34,0.00147247]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('905', '5', '6', '[276.209,[7825.63,6949.56,0.00130463]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('907', '5', '6', '[177.119,[9277.8,5701.52,1.65955]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('909', '6', '6', '[352.11,[4734.68,4675.63,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('911', '6', '6', '[93.9514,[7935.14,6972.35,0.00165558]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('913', '8', '6', '[268.111,[8368.57,5420.51,1.65997]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('915', '9', '6', '[85.3107,[9663.95,5668.88,1.66425]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('917', '10', '6', '[11.8789,[8132.46,5893.06,1.69315]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('919', '11', '6', '[90.068,[8220.49,5724.8,1.65314]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('921', '11', '6', '[265.014,[8022.16,5906.09,1.65851]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('923', '12', '6', '[7.07904,[7921.96,6844.09,0.00144958]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('925', '13', '6', '[170.439,[8395.93,5839.68,1.66151]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('927', '5', '6', '[42.1995,[10059.4,5622.01,0.00155783]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('929', '10', '6', '[11.8789,[8132.46,5893.06,1.69315]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('931', '10', '6', '[11.8789,[8132.46,5893.06,1.69315]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('933', '22', '6', '[152.889,[4766.71,5132.48,0.00144196]]', null, '0.850', null);
INSERT INTO `world_vehicle` VALUES ('935', '22', '6', '[354.308,[9819.49,5621.31,1.66866]]', null, '0.850', null);
