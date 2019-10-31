<?php
session_start();
include_once "../setup/db_config.php";

function	CheckUserMail($response)
{
	while ($data = $response->fetch())
	{
		if ($data != null)
		{ return true; } } return false;
}

function	CheckUserName($response)
{
	while ($data = $response->fetch())
	{
		return true;
	}
	return false;
}

function	Verif_email($email)
{
	if (preg_match('#^[\w.-]+@[\w.-]+\.[a-z]{2,6}$#i', $email))
		return (true);
	return (false);
}

try {
	$bdd = new PDO($DB_DSN, $DB_USERNAME, $DB_PSSWD);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}

catch (PDOException $e)
{
	$v['err'] = $e->getMessage();
	return ($v);
}

if (empty($_POST['username']) || empty($_POST['psswd']) || empty($_POST['verifpsswd']) || empty($_POST['email']))
{
	echo(2);
	exit();
}


else
{
	$response = $bdd->prepare('SELECT username FROM users WHERE username=:username');
	$response->execute(array('username' => $_POST['username']));

	if (CheckUserName($response))
	{
		echo(4);
		exit();
	}
	//echo("strlenPOST['username']=". strlen($_POST['username']));
	if (strlen($_POST['username']) < 3 || strlen($_POST['username']) > 20)
	{
		echo(5);
		exit();
	}

	if ($_POST['psswd'] != $_POST["verifpsswd"])
	{
		echo(6);
		exit();
	}

	if (strlen($_POST['psswd']) < 5 || strlen($_POST['psswd']) > 50)
	{
		echo(7);
		exit();
	}
/*	$response = $bdd->prepare('SELECT email FROM users WHERE email=:email');
	$response->execute(array('email' => $_POST['email']));

	if (CheckUserMail($response))
	{
		echo(8);
		exit();
}*/
	else {
		if (!Verif_email($_POST['email']))
		{
			echo(9);
			exit();
		}
		$username = $_POST['username'];
		$psswd = hash('whirlpool', $_POST['psswd']);
		$email = $_POST['email'];
		$verified = "N";
		$_SESSION['signup_success'] = "signup success pls check your mail box";

		$req = $bdd->prepare('INSERT INTO users(username, psswd, email, verified) VALUE (:username, :psswd, :email, :verified)');
		$req->execute(array(':username' => $username, ':psswd' => $psswd, ':email' => $email, ':verified' => $verified));


		$response = $bdd->prepare('SELECT id FROM users WHERE username=:username');
		$response->execute(array(':username' => $username));
		$id = $response->fetch();

		$sujet = "Activer votre compte" ;

		$entete  = 'MIME-Version: 1.0' . "\r\n";
		$entete .= 'Content-type: text/html; charset=UTF-8' . "\r\n";
		$entete .= 'From: <pvillene@student.42.fr>' . "\r\n";
		$message = '
			<html>
			<head>
			<title>' . $sujet . '</title>
			</head>
			<body>
			<p> <strong> Welcome To Camagru </strong> </p> </br>
			Hello ' . htmlspecialchars($username) . ' </br>
			To finalyze your subscribtion please click the link below </br>
			<a href="http://localhost:3500/function/validation.php?username='.$username.'&id='.$id[0].'"> Verify my email </a>
			</body>
			</html> ';

		mail($email, $sujet, $message, $entete);
		echo(3);
		return;
	}
}
?>
