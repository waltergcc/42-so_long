# so_long

The **so_long** project is a simple 2D game developed in C using the MiniLibX graphics library. The goal of the game is to guide a character through a maze, collecting items along the way and avoiding obstacles. The player must complete the game with the fewest number of moves possible.

## Prerequisites
Before compiling and running the project, make sure you have the MiniLibX installed in project folder. For that, after cloning, it's necessary to extract the contents of the `minilibx-Linux.tgz` file, rename the folder with the name `mlx`, and copy and paste this in the folder `lib`.

## Compilation
To compile the project, run:
```shell
make
```
This will compile the source files and generate the `so_long` executable.

## Execution
After compilation, you can run the game using the following command:

```shell
./so_long <map>
```

Replace `<map>` with the path to the map file you want to use. The map file should have the `.ber` extension and follow the format specified in the project. Inside the `assets/maps` folder there are some examples of valid and invalid maps.

## Game Rules
- The player starts at an initial position marked by a character.
- The goal is to collect all the items represented by collectibles (`C`) on the map.
- The player must avoid obstacles represented by walls (`1`) and enemies (`E`).
- The player can move in the up, down, left, and right directions using the arrow keys.
- The game ends when the player collects all the items and returns to the initial position or is captured by an enemy.
- The number of moves made by the player is displayed in the game window.

## Controls
- `W`, `S`, `D`, `A` and `Arrow keys`: move the character in the up, down, left, and right directions.
- `ESC` key: exit the game.

## Sprites
The sprites used in the game were created by me using the GIMP application. Here a small tutorial on how to create sprites using GIMP: https://thegimptutorials.com/how-to-make-pixel-art/.
If you want to use the sprites that I created, or modify them, you can use the sprites.xcf file.

## Grade: 100/100

## Used tests
so_long_invalidator: https://github.com/Nuno-Jesus/so_long_invalidator

