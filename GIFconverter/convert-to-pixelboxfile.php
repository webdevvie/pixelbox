<?php
#    Pixelbox GIF converter
#    Copyright (C) 2016  John Bakker
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.


function processAnim($animation, $loops, $delay, $sourcepath, $outfile)
{
    $maxX = 16;
    $maxY = 16;


    $nr = 0;
    $out = '';
    $frameFile = sprintf('anim%03d_fr%03d.png', $animation, $nr);
    while (file_exists($sourcepath . $frameFile)) {
        //echo "\n";
        $img = @imagecreatefrompng($sourcepath . $frameFile);
        for ($y = 0; $y < $maxY; $y++) {
            for ($x = 0; $x < $maxX; $x++) {
                $rgb = imagecolorat($img, $x, $y);
                $colors = imagecolorsforindex($img, $rgb);
                $out .= chr($colors['red']) . chr($colors['green']) . chr($colors['blue']);

                //echo sprintf("%03d",$colors['red']);
            }
            //echo "\n";
        }
        imagedestroy($img);
        $nr++;
        $frameFile = sprintf('anim%03d_fr%03d.png', $animation, $nr);
    }
    $outfile = sprintf($outfile, $animation);
    $fp = fopen($outfile, 'w+');
    fwrite($fp, chr($nr) . chr($loops) . chr($delay) . $out);
    fclose($fp);
}

processAnim(intval($argv[1]), intval($argv[2]), intval($argv[3]), $argv[4], $argv[5]);