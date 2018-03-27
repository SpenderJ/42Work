<?php
/**
 * Created by PhpStorm.
 * User: juspende
 * Date: 3/27/18
 * Time: 10:28 AM
 */

function ft_split($str) {
    $str = trim($str);
    $str = preg_replace('/ +/', ' ', $str);
    $array = explode(' ', $str);
    return ($array);
}

$tab = array();

for($i = 1; $i < count($argv); $i++) {
    $tmp = ft_split($argv[$i]);
    $tab = array_merge($tab, $tmp);
}

$alpha= array();
$other = array();
$numbers = array();

for($i = 0; $i < count($tab); $i++) {
    if (is_numeric($tab[$i]))
        array_push($numbers, $tab[$i]);
    else if (preg_match("/^[A-Za-z]+$/", $tab[$i]))
        array_push($alpha, $tab[$i]);
    else
        array_push($other, $tab[$i]);
}

sort($alpha, SORT_STRING | SORT_FLAG_CASE);
sort($numbers, SORT_STRING | SORT_FLAG_CASE);
sort($other, SORT_STRING | SORT_FLAG_CASE);

for ($i = 0; $i < count($alpha); $i++) {
    echo $alpha[$i]  . "\n";
}
for ($i = 0; $i < count($numbers); $i++) {
    echo $numbers[$i]  . "\n";
}
for ($i = 0; $i < count($other); $i++) {
    echo $other[$i]  . "\n";
}

?>