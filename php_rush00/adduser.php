<?php
header('Location: edit_user.php');
session_start();
if ($_SESSION['admin'] == 1)
{
$data = unserialize(file_get_contents("database/account.csv"));
$i = 1;
$ok = 1;
$rr = -1;
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				if ($val['login'] === $_POST['login'])
				{
					$i = 0;
				}
				if (!$val['id'])
					$rr = $key;
				$ok = $key + 1;
			}
		}
		if ($i != 0)
		{
			if ($_POST['login'] && $_POST['passwd'] && $_POST['fname'] &&
			$_POST['lname'] && $_POST['mail'] && $_POST['street'] &&
			$_POST['postalcode'] && $_POST['city'] && is_numeric($_POST['admin']))
			{
				$data[$ok]['login'] = $_POST['login'];
				$data[$ok]['passwd'] = hash(whirlpool, $_POST['passwd']);
				$data[$ok]['fname'] = $_POST['fname'];
				$data[$ok]['lname'] = $_POST['lname'];
				$data[$ok]['mail'] = $_POST['mail'];
				$data[$ok]['street'] = $_POST['street'];
				$data[$ok]['postalcode'] = $_POST['postalcode'];
				$data[$ok]['city'] = $_POST['city'];
				if ($rr != -1 && $rr < $ok)
					$data[$ok]['id'] = $rr;
				else
					$data[$ok]['id'] = $ok;
				$data[$ok]['admin'] = $_POST['admin'];
				file_put_contents("database/account.csv", serialize($data));
			}
			else {
				?>
				<meta http-equiv="refresh" content='0;URL=edit_user.php'/>
				<?php
			}
		}
		else
			echo "ERROR\n";
}
?>
