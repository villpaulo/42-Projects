#!/usr/bin/php
<?php
include_once 'db_config.php';

// create db
try {
	$bdd = new PDO($DB_DSN_LIGHT, $DB_USERNAME, $DB_PASSWD);
	$bdd->SetAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE DATABASE `".$DB_NAME."`";
	$bdd->exec($sql);
	echo "Database created successfully/\n";
}

catch(PDOException $e)
{
	echo "ERROR CREATING DB: \n ".$e->getMessage()."";
	exit (-1);
}
// table user

try {
	$bdd = new PDO($DB_DSN, $DB_USERNAME, $DB_PASSWD);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE `users` (
		`id` INT NOT NULL AUTO_INCREMENT,
		`username` VARCHAR(50) NOT NULL,
		`email` VARCHAR(100) NOT NULL,
		`psswd` VARCHAR(255) NOT NULL,
		`verified` VARCHAR(1) NOT NULL DEFAULT 'N',
		PRIMARY KEY(id)
		)";
	$bdd->exec($sql);
	echo "Table users created successfully\n";
}

catch (PDOException $e)
{
	echo "ERROR CREATING TABLE USERS: \n ".$e->getMessage()."";
}

// table pictures

try {
	$bdd = new PDO($DB_DSN, $DB_USERNAME, $DB_PSSWD);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE `pictures` (
		`id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
		`userid` INT(11) NOT NULL,
		`img` VARCHAR(100) NOT NULL,
		FOREIGN KEY (userid) REFERENCES users(id)
		)";
	$bdd->exec($sql);
	echo "Table pictures created successfully";
}

catch (PDOException $e)
{
	echo "ERROR CREATING TABLE PICTURES: \n ".$e->getMessage()."";
}
?>

