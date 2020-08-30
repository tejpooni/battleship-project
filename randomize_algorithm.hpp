// this section will be able to randomize the ships location on a 8 x 8 grid.

#include "grid.hpp"

struct node{
    int arr1[3];  //4 int arrays represent coordinates
    int arr2[3];
    int arr3[3];
    int arr4[3];
	int length;
	int str_length;
    std::string name;
    node* next;
	node* previous;
};

node* structure(int carrier[4][2],int battleship[4][2], int submarine[3][2],int cruiser[3][2]){
    // first = carrier, second = battleship, third = submarine, fourth = cruiser 
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node; 

    first -> next = second;
    second -> next  = third;
    third -> next = fourth;
    fourth -> next =  NULL;
	
	first -> previous = NULL;
	second -> previous = first;
	third -> previous = second;
	fourth -> previous = third;
    
    //row 
    first -> arr1[0] = carrier[0][0];
    first -> arr2[0] = carrier[1][0];
    first -> arr3[0] = carrier[2][0];
    first -> arr4[0] = carrier[3][0];

    //cols 
    first -> arr1[1] = carrier[0][1];
    first -> arr2[1] = carrier[1][1];
    first -> arr3[1] = carrier[2][1];
    first -> arr4[1] = carrier[3][1];

    //boolean value if you miss
    first -> arr1[2] =  0;
    first -> arr2[2] =  0;
    first -> arr3[2] =  0;
    first -> arr4[2] =  0;

    //name of ship is carrier
    first -> name = "carrier";
	first -> str_length = 7;

    //rows battleship
    second -> arr1[0] = battleship[0][0];
    second -> arr2[0] = battleship[1][0];
    second -> arr3[0] = battleship[2][0];
    second -> arr4[0] = battleship[3][0];
    //cols battleship
    second -> arr1[1] = battleship[0][1];
    second -> arr2[1] = battleship[1][1];
    second -> arr3[1] = battleship[2][1];
    second -> arr4[1] = battleship[3][1];

    //boolean value if u miss for battleship
    second -> arr1[2] =  0;
    second -> arr2[2] =  0;
    second -> arr3[2] =  0;
    second -> arr4[2] =  0;

    //name
    second -> name = "battleship";
	second -> str_length = 10;

    //row submarine
    third -> arr1[0] = submarine[0][0];
    third -> arr2[0] = submarine[1][0];
    third -> arr3[0] = submarine[2][0];
    third -> arr4[0] = -1;
    //cols sub
    third -> arr1[1] = submarine[0][1];
    third -> arr2[1] = submarine[1][1];
    third -> arr3[1] = submarine[2][1];
    third -> arr4[1] = -1;
    //boolean for miss
    third -> arr1[2] =  0;
    third -> arr2[2] =  0;
    third -> arr3[2] =  0;
    third -> arr4[2] =  1;
    //name
    third -> name =  "submarine";
	third -> str_length = 9;

    //cruiser rows
    fourth -> arr1[0] = cruiser[0][0];
    fourth -> arr2[0] = cruiser[1][0];
    fourth -> arr3[0] = cruiser[2][0];
    fourth -> arr4[0] = -1;
    //cruiser cols
    fourth -> arr1[1] = cruiser[0][1];
    fourth -> arr2[1] = cruiser[1][1];
    fourth -> arr3[1] = cruiser[2][1];
    fourth -> arr4[1] = -1;
    //cruiser boolean if miss
    fourth -> arr1[2] =  0;
    fourth -> arr2[2] =  0;
    fourth -> arr3[2] =  0;
    fourth -> arr4[2] =  1;
    // name
    fourth -> name = "cruiser";
	fourth -> str_length = 7;

	first -> length = 4;
	second -> length = 4;
	third -> length = 3;
	fourth -> length = 3;
	
	return first;
}


