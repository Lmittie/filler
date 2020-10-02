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

![board example](https://downloader.disk.yandex.ru/preview/a80cc8366cc9d8b82bce1fac03bb8cbaf46dcfb4413eddb437ab53e0e7767279/5f77782a/9eW4rAdDeEt_FwHt2EbAE5YdO3AYTbGm5X43L-K0mwmvRG5K6VxVsI-jK2RF6PV_iJnUZitPYE4QoGzxZoc74w==?uid=0&filename=plateau.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&owner_uid=105167634&size=866x424)

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
For visualization usage you should install SDL2.

```
make -C visual/ && make clean -C visual/
./virtual_machine/filler_vm -f path [-i | -p1 path | -p2 path] | ./visual/visualazier
```
![](https://downloader.disk.yandex.ru/preview/4eee40fb63f2441cda9659d0091c3dcafe036c7760d0595f9607871fa388cd3f/5f777e55/Iov8E-P-z5Wl-6rTPFHU7cCYP2CeX5DzXWtV_yZqrAh6EYkD_vVf9sONFldqxtJ5OC8CdxUB6XkC-zAEbEQCiA==?uid=0&filename=filler.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&tknv=v2&owner_uid=105167634&size=1048x1048)
