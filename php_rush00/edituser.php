<?php
header('Location: edit_user.php');
session_start();
if ($_SESSION['admin']) {
$data = unserialize(file_get_contents("database/account.csv"));
$i = 1;
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				if ($val['id'] == $_POST['id'])
				{
					$i = 0;
					$ok = $key;
				}
			}
		}
		if ($i == 0 && $_POST['submit'] === 'EDIT')
		{
			if ($i == 0 && $_POST['mail'])
			{
				$data[$ok]['mail'] = $_POST['mail'];
				file_put_contents("database/account.csv", serialize($data));
				echo "OK\n";
			}
			if ($i == 0 && $_POST['fname'])
			{
				$data[$ok]['fname'] = $_POST['fname'];
				file_put_contents("database/account.csv", serialize($data));
				echo "OK\n";
			}
			if ($i == 0 && $_POST['lname'])
			{
				$data[$ok]['lname'] = $_POST['lname'];
				file_put_contents("database/account.csv", serialize($data));
				echo "OK\n";
			}
			if ($i == 0 && $_POST['street'])
			{
				$data[$ok]['street'] = $_POST['street'];
				file_put_contents("database/account.csv", serialize($data));
				echo "OK\n";
			}
			if ($i == 0 && $_POST['postalcode'])
			{
				$data[$ok]['postalcode'] = $_POST['postalcode'];
				file_put_contents("database/account.csv", serialize($data));
				echo "OK\n";
			}
			if ($i == 0 && $_POST['city'])
			{
				$data[$ok]['city'] = $_POST['city'];
				file_put_contents("database/account.csv", serialize($data));
				echo "OK\n";
			}
			if ($i == 0 && is_numeric($_POST['admin']))
			{
				$data[$ok]['admin'] = $_POST['admin'];
				$_SESSION['admin'] = $_POST['admin'];
				file_put_contents("database/account.csv", serialize($data));
				echo "OK\n";
			}
			else {
				?>
				<meta http-equiv="refresh" content='0;URL=edit_user.php'/>
				<?php
			}
		}
		else if ($i == 0 && $_POST['submit'] === 'DEL')
		{
			$data = unserialize(file_get_contents("database/account.csv"));
			$k = 0;
			foreach ($data as $key => $val)
			{
				if ($_SESSION['login'] === $_POST['login'])
				{
					$k = 1;
				}
			}
			if ($k == 0)
			{
				unset($data[$ok]);
				$data = array_values(array_filter($data));
				file_put_contents("database/account.csv", serialize($data));
				echo "OK\n";
			}
			else {
				$_SESSION['error'] = "Log out before deleting yourself.\n";
			}
		}
		else
			echo "ERROR\n";
}?>