// the function randomize the ships position
node* randomizer(int new_grid[8][8], int random_array[8])
{
	int counter;  // a counter that decides the randomness of the ship
	int max_square;  // the maximum number of ships in a row or column
	int coin_flip;  // either 0 or 1, random. If the flip is 0, then the ship is horiontal. If the flip is 1, then the ship is vertical
	int random_number;  // a random number from 1 to 25 or 1 to 36
	int truth_grid[8][8];  // a grid that will decide whether the ship fits on the new_grid
	int row;  
	int col;
	
	zero_grid(new_grid);
	zero_grid(truth_grid);

	max_square = 8 - 4 + 1;

	// flip a fair coin
	coin_flip = random_array[0] % 2; 
	
	random_number = random_array[1] % 40 + 1;

	if (coin_flip == 0)  // if the flip is 0, then the ship will be placed horrizontal
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				truth_grid[i][j] = 1;
			}
		}
	}
	else if (coin_flip == 1)  // if the flip is 1, then the ship will be placed vertically
	{
		for (int i = 0; i < max_square; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				truth_grid[i][j] = 1;
			}
		}
	}
	
	counter = 0;
	for (int i = 0; i < 8 && counter != random_number; i++)
	{
		for (int j = 0; j < 8 && counter != random_number; j++)
		{
			if (truth_grid[i][j] == 1)
			{
				counter++;
				row = i;
				col = j;
			}
		}
	}
	
	int arr[4][2];  // array_1 of coordinates
	
	if (coin_flip == 0)
	{
		for (int j = col; j < col + 4; j++)
		{
			new_grid[row][j] = 1;
			arr[j - col][1] = j;
			arr[j - col][0] = row;
		}
	}
	else if (coin_flip == 1)
	{
		for (int i = row; i < row + 4; i++)
		{
			new_grid[i][col] = 1;
			arr[i - row][0] = i;
			arr[i - row][1] = col;
		}
	}
	
	for (int x = 0; x < 4; x++)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				row = arr[x][0] + i;
				col = arr[x][1] + j;
				if ((row < 8 && row >= 0) && (col < 8 && col >= 0) && (!(i == 0 || j == 0)))
				{
					new_grid[row][col] = -1;
				}
				if (x == 0 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == -1 || j == -1))
				{
					new_grid[row][col] = -1;
				}
				if (x == 3 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == 1 || j == 1))
				{
					new_grid[row][col] = -1;
				}
			}
		}
	}
	
	zero_grid(truth_grid);  // refresh the truth grid to a zero grid
	
	int arr_2[4][2];  // array_2 of coordinates for battleship
	int condition;  // condition will equal to 1 if the ship can fit on the grid, else 0
	coin_flip = random_array[2] % 2;  // flip a coin again
	
	if (coin_flip == 0)  // same idea above, but this time the code will check if the ship will be touched by another ship
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				condition = 1;  // assume that the ship can fit on the grid
				
				for (int x = j; x < j + 4; x++)  // if there's an obstacle in front of the ship, the ship won't fit on the grid
				{
					if (new_grid[i][x] != 0)
					{
						condition = 0;  
					}
				}
				
				if (condition == 1)  // if the ship can fit on the grid, add the info to truth grid
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	else if (coin_flip == 1)  // same idea above
	{
		for (int i = 0; i < max_square; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				condition = 1;
				
				for (int x = i; x < i + 4; x++)
				{
					if (new_grid[x][j] != 0)
					{
						condition = 0;
					}
				}
				
				if (condition == 1)
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	
	random_number = random_array[3] % int_count(truth_grid, 1) + 1;
	
	counter = 0;
	for (int i = 0; i < 8 && counter != random_number; i++)
	{
		for (int j = 0; j < 8 && counter != random_number; j++)
		{
			if (truth_grid[i][j] == 1)
			{
				counter++;
				row = i;
				col = j;
			}
		}
	}
	
	if (coin_flip == 0)
	{
		for (int j = col; j < col + 4; j++)
		{
			new_grid[row][j] = 2;
			arr_2[j - col][1] = j;
			arr_2[j - col][0] = row;
		}
	}
	else if (coin_flip == 1)
	{
		for (int i = row; i < row + 4; i++)
		{
			new_grid[i][col] = 2;
			arr_2[i - row][0] = i;
			arr_2[i - row][1] = col;
		}
	}
	
	for (int x = 0; x < 4; x++)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				row = arr_2[x][0] + i;
				col = arr_2[x][1] + j;
				if ((row < 8 && row >= 0) && (col < 8 && col >= 0) && (!(i == 0 || j == 0)))
				{
					new_grid[row][col] = -1;
				}
				if (x == 0 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == -1 || j == -1))
				{
					new_grid[row][col] = -1;
				}
				if (x == 3 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == 1 || j == 1))
				{
					new_grid[row][col] = -1;
				}
			}
		}
	}
	
	int arr_3[3][2];  // array_3 of coordinate for submarine
	max_square = 8 - 3 + 1;
	coin_flip = random_array[4] % 2;
	
	zero_grid(truth_grid);  // refresh truth grid
	
	if (coin_flip == 0)  // same as above, but with a different size ship
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				condition = 1;  
				
				for (int x = j; x < j + 3; x++)  
				{
					if (new_grid[i][x] != 0)
					{
						condition = 0;  
					}
				}
				
				if (condition == 1)  
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	else if (coin_flip == 1)  // same idea above
	{
		for (int i = 0; i < max_square; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				condition = 1;
				
				for (int x = i; x < i + 3; x++)
				{
					if (new_grid[x][j] != 0)
					{
						condition = 0;
					}
				}
				
				if (condition == 1)
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	
	random_number = random_array[5] % int_count(truth_grid, 1) + 1;
	
	counter = 0;
	for (int i = 0; i < 8 && counter != random_number; i++)
	{
		for (int j = 0; j < 8 && counter != random_number; j++)
		{
			if (truth_grid[i][j] == 1)
			{
				counter++;
				row = i;
				col = j;
			}
		}
	}
	
	if (coin_flip == 0)
	{
		for (int j = col; j < col + 3; j++)
		{
			new_grid[row][j] = 3;
			arr_3[j - col][1] = j;
			arr_3[j - col][0] = row;
		}
	}
	else if (coin_flip == 1)
	{
		for (int i = row; i < row + 3; i++)
		{
			new_grid[i][col] = 3;
			arr_3[i - row][0] = i;
			arr_3[i - row][1] = col;
		}
	}
	
	for (int x = 0; x < 3; x++)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				row = arr_3[x][0] + i;
				col = arr_3[x][1] + j;
				if ((row < 8 && row >= 0) && (col < 8 && col >= 0) && (!(i == 0 || j == 0)))
				{
					new_grid[row][col] = -1;
				}
				if (x == 0 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == -1 || j == -1))
				{
					new_grid[row][col] = -1;
				}
				if (x == 2 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == 1 || j == 1))
				{
					new_grid[row][col] = -1;
				}
			}
		}
	}
	
	int arr_4[3][2];  // the last array for the cruiser
	coin_flip = random_array[6] % 2;
	
	zero_grid(truth_grid);
	
	if (coin_flip == 0)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				condition = 1;  
				
				for (int x = j; x < j + 3; x++)  
				{
					if (new_grid[i][x] != 0)
					{
						condition = 0;  
					}
				}
				
				if (condition == 1)  
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	else if (coin_flip == 1)  // same idea above
	{
		for (int i = 0; i < max_square; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				condition = 1;
				
				for (int x = i; x < i + 3; x++)
				{
					if (new_grid[x][j] != 0)
					{
						condition = 0;
					}
				}
				
				if (condition == 1)
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	
	if (coin_flip == 0 && int_search(truth_grid, 1) == 0)  // if the horrizontal combination is impossible, then do the vertical combination
	{
		zero_grid(truth_grid);  // refresh the zero grid
		coin_flip = 1;  // change the flip of the coin
		
		for (int i = 0; i < max_square; i++)  // make the ship vertical and fit into the grid
		{
			for (int j = 0; j < 8; j++)
			{
				condition = 1;
				
				for (int x = i; x < i + 3; x++)
				{
					if (new_grid[x][j] != 0)
					{
						condition = 0;
					}
				}
				
				if (condition == 1)
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	if (coin_flip == 1 && int_search(truth_grid, 1) == 0)  // same idea as above, but for the vertical combination
	{
		zero_grid(truth_grid);  // refresh the zero grid
		coin_flip = 0;
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				condition = 1;  
				
				for (int x = j; x < j + 3; x++)  
				{
					if (new_grid[i][x] != 0)
					{
						condition = 0;  
					}
				}
				
				if (condition == 1)  
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	
	random_number = random_array[7] % int_count(truth_grid, 1) + 1;
	
	counter = 0;
	for (int i = 0; i < 8 && counter != random_number; i++)
	{
		for (int j = 0; j < 8 && counter != random_number; j++)
		{
			if (truth_grid[i][j] == 1)
			{
				counter++;
				row = i;
				col = j;
			}
		}
	}
	
	if (coin_flip == 0)
	{
		for (int j = col; j < col + 3; j++)
		{
			new_grid[row][j] = 4;
			arr_4[j - col][1] = j;
			arr_4[j - col][0] = row;
		}
	}
	else if (coin_flip == 1)
	{
		for (int i = row; i < row + 3; i++)
		{
			new_grid[i][col] = 4;
			arr_4[i - row][0] = i;
			arr_4[i - row][1] = col;
		}
	}
	
	return structure(arr, arr_2, arr_3, arr_4);
}


node* game_system(int grid[8][8], int row, int col, node* old_ship_list)  // opponent's grid
{
	int condition;  
	int row_num;  // temparary row and col
	int col_num;
	node* current;
	node* ship_list = old_ship_list;
	node* return_list = ship_list;
	
	if (grid[row][col] == 0 || grid[row][col] == -1)
	{
		grid[row][col] = -2;
		return return_list;
	}
	else if(grid[row][col] == 1 || grid[row][col] == 2 || grid[row][col] == 3 || grid[row][col] == 4)
	{
		grid[row][col] = -3;
		while (ship_list != NULL)
		{
			condition = 1;
			if (ship_list -> arr1[0] == row && ship_list -> arr1[1] == col)
			{
				ship_list -> arr1[2] = 1;
			}
			if (ship_list -> arr2[0] == row && ship_list -> arr2[1] == col)
			{
				ship_list -> arr2[2] = 1;
			}
			if (ship_list -> arr3[0] == row && ship_list -> arr3[1] == col)
			{
				ship_list -> arr3[2] = 1;
			}
			if (ship_list -> arr4[0] == row && ship_list -> arr4[1] == col)
			{
				ship_list -> arr4[2] = 1;
			}
			
			if (ship_list -> arr1[2] == 1 && ship_list -> arr2[2] == 1 && ship_list -> arr3[2] == 1 && ship_list -> arr4[2] == 1)
			{
				condition = 0;
				
				if (ship_list -> length == 4)
				{
					grid[ship_list -> arr1[0]][ship_list -> arr1[1]] = -4;
					grid[ship_list -> arr2[0]][ship_list -> arr2[1]] = -4;
					grid[ship_list -> arr3[0]][ship_list -> arr3[1]] = -4;
					grid[ship_list -> arr4[0]][ship_list -> arr4[1]] = -4;
					
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							row_num = ship_list -> arr1[0] + i;
							col_num = ship_list -> arr1[1] + j;
							if ((row_num < 8 && row_num >= 0) && (col_num < 8 && col_num >= 0) && (!(i == 0 || j == 0)))
							{
								grid[row_num][col_num] = -2;
							}
							if (row_num < 8 && row_num >= 0 && (col_num < 8 && col_num >= 0) && (i == -1 || j == -1))
							{
								grid[row_num][col_num] = -2;
							}
						}
					}
					
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							row_num = ship_list -> arr2[0] + i;
							col_num = ship_list -> arr2[1] + j;
							if ((row_num < 8 && row_num >= 0) && (col_num < 8 && col_num >= 0) && (!(i == 0 || j == 0)))
							{
								grid[row_num][col_num] = -2;
							}
						}
					}
					
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							row_num = ship_list -> arr3[0] + i;
							col_num = ship_list -> arr3[1] + j;
							if ((row_num < 8 && row_num >= 0) && (col_num < 8 && col_num >= 0) && (!(i == 0 || j == 0)))
							{
								grid[row_num][col_num] = -2;
							}
						}
					}
					
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							row_num = ship_list -> arr4[0] + i;
							col_num = ship_list -> arr4[1] + j;
							if ((row_num < 8 && row_num >= 0) && (col_num < 8 && col_num >= 0) && (!(i == 0 || j == 0)))
							{
								grid[row_num][col_num] = -2;
							}
							if (row_num < 8 && row_num >= 0 && (col_num < 8 && col_num >= 0) && (i == 1 || j == 1))
							{
								grid[row_num][col_num] = -2;
							}
						}
					}
				}
				else if (ship_list -> length == 3)
				{
					grid[ship_list -> arr1[0]][ship_list -> arr1[1]] = -4;
					grid[ship_list -> arr2[0]][ship_list -> arr2[1]] = -4;
					grid[ship_list -> arr3[0]][ship_list -> arr3[1]] = -4;
					
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							row_num = ship_list -> arr1[0] + i;
							col_num = ship_list -> arr1[1] + j;
							if ((row_num < 8 && row_num >= 0) && (col_num < 8 && col_num >= 0) && (!(i == 0 || j == 0)))
							{
								grid[row_num][col_num] = -2;
							}
							if (row_num < 8 && row_num >= 0 && (col_num < 8 && col_num >= 0) && (i == -1 || j == -1))
							{
								grid[row_num][col_num] = -2;
							}
						}
					}
					
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							row_num = ship_list -> arr2[0] + i;
							col_num = ship_list -> arr2[1] + j;
							if ((row_num < 8 && row_num >= 0) && (col_num < 8 && col_num >= 0) && (!(i == 0 || j == 0)))
							{
								grid[row_num][col_num] = -2;
							}
						}
					}
					
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							row_num = ship_list -> arr3[0] + i;
							col_num = ship_list -> arr3[1] + j;
							if ((row_num < 8 && row_num >= 0) && (col_num < 8 && col_num >= 0) && (!(i == 0 || j == 0)))
							{
								grid[row_num][col_num] = -2;
							}
							if (row_num < 8 && row_num >= 0 && (col_num < 8 && col_num >= 0) && (i == 1 || j == 1))
							{
								grid[row_num][col_num] = -2;
							}
						}
					}
				}

				if (ship_list -> previous == NULL && ship_list -> next == NULL)
				{
					current = ship_list;
					ship_list = NULL;
					return_list = NULL;
					delete current;
				}
				else if (ship_list -> previous == NULL)
				{
					current = ship_list;
					ship_list -> next -> previous = NULL;
					ship_list = ship_list -> next;
					return_list = ship_list;
					delete current;
				}
				else if (ship_list -> next == NULL)
				{
					current = ship_list;
					ship_list -> previous -> next = NULL;
					ship_list = NULL;
					delete current;
				}
				else
				{
					current = ship_list;
					ship_list -> previous -> next = ship_list -> next;
					ship_list -> next -> previous = ship_list -> previous;
					ship_list = ship_list -> next;
					delete current;
				}
			}
			if (condition == 1)
			{
				ship_list = ship_list -> next;
			}
		}
		return return_list;
	}
}


