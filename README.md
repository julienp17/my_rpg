## my_rpg

[![pipeline status](https://gitlab.com/julienp17/my_rpg/badges/master/pipeline.svg)](https://gitlab.com/julienp17/my_rpg/commits/master)
[![coverage report](https://gitlab.com/julienp17/my_rpg/badges/master/coverage.svg)](https://gitlab.com/julienp17/my_rpg/commits/master)

### How to make maps
Maps are created with Tiled.
The tile size must be 32x32.
The map size must be between 60x60 and 128x128 tiles.
Create 3 layers in this order:
- collision
- top
- bottom

... and export the map as CSV under assets/maps/*name_of_your_map*/
You must use the same tileset for the top and bottom layer.
When making the collision layer, any tile put means collision.

### How to add musics / fonts
Add your asset under the correct directory in assets/

If you add music, remember that SFML doesn't support mp3. Use other popular formats
such as .ogg or .wav

Then when you have the game structure, to get the asset just do :
> MUSIC(*name_of_the_file_without_extension*)
> FONT(*name_of_the_file_without_extension*)

**Example**
> sfMusic_play(MUSIC("underwater_cave"))
> sfText_setFont(FONT("arial"))


### How to create NPCS
Go to assets/maps/name_of_your_map/

Create a file with the name you want + ".npc" as extension

Add the following information :
- Name of the NPC
- Tile position of the NPC (refer to Tiled for this)
- Sprite rectangle of the NPC from the NPC spritesheet (located at assets/spritesheets/npc_spritesheet.png)
- Text to display when you interact with the NPC for the following lines

**Example**
> Alfred Virgo
> 42 55
> 0 128 32 32
> Hello, my name is Alfred Virgo
> I have travelled the seas
> Just to speak with you

### How to create Warps
Go to assets/maps/*name_of_your_map*/

Create a file with the name you want + ".warp" as extension

Add the following information :
- Name of the map to warp to
- Tile zone where the player should warp from (int rectangle)
- Tile position where the player should appear on the new map

**Example**
> Mount Elfia
> 12 58 2 2
> 12 2

This means if the player is in the zone starting from tile 12 58 to tile 14 60,
teleport him to the "Mount Elfia" map at tile 12 2

### How to modify the starting screen background animation shader
Write your code in assets/shader/interlace.glsl