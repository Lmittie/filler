# Filler 42

School 42 project.

## Overview

Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops.
The goal is to create the player and be the last who put a piece sent by the VM.

## The Board

A board is a two-dimensional grid with an arbitrary number of rows and columns. To
launch the game an initial board must be passed as an argument to the VM. This initial
board must have a starting form for each player.

![board example](https://github.com/Lmittie/filler/blob/master/examples/plateau.png?raw=true)

![piece example](https://github.com/Lmittie/filler/blob/master/examples/piece.png?raw=true)

## Usage
```
make && make clean
./virtual_machine/filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]

   -t  --time           set timeout in second
   -q  --quiet          quiet mode
   -i  --interactive    interactive mode(default)
   -p1 --player1        use filler binary as a first player
   -p2 --player2        use filler binary as a second player
   -f  --file           use a map file (required)
   -s  --seed           use the seed number (initialization random) (man srand)
```
You can find examples of maps and players in virtual_machine/maps virtual_machine/players folders.

### example
```
make && make clean
./virtual_machine/filler_vm -f virtual_machine/maps/map00 -p1 ./virtual_machine/players/hcao.filler -p2 ./lmittie.filler
```

## Visualization
For visualization usage you should install SDL2 (Mac OC).

```
make -C visual/ && make clean -C visual/
./virtual_machine/filler_vm -f path [-i | -p1 path | -p2 path] | ./visual/visualazier
```
![](https://github.com/Lmittie/filler/blob/master/examples/filler.png?raw=true)
