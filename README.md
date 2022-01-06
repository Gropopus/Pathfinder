# Pathfinder
A pathfinder using A* algorithm

Run make to build the project then run ./Pathfinder -d (optional to allow diagonal search) file.map

Rules for the map:
- '0' is considered as a floor tile.
- '1' is considered as a wall tile.
- 'S' is the starting position. There must be only one.
- 'E' is the goal posiotion to reach. There must be only one too.
- Any other character makes the map considered as invalid.
- The map must be closed and a rectangle.
- The map must end with the extension ".map"
