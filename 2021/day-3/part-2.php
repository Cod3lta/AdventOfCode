<?php

// get puzzle input
$file = fopen("data.txt", "r");
$data = explode("\n", fread($file, filesize("data.txt")));
fclose($file);

// init the criterias
$criterias = [
    "oxy" => [
        "data" => $data,
        "prefferedBit" => 1,
    ],
    "co2" => [
        "data" => $data,
        "prefferedBit" => 0,
    ]
];

function filterCrt($line) {
    global $sum, $mostCommonBit, $i, $crt;
    // If we have the same amount of 0s and 1s
    if ($sum == sizeof($crt['data']) / 2)
        // We return true if the current bit == the bit of the criteria
        return $line[$i] == $crt['prefferedBit'];
    return ($line[$i] == $crt['prefferedBit']) == $mostCommonBit;
};

function reduceCrt($sum, $line) {
    global $i;
    return $sum += intval($line[$i]);
};

// For each bit
for ($i = 0; $i < strlen($data[0]); $i++) {
    // For each criteria
    foreach ($criterias as $key => $crt) {
        if (count($crt['data']) == 1) break;
        $sum = array_reduce($crt['data'], "reduceCrt", 0);
        $mostCommonBit = $sum > sizeof($crt['data']) / 2;
        $criterias[$key]['data'] = array_filter($crt['data'], "filterCrt");
    }
};

$answer = (bindec(reset($criterias['oxy']['data']))
    *
    bindec(reset($criterias['co2']['data'])));

echo $answer;