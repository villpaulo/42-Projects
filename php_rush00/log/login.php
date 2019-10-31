<?php
session_start();
if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv") && !$_SESSION['login']) {
	 include ("inc.php"); ?>
<html>
	<head>
		<meta charset="utf-8">
		<title>Login</title>
		<LINK REL="stylesheet" href="style.css">
	</head>
	<body>
		<br />
		<form action="login.php" method="post">
			<span class="out">Pseudo: <input type="text" name="login">
			Password: <input type="password" name="passwd">
			<input type="submit" name="submit" value="OK"></span>
		</form>
		<?php
		include("auth.php");
		if ($_POST["login"] && $_POST["passwd"])
		{
			if (auth($_POST['login'], $_POST['passwd']))
			{
				$_SESSION['login'] = $_POST['login'];
				$data = unserialize(file_get_contents("database/account.csv"));
				if ($data)
				{
					foreach ($data as $key => $val)
					{
						if ($val['login'] === $_SESSION['login'])
						{
							$_SESSION['nblogin'] = $key;
							$_SESSION['admin'] = $val['admin'];
						}
					}
				}
				if ($_SESSION['basket'])
				{
					$data[$_SESSION['nblogin']]['basket'] = $_SESSION['basket'];
					file_put_contents("database/account.csv", serialize($data));
				}
				else {
					$_SESSION['basket'] = $data[$_SESSION['nblogin']]['basket'];
				}?>
					<meta http-equiv="refresh" content="0; url=index.php" />
				<?php
			}
			else {
				echo "<br /><br /><span class='add'>Your passsword doesn't match with your login.</span>";
			}
		}
		else if ($_POST) {
			echo "<br /><br /><span class='add'>Your passsword doesn't match with your login.</span>";
		}
		?>
	</body>
</html>
<?php }?>
