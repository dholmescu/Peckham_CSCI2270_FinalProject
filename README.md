# Peckham_CSCI2270_FinalProject
CSCI2270 FinalProject 2016
Made by: Andrew Peckham

My project is a Minesweeper game. 
##Desired improvements include:
1. a grid that doesn't shift around with numbers for rows and columns
2. making sure first move is not a bomb
3. fixing the memory leak
4. fixing all spelling errors

##Requirements:
  C++ 11,
  iostream,
  vector,
  random,

##Minesweeper.h
Minesweeper.h is the only header file. Definitions are in Minesweeper.cpp.
Minesweeper.h includes 4 structs and 1 class
###Structs:
####possibility:
    created to represent the data for one square on the board.
#####contains:
      char symbol
        the symbol representing that square on the map
      bool mine
        does or does not contain a mine
      int nearby
        number of mines in neighboring squares
    no constructor built in
####rows:
    created to represent each row
    not actually needed, was created incase reveiwer(s) don't understand 2D vectors
#####contains:
      row:
        vector of possibility structs
      no constructor built in
####minefeild:
    created to be the 2D minesweeper board
#####contains:
      board:
       vector of rows structs
####cords:
    created to pass x,y cordinates
#####contains:
      int x
      int y
#####two constructors:
      cords()
        does nothing special
        (default)
      cords(int xin, int yin)
        xin sets the value of x in the struct
        yin sets the value of y in the struct
        
###Class:
####MineSweeperGame
#####two constructors
        MineSweeperGame(int rows, int collums, int mines)
          builds game with a board (rows) tall and (collums) wide containing (mines) mines
        MineSweeperGame()
          requests number of rows, number of columns, and number of mines then uses those to build a game as above
#####one destructor
        ~MineSweeperGame()
          contains no code
#####public:
######void flagsquare(int x,int y)
          changes (symbol) in square x,y to X
######void cheaksquare(int x,int y)
		if square is flagged
			prints "square flagged" 
			exits
		if you select a mine
			calls private method GameOver() 
		        exits
		if the value of (nearby) for that square is 0 and is symbol is 'O'
		        makes that squares (symbol) ' '
		        recursively calls itself for neighboring squares
		if above are all false
		        (symbol) becomes the number stored in nearby
		        	uses '0' plus number method
######void printBoard()
		      prints the board
######cords requestcords()
	  	    requests x and y
	  	      will output request to retry if input is invalid
######void showall()
	  	    sets all symbols 
######bool active
	  	    designated if the game is active
#####private:
######minefeild* activeBoard
	  	    the current board
######int activerows
	  	    current number of rows
######int activecollums
	  	    current number of columns
######void setnearby(int x, int y)
	  	    counts number of mines next to square x,y and sets variable (nearby) to that number
######void setnearbyall()
	  	    calls method set nearby for every square
######void laymines(int minenumber)
	  	    randomly places (minenumber) mines on the board
	  	    loops through board untill all mines have been placed
######void GameOver()
	  	    prints "Game Over"
	  	    ends game
	
##AndrewPeckhamCSCI2270Project.cpp
###main
####Opening Variables:
   int newrows=5
   int newcollums=5
   int newmines=5
   MineSweeperGame* currentGame=new MineSweeperGame(newrows,newcollums,newmines)
   int menuchoice =0
####While Loop
  while loop over rest of program exits when menuchoice = 5
  if statement causes a new game when (currentGame) is not active
  board prints at the start of every iteration of the while loop
  prints menu after board
  input for (menuchoice) after menu
    1: method requestcords() feeds method flasquare(x,y)
    2. method requestcords() feeds method checksquare()
    3. returns to top of while loop which prints out the board again
    4. sets the current game to not active and returns to the top of the while loop
    5. thanks the player and exits
    100 calls method showall() for error checking
    error case: clears and ignores cin and displays error message
