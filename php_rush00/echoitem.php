<?php
header('Location: index.php');
session_start();
if ($_POST['howmuch'] AND $_POST['item'] AND $_POST['prix'] AND $_POST['categorie1'] AND $_POST['categorie2'] AND $_POST['qte'])
{
	$tab = array('item' => $_POST['item'], 'stock' => $_POST['qte'], 'qte' => $_POST['howmuch'], 'prix' => $_POST['prix'], 'categorie1' => $_POST['categorie1'], 'categorie2' => $_POST['categorie2']);
	if ($_SESSION['basket'])
	{
		$i = 0;
		foreach ($_SESSION['basket'] as $key => $val)
		{
			if ($val['item'] == $tab['item'])
			{
				$_SESSION['basket'][$key]['qte'] = $val['qte'] + $tab['qte'];
				$_SESSION['basket'][$key]['prix'] = $tab['prix'];
				$_SESSION['basket'][$key]['categorie1'] = $tab['categorie1'];
				$_SESSION['basket'][$key]['categorie2'] = $tab['categorie2'];
				$_SESSION['basket'][$key]['stock'] = $tab['stock'];
				$i = 1;
			}
			$ok = $key + 1;
		}
		if ($i != 1)
		{
			$_SESSION['basket'][$ok]['item'] = $tab['item'];
			$_SESSION['basket'][$ok]['qte'] = $tab['qte'];
			$_SESSION['basket'][$ok]['stock'] = $tab['stock'];
			$_SESSION['basket'][$ok]['prix'] = $tab['prix'];
			$_SESSION['basket'][$ok]['categorie1'] = $tab['categorie1'];
			$_SESSION['basket'][$ok]['categorie2'] = $tab['categorie2'];
		}
	}
	else
	{
		$_SESSION['basket'][0]['item'] = $tab['item'];
		$_SESSION['basket'][0]['qte'] = $tab['qte'];
		$_SESSION['basket'][0]['stock'] = $tab['stock'];
		$_SESSION['basket'][0]['prix'] = $tab['prix'];
		$_SESSION['basket'][0]['categorie1'] = $tab['categorie1'];
		$_SESSION['basket'][0]['categorie2'] = $tab['categorie2'];
	}
	if ($_SESSION['login'])
	{
		$data = unserialize(file_get_contents("database/account.csv"));
		if ($data) {
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
	$_SESSION['ok'] = "Item added to your basket !";
}
?>
