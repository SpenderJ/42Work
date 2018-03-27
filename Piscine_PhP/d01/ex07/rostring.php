<?php
/**
 * Created by PhpStorm.
 * User: juspende
 * Date: 3/27/18
 * Time: 10:09 AM
 */

function ft_split($str) {
    $str = trim($str);
    $str = preg_replace('/ +/', ' ', $str);
    $array = explode(' ', $str);
    return ($array);
}

if (count($argv) < 2) {
    return;
}
$tab = ft_split($argv[1]);
for ($i = 1; count($tab) > $i; $i++) {
    echo $tab[$i] . " ";
}
if (count($tab) >= 1) {
    echo $tab[0];
}
echo "\n";
?>
