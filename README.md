## my_rpg

[![pipeline status](https://gitlab.com/julienp17/my_rpg/badges/master/pipeline.svg)](https://gitlab.com/julienp17/my_rpg/commits/master)
[![coverage report](https://gitlab.com/julienp17/my_rpg/badges/master/coverage.svg)](https://gitlab.com/julienp17/my_rpg/commits/master)

The time base used is milliseconds.
If you want to add music, remember that SFML doesn't support mp3. Rather use ogg or wav files.

### Making custom maps
Maps are created with Tiled.
The tile size must be 32x32.
The map size must be between 60x60 and 128x128 tiles.
Create 3 layers :
- object
- top
- bottom

... and export the map as CSV under assets/maps/
You must use the same tileset for the top AND bottom layer.
When making the object layer, leave empty for no collision and any tile for collision.