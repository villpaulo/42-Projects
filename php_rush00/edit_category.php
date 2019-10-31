<?php session_start(); ?>
<!DOCTYPE html>
<?php
if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv") && $_SESSION['admin'] == 1) {
	include("inc_adm.php"); ?>
<html>
	<head>
		<meta charset="utf-8">
		<title>Edit category</title>
		<LINK REL="stylesheet" href="style.css">
	</head>
	<body>
		<?php
		if (!file_exists("database/category.csv"))
			file_put_contents("database/category.csv", "");
		$data = unserialize(file_get_contents("database/category.csv"));
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				?>
				<form action="editcat.php" method="post">
					<span class="out">Category name: <input type="text" name="catname" value="<?php echo $val['catname'];?>">
					<input type="submit" name="submit" value="EDIT">
					<input type="submit" name="submit" value="DEL"></span>
				</form><br />
				<?php
			}
		}
		?><br />
		<form action="addcat.php" method="post">
			<span class="add">Category name: <input type="text" name="catname" value="">
			<input type="submit" name="submit" value="ADD"></span><br />
		</form>
	</body>
</html>
<?php } ?>
