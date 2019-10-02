# solvemaze
Maze program in C++ which takes a text file with the dimensions (max 99 by 99) and solves the maze showing you the paths taken.
Maze input file must be accurate to the size and contain only certain characters representing parts of the maze. Solution made my using Stacks, Linked Lists, and other dynamic memory techniques.

File must have the two numbers for the the size at the top seperated by a single space. First width, second height.

Character List:
- 'G' : Goal of the maze
- '.' : Paths of the maze which you can travel to
- 'S' : Start of the maze
- '#' : Represents walls of the maze, places you can not travel to

Maze file can not be more than 99 by 99.
Examples of maze text files and their final outputs will be displayed.

Main File is arraytest.cpp
When compiling, must include LinkedList.cpp stack.cpp

ex: 

g++ arraytest.cpp LinkedList.cpp stack.cpp

input text file into  arraytest.cpp in the first part of the readfile() function.
