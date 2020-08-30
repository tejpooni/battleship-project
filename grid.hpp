// contains the functions to test the grid
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>

void zero_grid(int grid[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			grid[i][j] = 0;
		}
	}
}


// the function print out the game board grid
void print_grid(int grid[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << std::setw(3) << grid[i][j];
		}
		std::cout << std::endl << std::endl;;
	}
}


// the function changes the integer value to a character for player
char int_to_char_player(int num)
{
	if (num == 1)
	{
		return 'C';
	}
	else if (num == 2)
	{
		return 'B';
	}
	else if (num == 3)
	{
		return 'S';
	}
	else if (num == 4)
	{
		return 'c';
	}
	else if (num == -2)
	{
		return '*';
	}
	else if (num == -3 || num == -4)
	{
		return 'X';
	}
	else 
	{
		return ' ';
	}
}


char int_to_char_enemy(int num)
{
	if (num == -2)
	{
		return '*';
	}
	else if (num == -3 || num == -4)
	{
		return 'X';
	}
	else
	{
		return ' ';
	}
}


// the function contains the test grid for the player
void player_grid(int grid[8][8])
{
	zero_grid(grid);
	
	grid[1][6] = 2;
	grid[2][6] = 2;
	grid[3][6] = 2;
	grid[4][6] = 2;
	
	grid[1][1] = 3;
	grid[1][2] = 3;
	grid[1][3] = 3;
	
	grid[4][0] = 1;
	grid[4][1] = 1;
	grid[4][2] = 1;
	grid[4][3] = 1;
	
	grid[6][5] = 4;
	grid[6][6] = 4;
	grid[6][7] = 4;
}


// the function contains the test grid for the AI
void ai_grid(int grid[8][8])
{
	zero_grid(grid);
	
	grid[0][3] = 4;
	grid[0][4] = 4;
	grid[0][5] = 4;
	
	grid[1][1] = 1;
	grid[2][1] = 1;
	grid[3][1] = 1;
	grid[4][1] = 1;
	
	grid[3][3] = 3;
	grid[4][3] = 3;
	grid[5][3] = 3;
	
	grid[2][5] = 2;
	grid[3][5] = 2;
	grid[4][5] = 2;
	grid[5][5] = 2;
}


// the function searches for the integer on the grid. Returns 1 if it's on the grid, return 0 if not
bool int_search(int grid[8][8], int value)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == value)
			{
				return 1;
			}
		}
	}
	return 0;
}


// the function counts for the number of integers on the grid.
int int_count(int grid[8][8], int value)
{
	unsigned int counter = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == value)
			{
				counter++;
			}
		}
	}
	return counter;
}


// the function generates a list of position for the value
std::vector <std::vector <int> > int_list(int grid[8][8], int value)
{
	unsigned int counter = 0;
	std::vector <std::vector <int> > value_pos;  // create a 2 dimensional vector
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == value)
			{
				value_pos.push_back(std::vector <int> ());
				value_pos[counter].push_back(i);  // the 0th index is the row number
				value_pos[counter].push_back(j);  // the 1st index is the column number
				counter++;
			}
		}
	}
	
	return value_pos;
}