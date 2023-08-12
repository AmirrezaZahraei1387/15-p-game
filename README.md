# 15-p-game


the 15 puzzle game is a game containing a 4x4 board filled
with numbers from 1 to 15. also there is a spot instead of number
16 in the top left corner. the goal the player should achieve is
to make the numbers in the correct order and transform the
spot to the bottom right corner.

___

in order to play this game the game provides the following
commands for the users:

w - slide tile up

a - slide tile left

s - slide tile down

d - slide tile right

q - quit game

# design

class board is the main part of the designation of this
program. the board class will need the class Tile to represent
each of the tiles in the board of the game. it will contain
functionality for doing shuffling, and it should keep track
of the spot that is empty in the board. we will need another class
for managing the users inputs. it will get the user commands
and manage them. also if they were wring it will say. 
Then in the main, the main logic part of the program will 
happen. so basically we will have  while True loop that will
iterate until the user quit or the user win the game. 
it should get the user commands, update the board and check 
if the user won or not.




