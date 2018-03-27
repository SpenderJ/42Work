<?php
/**
 * Created by PhpStorm.
 * User: juspende
 * Date: 3/27/18
 * Time: 9:33 AM
 */

function epur($str)
{
    $str = trim($str);
    $str = preg_replace('/ +/', ' ', $str);
    return ($str);
}

if (count($argv) != 2) {
    return;
}
else {
    echo (epur($argv[1]));
    echo ("\n");
}
?>
