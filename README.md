# Pathfinder
A simple Pathfinder using *A algorithm.
It takes a map as single argument.The map must be composed of only 0 and 1 (walls)

exemple:

./Pathfinder map3

11111111111

1xxxxxxxx.1

111111111x1

1.xxxxxxxx1

1x111111111

1.xxxx....1

1.1111x11.1

1......x1.1

1.......x.1

1.......x.1

1........x1

11111111111

path cost is 27:
(1, 1)
(2, 1)
(3, 1)
(4, 1)
(5, 1)
(6, 1)
(7, 1)
(8, 1)
(9, 2)
(9, 3)
(8, 3)
(7, 3)
(6, 3)
(5, 3)
(4, 3)
(3, 3)
(2, 3)
(1, 4)
(2, 5)
(3, 5)
(4, 5)
(5, 5)
(6, 6)
(7, 7)
(8, 8)
(8, 9)
(9, 10)

For the moment it starts at le very first 0 and stops at the last one.
I'll soon add features to set the start and end position on the map using char 'S' and 'E'
