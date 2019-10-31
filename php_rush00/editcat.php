<?php
header('Location: edit_category.php');
session_start();
if ($_SESSION['admin']) {
$data = unserialize(file_get_contents("database/category.csv"));
$i = 1;
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				if ($val['catname'] === $_POST['catname'])
				{
					$i = 0;
					$ok = $key;
				}
			}
		}
		if ($i == 0 && $_POST['submit'] === 'EDIT')
		{
			if ($_POST['catname'])
			{
				$data[$ok]['catname'] = trim($_POST['catname']);
				file_put_contents("database/category.csv", serialize($data));
			}
			else {
				?>
				<meta http-equiv="refresh" content='0;URL=edit_category.php'/>
				<?php
			}
		}
		else if ($i == 0 && $_POST['submit'] === 'DEL')
		{
			unset($data[$ok]);
			$data = array_values(array_filter($data));
			file_put_contents("database/category.csv", serialize($data));
			echo "OK\n";
		}
		else
			echo "ERROR\n";
}
?>
