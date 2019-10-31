<?php
	header('Location: panier.php');
	session_start();
	if ($_POST['submit'] === EDIT)
	{
		foreach ($_SESSION['basket'] as $key => $val)
		{
			if ($_POST['item'] === $val['item'])
			{
				if ($_POST['qte'] == 0)
				{
					unset($_SESSION['basket'][$key]);
					$_SESSION['basket'] = array_values(array_filter($_SESSION['basket']));
				}
				else
				{
					$_SESSION['basket'][$key]['qte'] = $_POST['qte'];
				}
				if ($_SESSION['login'])
				{
					$data = unserialize(file_get_contents("database/account.csv"));
					foreach ($data as $key => $val)
					{
						if ($val['login'] === $_SESSION['login'])
						{
							$data[$key]['basket'] = $_SESSION['basket'];
						}
					}
					file_put_contents("database/account.csv", serialize($data));
				}
			}
		}
		$_SESSION['ok'] = "An item of your basket has been updated !";
	}
	else if ($_POST['submit'] === DEL)
	{
		foreach ($_SESSION['basket'] as $key => $val)
		{
			if ($_POST['item'] === $val['item'])
			{
				unset($_SESSION['basket'][$key]);
				$_SESSION['basket'] = array_values(array_filter($_SESSION['basket']));
				if ($_SESSION['login'])
				{
					$data = unserialize(file_get_contents("database/account.csv"));
					foreach ($data as $key => $val)
					{
						if ($val['login'] === $_SESSION['login'])
						{
							$data[$key]['basket'] = $_SESSION['basket'];
						}
					}
					file_put_contents("database/account.csv", serialize($data));
				}
			}
		}
		$_SESSION['ok'] = "Item removed from your basket !";
	}
?>
