<?php
session_start();
if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv")) {
	 include ("inc.php"); ?>
<!DOCTYPE html>
<HTML>
	<HEAD><TITLE>Basket</TITLE>
		<LINK REL="stylesheet" href="style.css">
	</HEAD>
		<BODY>
			<?php if ($_SESSION['ok'])
			{?>
			<span class="error"><?php echo $_SESSION['ok'];?></span>
			<?php $_SESSION['ok'] = "";
		}?>
			<br />
		<CENTER><H1><span class="title">Basket</span></H1></CENTER>
		<?php
		if ($_SESSION['basket'])
		{
			foreach ($_SESSION['basket'] as $val)
			{?>
				<form action="editpanier.php" method="post">
					<span class="out"><b>Item: </b><?php echo $val['item'];?><input type="hidden" name="item" value=<?php echo $val['item'];?>>&nbsp;&nbsp;
					<b>Qantity: </b><input type="number" name="qte" min="0" max="<?php echo $val['stock'];?>" value="<?php echo $val['qte'];?>">
					<b>Price: </b><?php echo $val['prix'] * $val['qte'];?>&nbsp;euro(s)&nbsp;
					<input type="submit" name="submit" value="EDIT">
					<input type="submit" name="submit" value="DEL"></span><br /><br />
				</form>
				<?php
				$total = $total + ($val['prix'] * $val['qte']);
			}?>
			<BR /><span class='add'><b>Total: </b><?php echo $total;?>&nbsp;euro(s)</span><BR /><BR />
			<?php
			if ($_SESSION['login'])
			{?>
				<form action="buy.php" method="post">
					<input type="submit" name="submit" value="BUY">
				</form>
				<?php
			}
		}
		else
			echo "<span class='add'>Your basket is empty.</span>";
		?>
		</BODY>
</HTML>
<?php }?>