// the function prints out the game board for the player
void print_game(int grid[8][8], int enemy_grid[8][8], node* player, node* ai)
{
	int total_str_len = 54;  // the length of the string in total_str_len
	int str_len = 0;
	int str_size;  // size of a string
	
	std::cout << "Your ships:" << std::setw(57) << "Enemy's ships:" << std::endl;
	
	while (player != NULL)
	{
		str_size = player -> str_length;
		std::cout << player -> name << "; ";
		player = player -> next;
		str_len = str_len + 2 + str_size;
	}
	
	for (int i = 0; i < (total_str_len - str_len); i++)
	{
		std::cout << ' ';
	}
	
	while (ai != NULL)
	{
		std::cout << ai -> name << "; ";
		ai = ai -> next;
	}
	
	std::cout << std::endl;
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << "+---";
		}
		
		std::cout << "+          |          ";
		
		for (int j = 0; j < 8; j++)
		{
			std::cout << "+---";
		}
		
		std::cout << "+\n";
		
		for (int j = 0; j < 8; j++)
		{
			std::cout << "| " << int_to_char_player(grid[i][j]) << " ";
		}
		
		std::cout << "|          |          ";
		
		for (int j = 0; j < 8; j++)
		{
			std::cout << "| " << int_to_char_enemy(enemy_grid[i][j]) << " ";
		}
		
		std::cout << "|\n";
	}
	
	for (int j = 0; j < 8; j++)
		{
			std::cout << "+---";
		}
		
		std::cout << "+          |          ";
		
		for (int j = 0; j < 8; j++)
		{
			std::cout << "+---";
		}
		
		std::cout << "+\n";
}