<?php
header('Location: edit_obj.php');
session_start();
if ($_SESSION['admin'] == 1)
{
$data = unserialize(file_get_contents("database/bdd.csv"));
$i = 1;
$ok = 0;
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				if ($val['item'] === $_POST['item'])
				{
					$i = 0;
				}
				$ok = $key + 1;
			}
		}
		if ($i != 0)
		{
			if ($_POST['item'] && trim($_POST['item']) && $_POST['categorie1'] && $_POST['categorie2'] && $_POST['qte'] && $_POST['prix'])
			{
				$data[$ok]['item'] = $_POST['item'];
				$data[$ok]['categorie1'] = $_POST['categorie1'];
				$data[$ok]['categorie2'] = $_POST['categorie2'];
				$data[$ok]['qte'] = $_POST['qte'];
				$data[$ok]['prix'] = $_POST['prix'];
				file_put_contents("database/bdd.csv", serialize($data));
			}
			else {
				?>
				<meta http-equiv="refresh" content='0;URL=edit_obj.php'/>
				<?php
			}
		}
		else
			echo "ERROR\n";
}
?>
