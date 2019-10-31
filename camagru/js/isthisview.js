function switch_view($b)
{
	var register = document.getElementById("register")
	var connexion = document.getElementById("connexion")

	if ($b == 1)
	{
		register.style.display = "block"
		connexion.style.display = "none"
	}
	else
	{
		register.style.display = "none"
		connexion.style.display = "block"
	}
}
