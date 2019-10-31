<?php
session_start();
if (!file_exists("database")) {?>
	<meta http-equiv="refresh" content="0; url=install.php" />
<?php }
if (file_exists("database")) {
	include ("inc.php");?>
<HTML>
	<HEAD><TITLE>E-CHEAP</TITLE>
		<LINK REL="stylesheet" href="style.css">
	</HEAD>
		<BODY>
			<?php if ($_SESSION['ok']) //a quoi ca sert!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			{?>
			<span class="error"><?php echo $_SESSION['ok'];?></span>
			<?php $_SESSION['ok'] = "";
		}?>
			<BR />
		<CENTER><H1><span class="title"> Welcom to Camagru</span></H1></CENTER>
		</BODY>
</HTML>
<?php }?>
