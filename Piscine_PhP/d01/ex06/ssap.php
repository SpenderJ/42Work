<?php
/**
 * Created by PhpStorm.
 * User: juspende
 * Date: 3/27/18
 * Time: 9:36 AM
 */

function ft_split($str) {
    $str = trim($str);
    $str = preg_replace('/ +/', ' ', $str);
    $array = explode(' ', $str);
    return ($array);
}

$tab = array();
for ($i = 1; $i < count($argv); $i++)
{
    $tmp = ft_split($argv[$i]);
    $tab = array_merge($tab, $tmp);
}
sort($tab, SORT_STRING);
for ($i = 0; $i < count($tab); $i++) {
    echo ($tab[$i] . "\n");
}
?>