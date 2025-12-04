#include "memory_functions_lohja.h"

using namespace std;

// initMemory initializes the memory; at the outset of the game the grid of
// shots taken is empty, we've not hit any ships, and our player can only apply
// a general, somewhat random firing strategy until we get a hit on some ship
void initMemoryLohja(ComputerMemory &memory) 
{
   memory.mode        =  RANDOM;
   memory.hitRow      = -1;
   memory.hitCol      = -1;
   memory.hitShip     =  NONE;
   memory.fireDir     =  NONE;
   memory.fireDist    =  1;
   memory.lastResult  =  NONE;

   for (int i = 0; i < BOARDSIZE; i++) {
      for (int j = 0; j < BOARDSIZE; j++) {
         memory.grid[i][j] = EMPTY_MARKER;
      }
   }
}

// complete this function so it produces a "smart" move based on the information
// which appears in the computer's memory
string smartMoveLohja(const ComputerMemory &memory) 
{
   string move = "";

   int currRow = -1;
   int currCol = -1;

   if (memory.fireDir == EAST) 
   {
	   currRow = memory.hitRow;
	   currCol = memory.hitCol + memory.fireDist;

	   move = move + (char)('A' + currRow);

	   if (currCol < 9)
	   {
		   move = move + (char)('1' + currCol);
	   }
	   else
	   {
		   move = move + "10";
	   }
   }
   else if (memory.fireDir == WEST)
   {
	   currRow = memory.hitRow;
	   currCol = memory.hitCol - memory.fireDist;

	   move = move + (char)('A' + currRow);

	   if (currCol > 0)
	   {
		   move = move + (char)('1' + currCol);
	   }
	   else
	   {
		   move = move + "1";
	   }
   }
   else if (memory.fireDir == NORTH)
   {
           currRow = memory.hitRow - memory.fireDist;
           currCol = memory.hitCol;

           if (currRow > 0)
           {
           	   move = move + (char)('A' + currRow);
           }
           else
           {
           	   move = move + "A";
           }
	   //if it tries to go off the right most edge
	   if (currCol < 9)
           {
                   move = move + (char)('1' + currCol);
           }
           else
           {
                   move = move + "10";
           }

   }
   else if (memory.fireDir == SOUTH)
   {
	   currRow = memory.hitRow + memory.fireDist;
           currCol = memory.hitCol;

           if (currRow < 9)
           {
                   move = move + (char)('A' + currRow);
           }
           else
           {
                   move = move + "J";
           }
	   //in case it tries to go off the board to the right
	   if (currCol < 9)
	   {
		   move = move + (char)('1' + currCol);
	   }
	   else
	   {
		   move = move + "10";
	   }
   }

   return move;
}


void updateMemoryLohja (int row, int col, int result, ComputerMemory &memory)
{
	if (isASunk(result))
	{
		memory.hitRow = row;
		memory.hitCol = col;
		memory.hitShip = isShip(result);
		memory.fireDir = NONE;
		memory.fireDist = 1;
		memory.mode = RANDOM;
		memory.lastResult = isASunk(result);
	}
	else if ( (isAMiss(result)) && (memory.mode == RANDOM) )
	{
		memory.hitRow = row;
		memory.hitCol = col;
		memory.lastResult = isAMiss(result);
	}
	else if ( (isAHit(result)) && (memory.mode == RANDOM) )
	{
		memory.hitRow = row;
		memory.hitCol = col;
		memory.hitShip = isShip(result);
		memory.fireDir = EAST;
		memory.mode = SEARCH;
		memory.lastResult = isAHit(result);
	}
	else if ( (isAMiss(result)) && (memory.mode == SEARCH) )
	{
		memory.lastResult = isAMiss(result);

		if (memory.fireDir == EAST)
		{
			memory.fireDir = SOUTH;
		}
		else if (memory.fireDir == SOUTH)
		{
			memory.fireDir = WEST;
		}
		else if (memory.fireDir == WEST)
		{
			memory.fireDir = NORTH;
		}
	}
	else if ( (isAHit(result)) && (memory.mode == SEARCH) )
	{
		//for if i hit a ship i don't want
		//keep searching for the original ship
		if (isShip(result) != memory.hitShip)
		{
			if (memory.fireDir == EAST)
			{
				memory.fireDir = SOUTH;
			}
			else if (memory.fireDir == SOUTH)
			{
				memory.fireDir = WEST;
			}
			else if (memory.fireDir == WEST)
			{
				memory.fireDir = NORTH;
			}
		}
		else
		{
			memory.mode = DESTROY;
			memory.fireDist += 1;
			memory.lastResult = isAHit(result);
		}
	}
	
	else if ( (isAMiss(result)) && (memory.mode == DESTROY) )
	{
		memory.lastResult = isAMiss(result);
		memory.fireDist = 1;

		if (memory.fireDir == EAST)
		{
			memory.fireDir = WEST;
		}
		else if (memory.fireDir == WEST)
		{
			memory.fireDir = EAST;
		}
		else if (memory.fireDir == NORTH)
		{
			memory.fireDir = SOUTH;
		}
		else if (memory.fireDir == SOUTH)
		{
			memory.fireDir = NORTH;
		}
	}
	else if ( (isAHit(result)) && (memory.mode == DESTROY) )
	{
		//if i hit the wrong ship, keep going after the original ship
		if (isShip(result) != memory.hitShip) 
		{
			if (memory.fireDir == EAST)
			{
				memory.fireDir = WEST;
			}
			else if (memory.fireDir == WEST)
			{
				memory.fireDir = EAST;
			}
			else if (memory.fireDir == NORTH)
			{
				memory.fireDir = SOUTH;
			}
			else if (memory.fireDir == SOUTH)
			{
				memory.fireDir = NORTH;
			}

		}
		else
		{
			memory.fireDist += 1;
			memory.lastResult = isAHit(result);
		}
	}
}

