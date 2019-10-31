
// renvoyer des gros json, avec number pour le message error et des les fields a retoucher
function getElementsByRegexId(tagParam, regexpParam, manage)
{
	tagParam = (tagParam === undefined) ? "*" : tagParam

	for(var i=0 ; i < document.getElementsByTagName(tagParam).length ; i++)
	{
		if (document.getElementsByTagName(tagParam)[i].id && document.getElementsByTagName(tagParam)[i].id.match(regexpParam))
		{
			if (manage.match("error"))
				document.getElementsByTagName(tagParam)[i].style.background = "red"
			else if (manage.match("normal"))
				document.getElementsByTagName(tagParam)[i].style.background = "white"

		}
	}
}

function check_inscription()
{

	const username = encodeURIComponent(document.getElementById("username").value)
	const psswd = encodeURIComponent(document.getElementById("psswd").value)
	const verifpsswd = encodeURIComponent(document.getElementById("verifpsswd").value)
	const email = encodeURIComponent(document.getElementById("email").value)
	const submit = encodeURIComponent(document.getElementById("button").value)

	console.log("username=", username, "  psswd =", psswd, "  verifpsswd=", verifpsswd, "  email=", email, " submit=", submit)

	getElementsByRegexId("input", "username", "normal")
	getElementsByRegexId("input", "psswd", "normal")
	getElementsByRegexId("input", "verifpsswd", "normal")
	getElementsByRegexId("input", "email", "normal")
	document.getElementById("error").innerHTML = "" //enlever celui-ci

	const xhr = new XMLHttpRequest()
	console.log("registering entree")
	xhr.open("POST", "../function/register.php", true)
	xhr.onreadystatechange = function ()
	{
		console.log("entree dans xhr.onreadystatechange")
		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0))
		{
			console.log("xhr.responseText:", xhr.responseText)

			var response = parseInt(xhr.responseText, 10)
			console.log("type of response:", typeof response)
			if (response == 2)
			{
				console.log("default des champs, response:", response)
				document.getElementById("error").innerHTML = "tout les champs doivent etre remplis"
				getElementsByRegexId("input", "username", "error")
				getElementsByRegexId("input", "psswd", "error")
				getElementsByRegexId("input", "verifpsswd", "error")
				getElementsByRegexId("input", "email", "error")

			}
			if (response == 3)
			{
				document.getElementById("error").innerHTML = ""
				document.location.href="index.php"
				alert("un mail de confirmation vous a ete envoye")
			}
			if (response == 4)
			{
				document.getElementById("error").innerHTML = "Ce pseudo est deja utilise"
				getElementsByRegexId("input", "username", "error")
			}
			if (response == 5)
			{
				document.getElementById("error").innerHTML = "Le pseudo doit etre compris entre 3 et 20 characteres"
				getElementsByRegexId("input", "username", "error")
				//				document.getElementById("username").style.backgroundColor = "red"
			}
			if (response == 6)
			{
				document.getElementById("error").innerHTML = "Les mots de passes ne sont pas identiques"
				getElementsByRegexId("input", "psswd", "error")
				getElementsByRegexId("input", "verifpsswd", "error")
			}
			if (response == 7)
			{
				document.getElementById("error").innerHTML = "Le mot de passe doit etre compris entre 5 et 50 characteres"
				getElementsByRegexId("input", "psswd", "error")
				getElementsByRegexId("input", "verifpsswd", "error")
			}
			if (response == 8)
			{
				document.getElementById("error").innerHTML = "Cette adresse mail est deja utilisee"
				getElementsByRegexId("input", "email", "error")
			}
			if (response == 9)
			{
				document.getElementById("error").innerHTML = "Cette adresse mail n'est pas valide"
				getElementsByRegexId("input", "email", "error")
			}
		}

		console.log("sortie de xhr.onreadystatechange")
	}
	const body = "email="+email+"&username="+username+"&psswd="+psswd+"&verifpsswd="+verifpsswd+"&submit="+submit
	xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded")
	xhr.send(body)
	console.log("sortie")
}
