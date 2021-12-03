<?php

// get puzzle input
$file = fopen("data.txt", "r");
$data = explode("\n", fread($file, filesize("data.txt")));
fclose($file);

$gammaRate = "";
$epsilonRate = "";

// For each bit of a line
for ($i = 0; $i < strlen($data[0]); $i++) {
    $sum = 0;

    // Sum the numbers
    foreach ($data as $line) {
        $sum += intval($line[$i]);
    }

    // If the sum is greater than 500 -> append 1 to gammaRate
    if ($sum > sizeof($data) / 2) {
        $gammaRate .= "1";
    } else {
        $gammaRate .= "0";
    }
}

// set epsilon rate by inverting the bits of gammaRate
$epsilonRate = strtr($gammaRate,[1,0]);

echo bindec($gammaRate) * bindec($epsilonRate);

?>