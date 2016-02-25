Pixelbox
========
Copyright (C) 2016  John Bakker

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

I'm [@webdevvie](http://twitter.com/webdevvie) on twitter and also reachable at [my site](http://www.johnbakker.name/)

DIY PIXELBOX
============

![Everything hooked up][pixelbox]

This is a project I started after seeing the Gameframe and missing out on the kickstarter.
This project is here for educational purposes only.
This is a simple board, simple code and really nothing at all at the quality of an actual Gameframe!
But maybe a nice project to learn some arduino,electronics and 3d printing!

Making this thing yourself is a nice project.

But please buy a gameframe instead! It is much better looking than this DIY thing and it has more features.
https://ledseq.com/product/game-frame/

So you have been warned. No warranty. You are on your own.
(Besides this readme.md ofc)

Also: Please don't make these and sell em on ebay... don't be a dick.

All the code, circuit design, and arduinocode in this project have been made by me.
I used some examples by Adafruit and other Arduino samples to learn how to read the SD card.
If you change the code,designs please be sure to submit a pull request of your fork.

THIS IS A WORK IN PROGRESS
==========================


Features
========

- Display animations taken from animated gifs taken from the internets.
- Toggle between animations using the buttons
- Use one button to switch between animations and the other to pause the skipping to the next into a manual skip mode.



Parts
=====
You will need to go gather some parts

