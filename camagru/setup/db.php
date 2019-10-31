<?php

require_once("db_config.php");

try
{
$bdd = new PDO($DB_NAME, $DB_USERNAME, $DB_PASSWD);
$bdd->setAttribute(PDO:: ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$response = $bdd->query('SELECT name FROM account');
}

catch(PDOException $e)
{
	die('Erreur : ' .$e->getMessage());
}

while ($data = $response->fetch())
{
	echo($data['name']);
	echo($data['psswd']);
	echo($data['email']);
	echo($data['account']);
}
?>
