<?php
include_once("../setup/db_config.php");
session_start();

function	CheckVerif($response)
{
	while ($data = $response->fetch())
	{
		if ($data != null)
		{
			return true;
		}
	}
	return false;
}

function	CheckID($response)
{
	while ($data = $response->fetch())
	{
		if ($data != null)
		{
			return true;
		}
	}
	return false;
}

try	{
	$bdd = new PDO($DB_DSN, $DB_USERNAME, $DB_PSSWD);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	$username = $_GET['username'];
	$id = $_GET['id'];


	$response = $bdd->prepare('SELECT username FROM users WHERE username=:username;');
	$response->execute(array('username' => $username));
	if (!CheckVerif($response))
	{
		$_SESSION['error'] = "Un probleme est survenu, compte invalide";
		exit(header("Location: http://localhost:3500/index.php"));
	}

	$response = $bdd->prepare('SELECT id FROM users WHERE username=:username');
	$response->execute(array('username' => $username));

	if (!CheckID($response))
	{
		$_SESSION['error'] = "Un probleme est survenu, compte invalide";
		exit(header("Location: http://localhost:3500/index.php"));
	}

	$verified = "Y";
	$action = $bdd->prepare('UPDATE users SET verified =:verified WHERE id =:id');
	$action->execute(array('verified' => $verified, 'id' => $id));
	$_SESSION['signup_success'] = "compte valide";
	header("Location: http://localhost:3500/index.php");
	exit();
}

catch (PDOException $e)
{
	$v['err'] = $e->getMessage();
	return ($v);

}
?>
