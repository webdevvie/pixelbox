<?php

error_reporting(0);

function processAnim($animation,$loops,$delay)
{
    $maxX = 16;
    $maxY = 16;


    $nr = 0;
    $out='';
    $frameFile = sprintf('anim%03d_fr%03d.png', $animation,$nr);
    while (file_exists($frameFile)) {
        $img = @imagecreatefrompng($frameFile);
        for ($y = 0; $y < $maxY; $y++) {
            for ($x = 0; $x < $maxX; $x++) {
                $rgb = imagecolorat($img, $x, $y);
                $r = ($rgb >> 16) & 0xFF;
                $g = ($rgb >> 8) & 0xFF;
                $b = $rgb & 0xFF;
                $out.= chr($r) . chr($g) . chr($b);
            }
        }
        imagedestroy($img);
        $nr++;
        $frameFile = sprintf('anim%03d_fr%03d.png', $animation,$nr);
    }
    $outfile = sprintf('a%03d.src', $animation);
    $fp = fopen($outfile, 'w+');
    fwrite($fp,chr($nr).chr($loops).chr($delay).$out);
    fclose($fp);
}

processAnim(intval($argv[1]),intval($argv[2]),intval($argv[3]));