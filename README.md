# Peckham_CSCI2270_FinalProject
CSCI2270 FinalProject 2016

Made by: Andrew Peckham (Andrew.Peckham@colorado.edu)

##Discription
My project is a Minesweeper game. It uses an old school text format to display the board, prompt input, and receive input.

##Requirements to:
###Compile:
-  C++ 11,
-  iostream,
-  vector,
-  random,
###Run:
  Writen and tested on Windows 10, but should run on any OS. 

##How to Run
Place all files in one folder (normal folder, not a .zip or other fancy folder) and compile following your compiler's standard methods. After compile, it is recomended to run the file from command line or equivilant. Wait until the main menu has finised printing. You should now see the game board follwed by the main menu. In the following explanations, x is always column number and y is always row number. The top left corner is (0,0).
###Menu Options
####1. Flag Space
This option requests x and y cordinates and uses those to flag a square the player guesses has a bomb.

####2. Select Space
This option requests x and y cordinates and uses those to check that square for a mine. If that square is a mine then the game ends and a new one starts(see Menu option 4). If no mine is found then a number will show how many neighboring squares have a mine. If there are no mines next to a square then it will be blank and reveal all squares next to it following the same discription.
####3. Reprint Board
This option will reprint the board.
####4. New Game
This option will end the current game and start a new game. You will be asked for how many rows the board will have, how many columns the game will have, and how many mines the game will have.

##Known Bugs
-Memory leak when creating a new game
-Stability problems beyond 900 squares (30x30) (May be computer dependent)
-Stability problems beyond 20 mines (May be computer dependent)
-select space function doesn't always chain.

##Desired improvements include:
1. a grid that doesn't shift around that also has lables for rows and columns
2. making sure first move is not a bomb
3. fixing the memory leak
4. fixing all spelling errors
5. telling player when they have won


