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

CREATE DATABASE IF NOT EXISTS `breakingpointmod` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `breakingpointmod`;


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
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

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