Electronics
----------
 - Arduino pro mini for the board (or compatible substitute)
 - Sd card
 - sd card reader (Adafruit's sd card reader great) https://www.adafruit.com/product/254
 - A perma proto board
 - Solder
 - Soldering skills
 - flat cable wire
 - A capacitor (1000μf 10v)
 - a 16x16 5v WS2812B (neopixel like) grid of ebay for $50-$120 (16x16 WS2812B RGB LED Matrix Panel, 256 Individually Addressable Pixels, 5v)
 - Pins
 - Wire plug crimper and plugs
 - arduino headers
 - FTDI serial connector to program the arduino pro mini
 - a 3A 5v power supply
 - 2 buttons that fit the 3d printed parts
 - 1 resistor 220 ohm
 - 1 barrel jack for the power supply

The enclosure
-------------

You must print the 3d printed parts (see chapter on 3d printing below)

You will also require these things:
 - Screws and bolts (M4 worked for me)
 - Acrylic glass
 - A drill
 - Acrylic cutter
 - a4 or letter size paper to diffuse the light



3d printing
===========

There are two options:

Print the outside in small parts
--------------------------------
This is handy when printing with ABS, since it has a habbit of warping.
Print all the parts in the `3d-print/16x16/Outside/Small_parts` directory in the following quantities.
- `corner_with_wirespacer.stl` (4x)
- `side.stl` (5x or 6x depending if you wanna use the power hole on one side)
- `side_with_button_hole.stl` (2x)
- `side_with_power_hole` (0x or 1x depending if you wanna use the power hole on one side)

if you use abs you can use acetone to merge the parts.

Print the outside in two large parts
------------------------------------
Print the parts in : `3d-print/16x16/Outside/Large_parts`.(USE PLA!)
Glue them together. and presto your outside is done.


The grid
--------
For the grid there is just one option
Print `3d-print/16x16/Grid/grid-160x80mm-sp.stl` two times with 100% infill. I advise printing in PLA as that will prevent warping.
Leave it on the bed a bit if you use a heated bed until it is completely cooled.

Grid pressurer
--------------
To keep the grid against the pixels to prevent light leakage print the part:

`3d-print/16x16/Outside/Behind-pressure/behind-pressure.stl`

I suggest using PLA. as these are large (17x17cm)

Feet
----
To keep the box upright you may want to print some feet :

`3d-print/16x16/Feet/foot.stl`

print this one twice. You need to drill a hole to fit your screws




Soldering the circuitboard
==========================

See Circuitboard design below. I will record a video to go over the circuitboard soon and put it here.

 - Put the headers and pins like shown in the Circuitboard chapter below)
 - Link the data pin of the grid to pin 6 of the arduino
 - Link the button pins on one end to ground and the second button ground with a resistor (220ohm)
 - On the other end link both buttons to pin A1
 - Link pins 10,11,12,13 to the sd card reader
 - Hook up the 5v from the source power rail to the arduino's VIN
 - Hook up the ground and 5v from the arduino's VCC and ground to the other power rail
 - Put the capacitor in paralel on the source power rail (this is to prevent damaging the grid
 - Hook the source power rail to the appropriate pins on the 16x16 pixel grid.
 - Hook up the barrel jack to the appropriate rail (ground,5v)


Circuitboard design
-------------------
You can see some photos of my circuitboard here:

![Without the removable parts][circuit1]

![Everything hooked up][circuit2]




Arduino code
============
Load the code from the `arduino-sourcecode/Pixelbox/Pixelbox.ino` onto your arduino without it attached to the board.

If each line is flipped on your box. You might have a different pixel grid than i have. In the sourcecode change this:

`byte mode = 1;`

to

`byte mode = 0;`


Putting it together
===================
Before putting it together, test the circuitry. See if the pixels light up correctly.

Cut 2 pieces of Acrylic glass exactly the size of the box. Leave the protective plastic on. this will prevent scratches  Drill holes in the pieces the same spots they are on the box. (the 4 corners)

Put the 4 screws in the first sheet of acrylic , leave the outside piece of protective plastic on, but remove the back piece.

Cut a piece of paper exactly the same size as the acrylic.
Put holes in the same spots as the acrylic, and slide it over the screws onto the acrylic.

Now put the outside parts (glued) together.

Put in the buttons, (Which you should have already soldered to wires and plug to) and hotglue them to the frame.

Remove any droops and wires of the hot glue before proceeding.

Put the outside frame over the screws and make sure it is a snug fit. Remove any inperfections causing a bad fit.

Cut the circular pieces off the printed 16x16 grid. file or sand them down if if you have to. You can try glueing them.
But they should just fit inside the box against the paper.
Make sure you have the smooth side (from the kapton tape) down on the paper.

Grab your neopixel grid, and decide which side is up. Put the input wire on that side top left corner (looking from the back)
and let the grid fall into place.

Now put together the backside pressure parts (They should fit together using the holes in the pieces) and put the single piece pointing up to the buttons.

Now , drill some holes big enough for the connectors of the pixel grid and the buttons to pass through into the back acrylic.

Remove both sides of the
Use some double sided tape or other means to attach the board to the back of the acrylic with the holes.
Or drill holes in the acrylic and use screws in the permaproto board.
Make sure it is in a place where there is enough space for the power supply connector and not too far from the grid & button connectors.

Put the back acrylic piece with the board on the back end.

Put on the nuts and tighten them. Put the stands on the bottom screws (After drilling holes in the stands where the screws fit.)

Hook up your sd card filled with animations, and the power supply.

Now it has turned on it is displaying a wonderful animation. YAY!

Use the buttons to either fix on a single animation or switch to the next animation.

Alternate version
-----------------
You can also try fitting the electronics in a smaller permaproto board.then put it inside the space between the back pressure parts.
This will however prevent you from taking the expensiver parts off the board for an upgraded version later...

Image converter
===============
Ofcourse you want to put some animations on there.

Requirements:
-------------
- Mac or Linux
- PHP 5.4 (Tested with 5.6, but should work fine with php5.4)
- Imagemagick  (on mac install it with homebrew: brew install imagemagick )

Usage converting gifs:
----------------------
If you want to convert some gifs to the format the DIY pixelbox reads use this guide.

Put your gifs in a directory. For example ~/Desktop/myawesomegifs/.
Make a directory to store the converted gifs. ~/Desktop/forpixelbox/

Open a terminal window and change directory to the directory this repo is in.
Run the following (using some example locations) :

`php GIFconverter/convertgifs.php ~/Desktop/myawesomegifs/ ~/Desktop/forpixelbox/`

(make sure the final slashes are there)

Put them on your sd card (see below "Putting the files on the SD card")

There are two final arguments for the script. Loops and Delay. See the following chapter about what they mean.
By default it will use 20 loops and 100ms between frames

Usage to convert loose png files
--------------------------------
This is a bit more tricky but these will have a lot better quality than gifs.

Place your 16x16 pixel png files in a directory. Name them like so:

`anim000_000.png`
`anim000_001.png`
`anim000_002.png`
`anim000_003.png`

Run this command:

`php GIFconverter/convert-to-pixelboxfile.php 0 <loops> <delay> source/directory/ A000.SRC`

 - Delay: This is in 10ms (so take the delay between frames in MS and divide it by 10 and round to whole numbers)
 - Loops: The loop count of the animation

Putting the files on the SD card
--------------------------------
Make sure the sd card is formatted MS-DOS FAT16

Name the files like this:

`A000.SRC`

`A001.SRC`

etc.

Put them in the root dir of the sd card.

Be sure to clear the sd card of osx bull poop.

Go to the sd card mount point ( On mac this is /Volumes/SDCARDNAMEHERE/ ) and run :

`cd /Volumes/SDCARDNAMEHERE/`

`rm -fr .Spotlight-V100/ .Trashes/ ._.Trashes .fseventsd`

to clear out stuff osx puts there.

(this is important!)


Sample images
=============
You can take the sample_sd directory and put its contents on the SD card. These will work

What else?
==========
Put your sd card in the reader. And make sure all your wiring is good. Hook it up to the power supply and watch the glorious pixels do their magic

Liked this project? Or have feedback
====================================

I'm [@webdevvie](http://twitter.com/webdevvie) on twitter and also reachable at [my site](http://www.johnbakker.name/)




[pixelbox]: docimages/pixelbox.jpg "The pixelbox"
[circuit1]: docimages/circuit1.jpg "The circuit 2"
[circuit2]: docimages/circuit2.jpg "The circuit 2"