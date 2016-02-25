DIY PIXELBOX
============
This is a project I started after seeing the Gameframe and missing out on the kickstarter.
This project is here for educational purposes only.
This is a simple board, simple code and really nothing at all at the quality of an actual Gameframe!
But maybe a nice project to learn some arduino,electronics and 3d printing!

Making this thing yourself is a nice project. But please buy a gameframe instead! It probably is much better than this DIY thing.
https://ledseq.com/product/game-frame/

So you have been warned. No warranty. You are on your own.
(Besides this readme ofc)

Also: Please don't make these and sell em on ebay... don't be a dick.

THIS IS A WORK IN PROGRESS
==========================

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
See this video: [TODO ADD A VIDEO]

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

[circuit1]: images/circuit1.jpg "The circuit 2"
[circuit2]: images/circuit2.jpg "The circuit 2"


Arduino code
============
Load the code from the `arduino-sourcecode/Pixelbox/Pixelbox.ino` onto your arduino without it attached to the board.

If each line is flipped on your box ,

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


What else?
==========
Put your sd card in the reader. And make sure all your wiring is good. Hook it up to the power supply and watch the glorious pixels do their magic

Liked this project? Or have feedback
====================================

I'm [@webdevvie](http://twitter.com/webdevvie) and reachable at [my site](http://www.johnbakker.name/)

The end
=======



