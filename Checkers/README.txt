name : Chao Ma

structure: 
the homework contains Checker.cpp Board.h Board.cpp Piece.h Piece.cpp Position.h Position.cpp
the main method is within the Checkers.cpp
Board class implements the board of the game, and also contains the main rules for the game such as what is a legal move, whether one side has won
Piece class simulates the pieces in the game
Position class offers Position information for a given piece


input and output:
at the very beginning users will be asked to choose a play mode to decide the number of the players
if you choose 1 player, you will play against a computer
if you choose 2 players, you can paly is with other people

in every round, users will be asked to input the coordinate of a certain piece and its destination, if the move is legal, the game will execute the move, otherwise you will be asked again
sample input: 6 1 5 2 means move the piece at (6,1) to (5,2)

if one side won, the game would stop

the game will output a simulated board in the bash every round:
012345678y
1 * * * *
2* * * * 
3 * * * *
4        
5        
6+ + + + 
7 + + + +
8+ + + + 
x

test:
to test the game, you can simply start a 1 player game and play against the computer
