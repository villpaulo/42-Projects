<?php
session_start();?>
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
		<title>Edit item</title>
		<LINK REL="stylesheet" href="style.css">
	</head>
	<body>
		<?php
		include("is_cat.php");
		if (!file_exists("database/bdd.csv"))
			file_put_contents("database/bdd.csv", "");
		$data = unserialize(file_get_contents("database/bdd.csv"));
		if ($data)
		{
			foreach ($data as $key => $val)
			{
				?>
				<form action="editobj.php" method="post">
					<span class="out">Item: <?php echo $val['item'];?><input type="hidden" name="item" value="<?php echo $val['item'];?>">
					<select name='categorie1' size='1'>
						<?php
						is_cat($val, 'categorie1', 1);?>
					</select>
					<select name='categorie2' size='1'>
					<?php
					is_cat($val, 'categorie2', 1);
					?></select>
					&nbsp;Qantity: <input type="number" name="qte" min="0" value="<?php echo $val['qte'];?>">
					&nbsp;Price (euros): <input type="number" name="prix" min="0.1" step="0.1" value="<?php echo $val['prix'];?>">
					<input type="submit" name="submit" value="EDIT">
					<input type="submit" name="submit" value="DEL"></span><br />
				</form><br />
				<?php
			}
		}
		?><br />
		<form action="addobj.php" method="post">
			<span class="add">Item : <input type="text" name="item">
			<select name='categorie1' size='1'>
				<?php
				is_cat($val, 'categorie1', 0);?>
			</select>
			<select name='categorie2' size='1'>
			<?php
			is_cat($val, 'categorie2', 0);
			?></select>
			&nbsp;Qantity: <input type="number" min="0" name="qte">
			&nbsp;Price (euros): <input type="number" min="0.1" step="0.1" name="prix">
			<input type="submit" name="submit" value="ADD"></span><br />
		</form>
	</body>
</html>
<?php }?>
