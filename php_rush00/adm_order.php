<?php
session_start();
if (!file_exists("database") && !file_exists("database/bdd.csv") && !file_exists("database/account.csv") && !file_exists("database/category.csv")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database") && file_exists("database/bdd.csv") && file_exists("database/account.csv") && file_exists("database/category.csv") && $_SESSION['admin'] == 1) {
	 include ("inc_adm.php"); ?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>History of User's Orders</title>
		<LINK REL="stylesheet" href="style.css">
	</head>
	<body><br />
		<?php
		if ($_SESSION['login'])
		{
			$data = unserialize(file_get_contents("database/account.csv"));
			?><CENTER><H1><span class="title">History of User's Orders</span></H1></CENTER><?php
			if ($data)
			{
				foreach ($data as $key => $val)
				{
					if ($data[$key]['purchase'])
					{
						?><span class="add"><b><?= $val['login']?> :</b></span><br /><br /><?php
						foreach ($data[$key]['purchase'] as $key2 => $val2)
						{
							?><span class="add"><b>Order <?= $key2 + 1?> :</b></span><br /><br /><?php
							foreach ($val2 as $val3)
							{?>
								<span class="out"><b>Item: </b><?php echo $val3['item'];?>&nbsp;&nbsp;
									<b>Category 1: </b><?php echo $val3['categorie1'];?>&nbsp;&nbsp;
									<b>Category 2: </b><?php echo $val3['categorie2'];?>&nbsp;&nbsp;
									<b>Qantity: </b><?php echo $val3['qte'];?>
									<b>Price: </b><?php echo $val3['prix'] * $val3['qte'];?> euro(s)&nbsp;&nbsp;</span><br /><br />
									<?php
									$total = $total + ($val3['prix'] * $val3['qte']);
								}?>
								<span class="add"><b>Total: </b><?php echo $total;?> euro(s)</span>&nbsp;<BR /><br /><br />
								<?php $total = 0;
							}
							?><hr /><?php
						}
					}
				}
				else
				{
						echo "<span class='add'>You never purchase from this website</span>";
				}
			}
		}
	else {?>
		<meta http-equiv="refresh" content='0;URL=index.php'/>
		<?php }?>
	</body>
</html>
