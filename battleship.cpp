// a battleship game
#include "AI.hpp"


int main()
{
	// create two arrays filled with random integer
	std::srand(std::time(NULL));
	
	int random_1[8];
	int random_2[8];
	
	for (int i = 0; i < 8; i++)
	{
		random_1[i] = std::rand();
		random_2[i] = std::rand();
	}
	
	
	int prompt;  // ask the players what they want to choose
	int player[8][8];  // a 8 by 8 matrix for the game board for player
	int ai[8][8];  // the grid for AI

	// the linked list for ship information for both the player and the AI
	node* player_ship = randomizer(player, random_1);
	node* ai_ship = randomizer(ai, random_2);
	node* current;  // a current node used to delete a linked list
	
	std::cout << "Welcome to battleship, please choose one of the following prompt by entering the number:" << std::endl << std::endl;
	
	while (prompt != 0)
	{
		prompt = -1;  // initialize the value for prompt
		
		while (prompt != 0 && prompt != 1 && prompt != 2)
		{
			std::cout << "(0). Halt the program." << std::endl;
			std::cout << "(1). Play against the normal AI." << std::endl;
			std::cout << "(2). Play against the difficult AI." << std::endl;
			std::cout << "(3). See the rules." << std::endl;
			
			std::cin >> prompt;
			
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				
			}
			if (prompt != 0 && prompt != 1 && prompt != 2 && prompt != 3)
			{
				std::cout << "Sorry, please enter a number between 1-3" << std::endl << std::endl;
			}
			else if (prompt == 3)
			{
				player_grid(player);
				
				std::cout << "In this battleship game, your objective is to destroy all of the enemy ships before they destroy yours.\n"
				<< "You will be playing against the normal AI or the difficult AI, which is to be decided by your choice.\n"
				<< "The game board is a 8 by 8 grid, with 4 ships on it both for you and your opponent, like below:\n" << std::endl;
				print_game(player, ai, player_ship, ai_ship);
				std::cout << "You and your opponent will each have 4 ships: carrier(C), battleship(B), submarine(S) and cruiser(c).\n"
				<< "The carrier(C) and the battleship(B) will occupy 4 squares, and the submarine(S) and the cruiser(c) will occupy 3 squares.\n"
				<< "You will only be able to see where your ship lies on your own board, and you can't see where the enemy ships lie on.\n"
				<< "Both the ships on your and your opponent's board will be randomized.\n"
				<< "The position of the ship must be ONE SQUARE APART from each other.\n"
				<< "The game will begin with you trying to land a bomb on the enemy grid.\n"
				<< "If your bomb didn't land on a ship, the grid will display The symbol\"*\", meaning that the bomb didn't hit anything.\n"
				<< "If your bomb lands on a ship, the grid will display the symbol \"X\", meaning that the bomb hit the enemy ship.\n" 
				<< "Below is an example where your bomb missed the ship, but your opponent's bomb hit your ship:\n" <<std::endl;
				player[1][1] = -3;
				ai[5][6] = -2;
				print_game(player, ai, player_ship, ai_ship);
				std::cout << "If your bomb hit the target, you will be able to throw another bomb at your opponent's board, and so is your opponent.\n"
				<< "If your bomb didn't hit a target, your turn is over, and it will be your opponent's turn.\n"
				<< "In the board above, since the opponent's bomb hits the target, it's able to land a bomb on your grid again, but it missed this time:\n" << std::endl;
				player[1][0] = -2;
				print_game(player, ai, player_ship, ai_ship);
				std::cout << "Then it will be your turn to land the bomb, when the ship is destroyed, all of its surrondings will become \"*\":\n" << std::endl;
				ai[7][7] = -2;
				player[1][2] = -3;
				player[1][3] = -3;
				player[0][0] = -2;
				player[0][1] = -2;
				player[0][2] = -2;
				player[0][3] = -2;
				player[0][4] = -2;
				player[2][0] = -2;
				player[2][1] = -2;
				player[2][2] = -2;
				player[2][3] = -2;
				player[2][4] = -2;
				player[1][4] = -2;
				print_game(player, ai, player_ship, ai_ship);
				std::cout << "The match will keep going until your or your enemy's ship all get destroyed, and you or your enemy will thus lose\n"
				<< "Are you ready to play the game? Please select one of the following prompt by entering the corresponding digit:\n" << std::endl;
				
				zero_grid(player);
				zero_grid(ai);
			}
		}
		
		player_ship = randomizer(player, random_1);
		ai_ship = randomizer(ai, random_2);
		
		int temp;  // a temparary value
		int condition;  // condition is 1 when user give a good input, otherwise 0;
		int condition_2;
		int turn = 0;  // when turn is 0, it's player's turn. when turn is 1, it's ai's turn
		int row;
		int col;
		int* ai_coord = new int[2];
		
		while (player_ship != NULL && ai_ship != NULL && prompt != 0)
		{
			if (turn == 0)  // player's turn
			{
				std::cout << "Your turn:\n" << std::endl;
				temp = 1;
				row = -1;
				col = -1;
				while (temp == 1 || ai[row][col] == -2 || ai[row][col] == -4 || ai[row][col] == -3)  // ask for row and col input
				{
					temp = 0;
					condition = 0;
					while (condition == 0)
					{
						std::cout << "Please input the row number from 1 - 8:" << std::endl;
						std::cin >> row;
						
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "Invalid input, please try again." << std::endl;
						}
						else if (!(row >= 1 && row <= 8))
						{
							std::cout << "The input is out of the range." << std::endl;
						}
						else
						{
							condition = 1;
							row = row - 1;
						}
					}
					condition = 0;
					while (condition == 0)
					{
						std::cout << "Please input the column number from 1 - 8:" << std::endl;
						std::cin >> col;
						
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "Invalid input, please try again." << std::endl;
						}
						else if (!(col >= 1 && col <= 8))
						{
							std::cout << "The input is out of the range." << std::endl;
						}
						else
						{
							condition = 1;
							col = col - 1;
						}
					}
					if (ai[row][col] == -2 || ai[row][col] == -4 || ai[row][col] == -3)
					{
						std::cout << "The position already has bombs on it, please pick a different position!\n" << std::endl;
					}
				}
				if (ai[row][col] == 0 || ai[row][col] == -1)  // attack on the AI's board
				{
					ai_ship = game_system(ai, row, col, ai_ship);
					turn = 1;
					condition_2 = 0;
				}
				else if (ai[row][col] == 1 || ai[row][col] == 2 || ai[row][col] == 3 || ai[row][col] == 4)
				{
					ai_ship = game_system(ai, row, col, ai_ship);
					turn = 0;
					condition_2 = 1;
				}
			}
			else if(turn == 1)  // AI's turn
			{
				if (prompt == 1)
				{
					ai_coord = normal_ai(player);  // attack on player's board
				}
				else if (prompt == 2)
				{
					ai_coord = difficult_ai(player, player_ship);
				}
				
				row = ai_coord[0];
				col = ai_coord[1];
				
				delete ai_coord;
				
				std::cout << "AI's turn:" << '(' << row + 1 << ", " << col + 1 << ")\n" << std::endl;
				
				if (player[row][col] == 0 || player[row][col] == -1)  // attack on the AI's board
				{
					player_ship = game_system(player, row, col, player_ship);
					turn = 0;
					condition_2 = 2;
				}
				else if (player[row][col] == 1 || player[row][col] == 2 || player[row][col] == 3 || player[row][col] == 4)
				{
					player_ship = game_system(player, row, col, player_ship);
					turn = 1;
					condition_2 = 3;
				}
			}
			print_game(player, ai, player_ship, ai_ship);
			if (condition_2 == 0)
			{
				std::cout << "You missed. Switch turns.\n" << std::endl;
			}
			else if (condition_2 == 1 && ai_ship != NULL)
			{
				std::cout << "You hit the enemy ship! Now you can land a bomb again.\n" << std::endl;
			}
			else if (condition_2 == 2)
			{
				std::cout << "The enemy missed. Switch turns.\n" << std::endl;
			}
			else if (condition_2 == 3 && player_ship != NULL)
			{
				std::cout << "The enemy hit your ship! It gets to land a bomb again.\n" << std::endl;
			}
		}
		
		if (player_ship == NULL && prompt != 0)
		{
			std::cout << "The enemy has destroyed all of your ships. The AI has won the game!\n" << std::endl;
		}
		else if (ai_ship == NULL && prompt != 0)
		{
			std::cout << "You have destroyed all of the enemy's ships. You have won the game!\n" << std::endl;
		}
		
		if (prompt != 0)
		{
			std::cout << "Would you want to play again?\n" << std::endl;
		}
		else
		{
			std::cout << "The game ends..." << std::endl;
		}
		
		while (player_ship != NULL)
		{
			current = player_ship;
			player_ship = player_ship -> next;
			delete current;
		}
		
		while (ai_ship != NULL)
		{
			current = ai_ship;
			ai_ship = ai_ship -> next;
			delete current;
		}
	}

	return 0;
}