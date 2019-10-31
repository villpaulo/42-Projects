<?php
header('Location: edit_obj.php');
session_start();
if ($_SESSION['admin']) {
$data = unserialize(file_get_contents("database/bdd.csv"));
$i = 1;
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				if ($val['item'] === $_POST['item'])
				{
					$i = 0;
					$ok = $key;
				}
			}
		}
		if ($i == 0 && $_POST['submit'] === 'EDIT')
		{
			if ($_POST['item'] && trim($_POST['item']) && $_POST['categorie1'] && $_POST['categorie2'] && is_numeric($_POST['qte']) && is_numeric($_POST['prix']))
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
		else if ($i == 0 && $_POST['submit'] === 'DEL')
		{
			unset($data[$ok]);
			$data = array_values(array_filter($data));
			file_put_contents("database/bdd.csv", serialize($data));
			echo "OK\n";
		}
		else
			echo "ERROR\n";
		}
?>
