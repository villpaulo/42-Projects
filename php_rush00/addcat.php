<?php
header('Location: edit_category.php');
session_start();
if ($_SESSION['admin'] == 1)
{
$data = unserialize(file_get_contents("database/category.csv"));
$i = 1;
$ok = 0;
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				if ($val['catname'] === $_POST['catname'])
				{
					$i = 0;
				}
				$ok = $key + 1;
			}
		}
		if ($i != 0)
		{
			if (trim($_POST['catname']))
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
		else
			echo "ERROR\n";
}
?>
