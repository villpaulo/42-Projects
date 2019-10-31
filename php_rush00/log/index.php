<?php
session_start();
if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv")) {
	include ("inc.php");?>
<HTML>
	<HEAD><TITLE>E-CHEAP</TITLE>
		<LINK REL="stylesheet" href="style.css">
	</HEAD>
		<BODY>
			<?php if ($_SESSION['ok'])
			{?>
			<span class="error"><?php echo $_SESSION['ok'];?></span>
			<?php $_SESSION['ok'] = "";
		}?>
			<BR />
		<CENTER><H1><span class="title">Available Items</span></H1></CENTER>
		<?php
		if (!$_POST)
		{
			$what = 1;
		}
		if (!file_exists("database/bdd.csv"))
			file_put_contents("database/bdd.csv", "");
		$data = unserialize(file_get_contents("database/bdd.csv"));
		?>
				<form action="index.php" method="post">
					<select name='categorie1' size='1'>
						<?php
						$cat = unserialize(file_get_contents("database/category.csv"));
						$i = 0;
						foreach ($cat as $key =>$val2)
						{
							if ($_POST['categorie1'] === $val2['catname'])
							{
								echo "<option selected value=".$_POST['categorie1'].">".$_POST['categorie1']."</option>";
								$ok = $key;
							}
							else
							{
								echo "<option value=".$val2['catname'].">".$val2['catname']."</option>";
							}
						}
						?>
					</select>
				<input type="submit" value="list" name="<?= $ok ?>"></form>
				</form>
​
		<?php
		$file = "database/bdd.csv";
		if (!file_exists("database/bdd.csv"))
			file_put_contents("database/bdd.csv", "");
		$data = unserialize(file_get_contents("database/bdd.csv"));
		if ($data)
		{
			if ($_POST['categorie1'] === 'All')
				$what = 1;
			foreach ($data as $key => $val) {
				if ($what === 1 OR $_POST['categorie1'] === $val['categorie1'] OR $_POST['categorie1'] === $val['categorie2'])
				{
					if ($data[$key]['qte'] > 0)
					{
						?>
						<secion><H2><span class="add"><?php echo $val['item'];?></span></H2>
							<span class="out"><b>Category 1: </b><?php echo $val['categorie1'];?>&nbsp;&nbsp;
							<b>Category 2: </b><?php echo $val['categorie2'];?>&nbsp;&nbsp;
							<b>Stock available: </b><?php echo $val['qte'];?>&nbsp;&nbsp;
							<b>Price:  </b><?php echo $val['prix'];?> euro(s)</span>
							​
						<FORM ACTION='echoitem.php' METHOD='post'>
							<BR />
						<INPUT TYPE='hidden' NAME='prix' value=<?php echo $val['prix'];?>>
						<INPUT TYPE='hidden' NAME='categorie1' value=<?php echo $val['categorie1'];?>>
						<INPUT TYPE='hidden' NAME='categorie2' value=<?php echo $val['categorie2'];?>>
						<INPUT TYPE='hidden' NAME='qte' value=<?php echo $val['qte'];?>>
						<INPUT TYPE='number' NAME='howmuch' step='1' min="0" max=<?php echo $val['qte'];?> value=''>&nbsp;&nbsp;
						<input class="basket" border=0 src='img/basket.jpg' title='ajouter au panier' type='image' value=<?php echo $val['item'];?> name='item'></img>
						</FORM>
						<?php
					}
				}
			}
		}
		?>
		</BODY>
</HTML>
<?php }?>
