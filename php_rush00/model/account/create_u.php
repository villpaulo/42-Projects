<?php session_start(); ?>
<html>
<?php
if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv") && !$_SESSION['login']) {
	 include ("inc.php"); ?>
	<head>
		<meta charset="utf-8">
		<title>Creating Account</title>
			<LINK REL="stylesheet" href="style.css">
	</head>
	<body>
		<BR>
		<form action="create.php" method="post">
			<span class="out">Pseudo: <input type="text" name="login">
			Password: <input type="password" name="passwd">
			Retape your password: <input type="password" name="passwd2">
			First name: <input type="text" name="fname">
			Last name: <input type="text" name="lname">
			Mail: <input type="email" name="mail">
			Street: <input type="text" name="street">
			Postal code: <input type="text" name="postalcode">
			City: <input type="text" name="city">
			<input type="submit" name="submit" value="OK"></span><br /><br />
		</form>
		<?php if ($_SESSION['error'])
		{
			echo "<span class='add'>";
			echo $_SESSION['error'];
			echo "</span>";
			$_SESSION['error'] = "";
		}?>
	</body>
</html>
<?php }?>
