<?php session_start(); ?>
<html>
	<head>
		<meta charset="utf-8">
		<title>Install</title>
        <LINK REL="stylesheet" href="style.css">
	</head>
	<body bgcolor=#636363>
		<form action="install.php" method="post">
			<span class="add">Pseudo: <input type="text" name="login"></span><br /><br />
			<span class="add">Password: <input type="password" name="passwd"></span><br /><br />
			<span class="add">Retape your password: <input type="password" name="passwd2"></span><br /><br />
			<span class="add">Mail: <input type="email" name="mail"></span><br /><br />
			<input type="submit" name="submit" value="install">
		</form>
	</body>
</html>
<?php
if ($_POST['submit'] === install)
{
	if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv") && $_POST['passwd'] === $_POST['passwd2'] && $_POST['login'] &&
	$_POST['mail'])
	{
		mkdir("database");
		if (!file_exists("database/account.csv"))
			file_put_contents("database/account.csv", "");
		if (!file_exists("database/bdd.csv"))
			file_put_contents("database/bdd.csv", "");
		if (!file_exists("database/category.csv"))
			file_put_contents("database/category.csv", "");
		if (!file_exists("database/account.csv"))
			file_put_contents("database/account.csv", "");
		$data = unserialize(file_get_contents("database/category.csv"));
		$data[0]['catname'] = "All";
		file_put_contents("database/category.csv", serialize($data));
		$data = unserialize(file_get_contents("database/account.csv"));
		$data[0]['login'] = $_POST['login'];
		$data[0]['passwd'] = hash(whirlpool, $_POST['passwd']);
		$data[0]['mail'] = $_POST['mail'];
		$data[0]['admin'] = 1;
		$data[0]['id'] = 0 + 1;
		file_put_contents("database/account.csv", serialize($data));
		$_SESSION['login'] = $_POST['login'];
		$_SESSION['admin'] = 1;
		?>
		<meta http-equiv="refresh" content='0;URL=index.php'/>
		<?php
	}
	else
		echo "The database is already create or a field is missing";
}
?>
