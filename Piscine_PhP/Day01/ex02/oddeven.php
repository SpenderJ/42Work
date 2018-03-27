<?php
/**
 * Created by PhpStorm.
 * User: juspende
 * Date: 3/27/18
 * Time: 8:54 AM
 */

while (true)
{
    echo "Entrez un nombre: ";
    $handle = fopen ("php://stdin","r");
    $line = fgets($handle);
    if ($line == FALSE)
        break;
    $nbr = trim($line);
    if (is_numeric($nbr))
    {
        if ($nbr % 2 == 0) {
            echo ("Le chiffre " . $nbr . " est Pair\n");
        }
        else {
            echo ("Le chiffre " . $nbr . " est Impair\n");
        }
    }
    else {
        echo ("'" . $nbr . "'" . " n'est pas un chiffre\n");
    }
}