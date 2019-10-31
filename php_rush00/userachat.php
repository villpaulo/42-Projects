<?php
while ($_POST["ajouter au panier"] == OK)
{
	// changer la valeur des OK!!!
	session_start();

	if (!file_exists(" ../private/achat"))
	{
		if (!file_exists("../private"))
			mkdir("../private");
		file_put_contents("../private/achat", "");
	}
	else
	{
		$file = file_get_contents("../private/achat");
		$tab = unserialize($file);
		$new = array();
		$counter = 1;
	}

	if ($_GET['chiuaua'] == OK )
	{
		$_SESSION[$_SESSION['count']] = "chiuaua";
		$_SESSION['count']++;
	}

	if ($_GET[''] == OK )
	{
		$_SESSION[$_SESSION['count']] = "";
		$_SESSION['count']++;
	}

	if ($_GET[''] == OK )
	{
		$_SESSION[$_SESSION['count']] = "";
		$_SESSION['count']++;
	}


	if ($_POST["valider les achats"] == OK)
	{
		$i = 0;
		while ($_SESSION['count'] > -1)
		{
			// CODE QUI STOCKE DANS LE TAB NEW PIS DANS LE FICHIER;
			$new[$i++] = $_SESSION[$_SESSION['count']];
			$_SESSION['count']--;
		}
	}

	if ($_POST["fin des achats"] == OK)
	{
		if ($counter == 1)
		{
			$prec = ['anciens achats' => $tab, 'nouveau achats' => $new);
			$file = serialize($prec);
			file_put_contents("../private/achat", $file);
			exit();
		}
		$prec = $new;
		$file = serialize($prec);
		file_put_contents("../private/achat", $file);
		exit();
	}
}

?>
