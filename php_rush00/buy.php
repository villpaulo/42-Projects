<?php
	session_start();
	if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
		<meta http-equiv="refresh" content="0; url=install.php" />
	<?php }
	if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv")) {
include ('inc.php');
	if ($_POST['submit'] === BUY && $_SESSION['login'])
	{
		?>
		<!DOCTYPE html>
		<html>
			<head>
				<meta charset="utf-8">
				<title>buy</title>
				<LINK REL="stylesheet" href="style.css">
			</head>
			<body><br />
		<form action="addpurchase.php" method="post">
			<span class="add">Are you sure ?</span>
			<input type="submit" name="submit" value="NO">
			<input type="submit" name="submit" value="YES">
		</form>
	</body>
</html><?php
	}
}?>
