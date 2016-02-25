<?php
//    Pixelbox Gif converter
//    Copyright (C) 2016  John Bakker
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

$pattern = "A%03d.SRC";
$nr =0;
$loops = intval($argv[3]);
$delay = intval($argv[4]);
if($loops== 0)
{
    $loops=20;
}
if($delay == 0)
{
    $delay = 10;
}
foreach (glob($argv[1]."*.gif") as $filename) {
    echo "\n$filename size " . filesize($filename) . "\n";
    $command = __DIR__."/convertgif.sh ".$filename." ".$loops." ".$delay." ".$argv[2].sprintf($pattern,$nr);
    //echo "\nExecuting:".$command."\n";
    shell_exec($command);
	$nr++;
}
