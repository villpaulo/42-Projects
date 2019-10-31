<?php
	session_start();
	if ($_POST["submit"] === "OK")
	{
		$data = unserialize(file_get_contents("database/account.csv"));
		$i = 1;
		$ok = 0;
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				if ($val['login'] === $_POST["login"])
				{
					?>
					<meta http-equiv="refresh" content='0;URL=create_u.php'/>
					<?php
					$i = 0;
				}
				$ok = $key + 1;
			}
		}
		if ($i != 0)
		{
			if ($_POST['passwd'] === $_POST['passwd2'] && $_POST['login'] &&
			$_POST['fname'] && $_POST['lname'] && $_POST['mail'] &&
			$_POST['street'] && $_POST['postalcode'] && $_POST['city'])
			{
				$data[$ok]['login'] = $_POST['login'];
				$data[$ok]['passwd'] = hash(whirlpool, $_POST['passwd']);
				$data[$ok]['fname'] = $_POST['fname'];
				$data[$ok]['lname'] = $_POST['lname'];
				$data[$ok]['mail'] = $_POST['mail'];
				$data[$ok]['street'] = $_POST['street'];
				$data[$ok]['postalcode'] = $_POST['postalcode'];
				$data[$ok]['city'] = $_POST['city'];
				$data[$ok]['admin'] = 0;
				$data[$ok]['id'] = $ok + 1;
				$data[$ok]['basket'] = $_SESSION['basket'];
				file_put_contents("database/account.csv", serialize($data));
				$_SESSION['login'] = $_POST['login'];
				?>
				<meta http-equiv="refresh" content='0;URL=index.php'/>
				<?php
			}
			else {
				$_SESSION['error'] = "A field is missing or your password is incorrect.";
				?>
				<meta http-equiv="refresh" content='0;URL=create_u.php'/>
				<?php
			}
		}
	}
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body bgcolor="#636363">
	</body>
</html>
