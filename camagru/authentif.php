<?php
 //$_GET  $_POST $_SUBMIT
	require_once(db.php);

	$bdd->query('SELECT username FROM account');
	$response = $bdd->fetch();

	if (empty($_POST['username']) || empty($_POST['psswd']) || empty($_POST['email']))
	{
	$_SESSION['error']  = "you need to complete all field";
	echo('3');
	header("Location: index.php");
	}

	function	CheckUsername()
	{
		foreach ($val = response->fetch())
		{
				if ($_POST['username'] = $val)
					{
						echo ('1');
						die (
						header("Location: index.php")
				}
		}
	}

	function 	CheckPsswd($_POST, $response)
	{

	}

	if (empty($_POST['username']) || empty($_POST['psswd']) || empty($_POST['username'])) {

	}


	<a href = "create_account"> Sign up </a>
	<a href = "forgot.php"> Forgot your password? </a>

?>
