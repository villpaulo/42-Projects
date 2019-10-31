<?php
function is_cat($val, $str, $i)
{
	$cat = unserialize(file_get_contents("database/category.csv"));
	foreach ($cat as $val2)
	{
		if ($val[$str] === $val2['catname'] && $i == 1)
		{
			echo "<option selected value=".$val[$str].">".$val[$str]."</option>";
		}
		else
		{
			echo "<option value=".$val2['catname'].">".$val2['catname']."</option>";
		}
	}
}
?>
