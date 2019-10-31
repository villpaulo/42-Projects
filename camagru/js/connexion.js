function check_connexion ()
{
	const username = encodeURIComponent(document.getElementById("username").value)
	const psswd = encodeURIComponent(document.getElementById("psswd").value)
	const submit = encodeURIComponent(document.getElementById("button").value)

	const xhr = new XMLHttpRequest()

	xhr.onreadystatechange = function ()
	{
		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0))
		{
			console.log("xhr.responseText=", xhr.responseText)

			if (xhr.responseText == 1)
			{
				document.getElementById("error").innerHTML = "Pseudo ou mot de passe incorrect"
				document.getElementsById("username").style.background = "red"
				document.getElementById("psswd").style.background = "red"
			}
			if (xhr.responseText == 2)
				document.getElementById("error").innerHTML = "desole votre compte n'a pas ete verifie, regarder votre boite mail"
		}

	}
	xhr.open("POST", "../function/connexion.php", true )
	xhr.setRequestHeader("Content-type", "appli-photo")
	xhr.send("&username=" + username + "&psswd=" + psswd + "&submit=" + submit)
}
