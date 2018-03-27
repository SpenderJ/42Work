<?php
/**
 * Created by PhpStorm.
 * User: juspende
 * Date: 3/27/18
 * Time: 9:05 AM
 */

function ft_split($str) {
    $str = trim($str);
    $str = preg_replace('/ +/', ' ', $str);
    $array = explode(' ', $str);
    sort($array, SORT_STRING);
    return ($array);
}
?>