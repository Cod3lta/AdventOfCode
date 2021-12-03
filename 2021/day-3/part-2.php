<?php

// get puzzle input
$file = fopen("data.txt", "r");
$data = explode("\n", fread($file, filesize("data.txt")));
fclose($file);

// init the criterias
$criterias = [
    "oxy" => [
        "data" => $data,
        "number" => 1,
    ],
    "co2" => [
        "data" => $data,
        "number" => 0,
    ]
];


// For each bit
for ($i = 0; $i < strlen($data[0]); $i++) {
    // For each criteria
    foreach ($criterias as $key => $crt) {
        // If we're already at 1 final answer, we continue
        if (count($crt['data']) == 1) continue;

        // Sum the nth bit of each line
        $sum = 0;
        foreach ($crt['data'] as $line) {
            $sum += intval($line[$i]);
        }
        $moreOnes = $sum > sizeof($crt['data']) / 2;
        $equals1And0 = $sum == sizeof($crt['data']) / 2;

        // Filter the array to keep only the lines we want
        $criterias[$key]['data'] = array_filter($crt['data'], function ($line) use (
            $moreOnes, $equals1And0, $crt, $i) {
            if ($equals1And0) { // If we have the same amount of 0s and 1s
                // We return true if the current bit == the bit of the criteria
                return $line[$i] == $crt['number'];
            }
            return ($line[$i] == $crt['number']) == $moreOnes;
        });
    }
}

$answer = (
    bindec(reset($criterias['oxy']['data']))
     * 
    bindec(reset($criterias['co2']['data']))
);

echo $answer;