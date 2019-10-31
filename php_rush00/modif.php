<?php
session_start();
if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv") && $_SESSION['login']) {
	 include ("inc.php"); ?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Modificate Account</title>
		<LINK REL="stylesheet" href="style.css">
	</head>
	<body>
		<?php if ($_SESSION['ok'])
		{?>
		<span class="error"><?php echo $_SESSION['ok'];?></span>
		<?php $_SESSION['ok'] = "";
	}?>
	<br />
		<?php $data = unserialize(file_get_contents("database/account.csv"));?>
		<CENTER><H1><span class="title">Modify Account</span></H1></CENTER>
		<form action="modif.php" method="post">
			<span class='out'>Old password: <input type="password" name="oldpw" value="">
			New password: <input type="password" name="newpw" value="">
			First name: <input type="text" name="fname" value="<?= $data[$_SESSION['nblogin']]['fname'];?>">
			Last name: <input type="text" name="lname" value="<?= $data[$_SESSION['nblogin']]['lname'];?>">
			Mail: <input type="email" name="mail" value="<?= $data[$_SESSION['nblogin']]['mail'];?>">
			Street: <input type="text" name="street" value="<?= $data[$_SESSION['nblogin']]['street'];?>">
			Postal code: <input type="text" name="postalcode" value="<?= $data[$_SESSION['nblogin']]['postalcode'];?>">
			City: <input type="text" name="city" value="<?= $data[$_SESSION['nblogin']]['city'];?>">
			<input type="submit" name="submit" value="OK">
			<input type="submit" name="submit" value="destroy"></span>
		</form><br /><br /><br /><br /><br /><br />
		<CENTER><H1><span class="title">Order History</span></H1></CENTER>
		<?php
		if ($_SESSION['login'])
		{
			$data = unserialize(file_get_contents("database/account.csv"));
			$i = 1;
			if ($data)
			{
				foreach ($data as $key => $val)
				{
					if ($val['login'] === $_SESSION['login'])
					{
						$i = 0;
						$ok = $key;
					}
				}
				if ($i == 0 && $data[$ok]['purchase'])
				{
					foreach ($data[$ok]['purchase'] as $key => $val) {
						?><span class="add"><b>Order <?= $key + 1?> :</b></span><br /><br /><?php
						foreach ($val as $val2)
						{?>
							<span class="out"><b>Item: </b><?php echo $val2['item'];?>&nbsp;&nbsp;
							<b>Category 1: </b><?php echo $val2['categorie1'];?>&nbsp;&nbsp;
							<b>Category 2: </b><?php echo $val2['categorie2'];?>&nbsp;&nbsp;
							<b>Qantity: </b><?php echo $val2['qte'];?>
							<b>Price: </b><?php echo $val2['prix'] * $val2['qte'];?> euro(s)&nbsp;&nbsp;</span><br /><br />
							<?php
							$total = $total + ($val2['prix'] * $val2['qte']);
						}?>
						<span class="add"><b>Total: </b><?php echo $total;?> euro(s)</span>&nbsp;<BR /><br /><br />
						<?php
					}
				}
				else
				{
						echo "<span class='add'>You never purchase from this website</span>";
				}
			}
		}
		else {?>
		<meta http-equiv="refresh" content='0;URL=index.php'/>
		<?php }?>
	</body>
</html>
<?php
	session_start();
	if ($_POST["submit"] === "OK" && file_exists("database") &&
	file_exists("database/account.csv"))
	{
		$data = unserialize(file_get_contents("database/account.csv"));
		$i = 1;
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				if ($val['login'] === $_SESSION['login'])
				{
					$i = 0;
					$ok = $key;
				}
			}
			if ($i == 0 && $data[$ok]['passwd'] === $_POST['oldpw'])
			{
				$data[$ok]['passwd'] = hash(whirlpool, $_POST['newpw']);
				file_put_contents("database/account.csv", serialize($data));
			}
			if ($i == 0 && $_POST['mail'])
			{
				$data[$ok]['mail'] = $_POST['mail'];
				file_put_contents("database/account.csv", serialize($data));
			}
			if ($i == 0 && $_POST['fname'])
			{
				$data[$ok]['fname'] = $_POST['fname'];
				file_put_contents("database/account.csv", serialize($data));
			}
			if ($i == 0 && $_POST['lname'])
			{
				$data[$ok]['lname'] = $_POST['lname'];
				file_put_contents("database/account.csv", serialize($data));
			}
			if ($i == 0 && $_POST['street'])
			{
				$data[$ok]['street'] = $_POST['street'];
				file_put_contents("database/account.csv", serialize($data));
			}
			if ($i == 0 && $_POST['postalcode'])
			{
				$data[$ok]['postalcode'] = $_POST['postalcode'];
				file_put_contents("database/account.csv", serialize($data));
			}
			if ($i == 0 && $_POST['city'])
			{
				$data[$ok]['city'] = $_POST['city'];
				file_put_contents("database/account.csv", serialize($data));
			}
			$_SESSION['ok'] = "Account succesfully modified !";
			?>
			<meta http-equiv="refresh" content="0; url=modif.php" /><?php
		}
	}
	else if ($_POST["submit"] === "destroy" && file_exists("database") &&
	file_exists("database/account.csv"))
	{
		$data = unserialize(file_get_contents("database/account.csv"));
		$i = 1;
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				if ($val['login'] === $_SESSION['login'])
				{
					$i = 0;
					$ok = $key;
				}
			}
			if ($i == 0)
			{
				unset($data[$ok]);
				$data = array_values(array_filter($data));
				file_put_contents("database/account.csv", serialize($data));
				session_destroy();?>
				<meta http-equiv="refresh" content="0; url=index.php"/><?php
			}
		}
	}
}
?>
