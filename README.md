# Pathfinder

A simpe Pathfinder using A algorithm.
It takes a map as single argument.
The map must be composed of:

0 -> crossable
1 -> considered as an obstacle
S -> starting position
E -> ending position

Exemple:

11111111111
1x........1
1x1111111.1
1x........1
1x111111111
1x........1
1x1111111.1
1.xxxx..1.1
111111x.111
1.xxxx....1
1x........1
11111111111

path cost is 16:
(1, 1)
(1, 2)
(1, 3)
(1, 4)
(1, 5)
(1, 6)
(2, 7)
(3, 7)
(4, 7)
(5, 7)
(6, 8)
(5, 9)
(4, 9)
(3, 9)
(2, 9)
(1, 10)

(Run make to build.)
