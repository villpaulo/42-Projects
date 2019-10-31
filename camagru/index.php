<?php
session_start();
?>

<!DOCTYPE html>
<html>
<head>
	<link href="style/index.css" rel="stylesheet">
	<meta charset="utf-8">
	<title>Camagru</title>
</head>
<body>
	<header>
		<h1>Camagru</h1>
	</header>
<?php
if (isset($_SESSION['username']))
	include("header.php")
?>

<div>
		<div id = register style = "display : none">
		<h3> Registering </h3>
		<label> UserName </label> <br/ >
		<input id = "username" class = "auth" type = "text" value="" > <br/> <br/>
		 <label> PassWord </label> <br/ >
		<input id = "psswd" class = "auth" type = "text" value="" > <br/> <br/>
		<label> Repeat PassWord <label> <br/ >
		<input id = "verifpsswd" class = "auth" type = "text" > <br /> <br />
		<label> email </label> <br/ >
		<input id = "email" class = "auth" type = "email" > <br/ > <br/>
		<input id = "button" class = "auth" type = "submit" onclick="check_inscription()"> <br /> <br />
		<div id = "error" style="color: red"> </div>
		<p> Vous avez deja un compte ? <br/> <a href="#" onclick="switch_view(0)" > connectez vous <a/> </p>
		</div>

</div>

<div>
		<div id = connexion style = "display : block">
		<h3> Connexion </h3>
		<label> UserName </label>
		<input id = "username" class = "auth" type = "text" value="" > <br/ > <br />
		<label> PassWord </label>
		<input id = "psswd" class = "auth" type = "text" value="" > <br /> <br />
		<input id="button" class="auth" type ="submit" onclick="check_connexion()">
		<div id = "error" style="color: red"> </div>
		<p> vous n'avez pas encore de compte ? <br/> <a href="#" onclick="switch_view(1)" > Inscrivez vous <a/> </p>
		</div>

<?php
	if ($_SESSION['error'] != null)
		echo($_SESSION['error']);
$_SESSION['error'] = null;
if (isset($_SESSION['username']))
	echo("Welcome ". $_SESSION['username']);
/*else if (isset($_SESSION['signup_success']))
{
	if ($_SESSION['signup_success'] != null)
		echo($_SESSION['signup_success']);
	$_SESSION['signup_success'] = null;
}*/
else if ($_SESSION['signup_success'])
{
	echo $_SESSION['signup_success'];
}
$_SESSION['signup_success'] = null;
?>

	<br/>
<script src = "./js/registering.js" > </script>
<script src= "./js/connexion.js" > </script>
<script src= "./js/isthisview.js" > </script>
</body>
</html>
