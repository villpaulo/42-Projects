<?php
session_start();?>
<!DOCTYPE html>
<?php
if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv") && $_SESSION['admin'] == 1) {
	include("inc_adm.php"); ?>
<html>
	<head>
		<meta charset="utf-8">
		<title>Edit user</title>
		<LINK REL="stylesheet" href="style.css">
	</head>
	<body>
		<?php
		if (!file_exists("database/account.csv"))
			file_put_contents("database/account.csv", "");
		$data = unserialize(file_get_contents("database/account.csv"));
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				?>
				<form action="edituser.php" method="post">
					<span class="out">Pseudo: <input type="text" name="login" value="<?php echo $val['login'];?>">
					&nbsp;First name: <input type="text" name="fname" value="<?php echo $val['fname'];?>">
					&nbsp;Last name: <input type="text" name="lname" value="<?php echo $val['lname'];?>">
					&nbsp;Mail: <input type="email" name="mail" value="<?php echo $val['mail'];?>">
					&nbsp;Street: <input type="text" name="street" value="<?php echo $val['street'];?>">
					&nbsp;Postal code: <input type="text" name="postalcode" value="<?php echo $val['postalcode'];?>">
					&nbsp;City: <input type="text" name="city" value="<?php echo $val['city'];?>">
					&nbsp;Admin: <input type="text" name="admin" value="<?php echo $val['admin'];?>">
					&nbsp;<input type="hidden" name="id" value="<?php echo $val['id'];?>">
					<input type="submit" name="submit" value="EDIT">
					<input type="submit" name="submit" value="DEL"></span><br />
				</form><br />
				<?php
			}
		}
		?><br />
		<form action="adduser.php" method="post">
			<span class="add">Pseudo: <input type="text" name="login" value="">
			&nbsp;Password: <input type="password" name="passwd" value="">
			&nbsp;First name: <input type="text" name="fname" value="">
			&nbsp;Last name: <input type="text" name="lname" value="">
			&nbsp;Mail: <input type="email" name="mail" value="">
			&nbsp;Street: <input type="text" name="street" value="">
			&nbsp;Postal code: <input type="text" name="postalcode" value="">
			&nbsp;City: <input type="text" name="city" value="">
			&nbsp;Admin: <input type="text" name="admin" value="">
			<input type="submit" name="submit" value="ADD"></span><br />
		</form><br />
		<?php if ($_SESSION['error'])
		{
			echo "<span class='add'>";
			echo $_SESSION['error'];
			echo "</span>";
			$_SESSION['error'] = "";
		}?>
	</body>
</html>
<?php }
else {
	?><meta http-equiv="refresh" content="0; url=index.php"/><?php
}?>
