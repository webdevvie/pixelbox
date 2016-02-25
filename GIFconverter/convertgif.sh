#!/bin/sh
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

BASEPATH=$(dirname $0)
echo $BASEPATH
if [ "$4" = "" ]; then
    echo usage: $0 path/to/sourceimage.gif {loops} {delay} /full/path/to/anim000.src
    echo Please rename the file to the pattern anim%03d.src  like anim001.src and anim000.src
    echo and increase the counter for each new image
    exit 1
fi

mkdir -p $BASEPATH/tmp
rm -f $BASEPATH/tmp/*.png
convert $1  -coalesce -filter Point -distort Resize 16x16 $BASEPATH/tmp/anim000_fr%03d.png
php $BASEPATH/convert-to-pixelboxfile.php 0 $2 $3 $BASEPATH/tmp/ $4
rm -f $BASEPATH/tmp/*.png