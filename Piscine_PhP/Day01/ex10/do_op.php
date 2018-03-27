<?php
/**
 * Created by PhpStorm.
 * User: juspende
 * Date: 3/27/18
 * Time: 11:06 AM
 */

if (count($argv) != 4) {
    echo "Invalid Parameters\n";
    return ;
}

$a = trim($argv[1]);
$b = trim($argv[2]);
$c = trim($argv[3]);
if ($b == '+')
    echo $a + $c;
else if ($b == '-')
    echo $a - $c;
else if ($b == '*')
    echo $a * cd
$c;
else if ($b == '/')
    echo $a / $c;
else if ($b == '%')
    echo $a % $c;
echo "\n";

?>