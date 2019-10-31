<?php
session_start();
if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv")) {
include ('inc.php');
?>
<HTML>
	<HEAD><TITLE>Order History</TITLE>
		<LINK REL="stylesheet" href="style.css">
	</HEAD>
		<BODY>
		<CENTER><H1><span class="title">Order History</span></H1></CENTER>
		<?php
		if ($_SESSION['login'])
		{
			$data = unserialize(file_get_contents("database/account.csv"));
			$i = 1;
			if ($data)
			{
				foreach ($data as $key => $val)
				{
					if ($val['login'] === $_SESSION['login'])
					{
						$i = 0;
						$ok = $key;
					}
				}
				if ($i == 0)
				{
					foreach ($data[$ok]['purchase'] as $key => $val) {
						?><span class="add"><b>Order <?= $key + 1?> :</b></span><br /><br /><?php
						foreach ($val as $val2)
						{?>
							<span class="out"><b>Item: </b><?php echo $val2['item'];?>&nbsp;&nbsp;
							<b>Category 1: </b><?php echo $val2['categorie1'];?>&nbsp;&nbsp;
							<b>Category 2: </b><?php echo $val2['categorie2'];?>&nbsp;&nbsp;
							<b>Qantity: </b><?php echo $val2['qte'];?>
							<b>Price: </b><?php echo $val2['prix'] * $val2['qte'];?> euro(s)&nbsp;&nbsp;</span><br /><br />
							<?php
							$total = $total + ($val2['prix'] * $val2['qte']);
						}?>
						<span class="add"><b>Total: </b><?php echo $total;?> euro(s)</span>&nbsp;<BR /><br /><br />
						<?php
					}
				}
			}
			else
				echo "Vous n'avez jamais commandé.\n";
		}
		else {?>
		<meta http-equiv="refresh" content='0;URL=index.php'/>
		<?php }
	}?>
		</BODY>
</HTML>
