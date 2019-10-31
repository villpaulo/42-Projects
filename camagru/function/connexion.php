<?php
include_once("../setup/db_config.php");

function	CheckAuth($response)
{

	while ($data = $response->fetch())
	{
		if ($data != null)
		{
			echo("data[0]=". $data[0] ."\n". "data[1]=". $data[1] . "\n");
			return (true);
		}
	}
	return false;
}

function	CheckVerified($response)
{
	while ($data = $response->fetch())
	{
		if ($data == 'V')
			return (true);
	}
	return false;
}


try {

	$dbb = new PDO($DB_NAME, $DB_USERNAME, $DB_PSSWD);
	$dbb->setAttribute(PDO::ERRMODE_EXCEPTION, PDO::ATTR_ERRMODE);
}

catch (PDOEXCEPTION $e)
{
	$v['err'] = $e->getMessage();
	return ($v);
}

$username = $_POST['username'];
$psswd = $_POST['psswd'];

$response = $bdd->prepare('SELECT username FROM users WHERE psswd=:psswd');
$response->execute(array('username' => $username, 'psswd' => $psswd));

if (!CheckAuth($response))
{
	echo(1);
	exit();
}

$response = $bdd->prepare('SELECT verified FROM users WHERE username=:username');
$response->execute(array('username' => $username));

if (!CheckVerified($response))
{
	echo(2);
	exit();
}

$_SESSION['username'] = $username;
$_SESSION['signin'] = 1;

?>
