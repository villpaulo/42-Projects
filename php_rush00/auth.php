<?php
function auth($login, $passwd)
{
	if (file_exists("database") && file_exists("database/account.csv"))
	{
		$data = unserialize(file_get_contents("database/account.csv"));
		if ($data)
		{
			foreach ($data as $val)
			{
				if ($val['login'] === $login && $val['passwd'] === hash(whirlpool, $passwd))
					return (true);
			}
		}
	}
	return (false);
}
?>
