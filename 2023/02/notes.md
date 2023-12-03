# Part 1

1st idea of the data structure: use hashmaps (unordered are not necessary in this case)

```cpp
games = {
  1 => {[
    ["8 green", "5 green", "6 blue", "1 red"],
    ["2 green", "1 blue", "4 red"],
    ["10 green", "1 red", "2 blue", "3 red"]
  ]},
  2 => {[
    ["10 blue", "12 red"],
    ["8 red"],
    ["7 green", "5 red", "7 blue"],
  ]},
  ...
}
```

Problem: the "red", "green" and "blue" texts are redundants
-> get rid of them and use the pos in the inner arrays to detemine the colour

for instance: here the order is always RGB : Red Green and Blue

```cpp
games = {
  1 => {[
    [1, 13, 6],
    [4, 2, 1],
    [4, 10, 2]
  ]},
  2 => {[
    [12, 0, 10],
    [8, 0, 0],
    [5, 7, 7],
  ]},
  ...
}
```

Now the thing is: while deconstructing the original data to place it in this array, we can already test if one of the numbers is already too big, and detemine if the game is possible or not. No need to build the complete array.  
So the thing to do is just to deconstruct the original data and track count of the nb. of times we have each color