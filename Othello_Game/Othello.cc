//****************************************************************************
//
// Name: Ethan Roush
//
// Date: 11/23/2017
//
// Description: The implementation file for Othello; the game for the final project.
//
//****************************************************************************

#include <iostream>
#include <cstdlib>
#include <string>

#include "colors.h"
#include "game.h"
#include "Othello.h"

namespace main_savitch_14
{
	void Othello::display_status() const
	{
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (i == 0 && j == 0)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 0 && j == 1)
				{
					cout << B_GREEN << "|     a    ";
				}
				else if (i == 0 && j == 2)
				{
					cout << B_GREEN << "|     b    ";
				}
				else if (i == 0 && j == 3)
				{
					cout << B_GREEN << "|     c    ";
				}
				else if (i == 0 && j == 4)
				{
					cout << B_GREEN << "|     d    ";
				}
				else if (i == 0 && j == 5)
				{
					cout << B_GREEN << "|     e    ";
				}
				else if (i == 0 && j == 6)
				{
					cout << B_GREEN << "|     f    ";
				}
				else if (i == 0 && j == 7)
				{
					cout << B_GREEN << "|     g    ";
				}
				else if (i == 0 && j == 8)
				{
					cout << B_GREEN << "|     h    ";
				}
				else if (i == 0 && j == 9)
				{
					cout << B_GREEN << "|          |";
					cout << RESET << endl;
				}
				else if (i >= 1 && i <= 8 && j == 1)
				{
					if (board[i][j].is_empty())
					{
						cout << B_WHITE << BLACK << "|          |" << RESET;
					}
					else if (board[i][j].is_black())
					{
						cout << B_BLUE << WHITE << "|     O    |" << RESET;
					}
					else if (board[i][j].is_white())
					{
						cout << B_RED << WHITE << "|     O    |" << RESET;
					}
					else
					{
						;
					}
				}
				else if (i >= 1 && i <= 8 && j >= 2 && j <= 8)
				{
					if (board[i][j].is_empty())
					{
						cout << B_WHITE << BLACK << "          |" << RESET;
					}
					else if (board[i][j].is_black())
					{
						cout << B_BLUE << WHITE << "     O    |" << RESET;
					}
					else if (board[i][j].is_white())
					{
						cout << B_RED << WHITE << "     O    |" << RESET;
					}
					else
					{
						;
					}
				}
				else if (i >= 1 && i <= 8 && j == 9)
				{
					cout << B_GREEN << "          |";
					cout << RESET << endl;
				}
				else if (i == 1 && j == 0)
				{
					cout << B_GREEN << "|    1     " << RESET;
				}
				else if (i == 2 && j == 0)
				{
					cout << B_GREEN << "|    2     " << RESET;
				}
				else if (i == 3 && j == 0)
				{
					cout << B_GREEN << "|    3     " << RESET;
				}
				else if (i == 4 && j == 0)
				{
					cout << B_GREEN << "|    4     " << RESET;
				}
				else if (i == 5 && j == 0)
				{
					cout << B_GREEN << "|    5     " << RESET;
				}
				else if (i == 6 && j == 0)
				{
					cout << B_GREEN << "|    6     " << RESET;
				}
				else if (i == 7 && j == 0)
				{
					cout << B_GREEN << "|    7     " << RESET;
				}
				else if (i == 8 && j == 0)
				{
					cout << B_GREEN << "|    8     " << RESET;
				}
				else if (i == 9 && j == 0)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 9 && j == 1)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 9 && j == 2)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 9 && j == 3)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 9 && j == 4)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 9 && j == 5)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 9 && j == 6)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 9 && j == 7)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 9 && j == 8)
				{
					cout << B_GREEN << "|          ";
				}
				else if (i == 9 && j == 9)
				{
					cout << B_GREEN << "|          |";
					cout << RESET << endl;
				}
				else
				{
					;
				}
			}
		}
	}

	bool Othello::is_legal(const std::string& move) const
	{
		if (move == "Pass")
		{
			return true;
		}
		int column = int(toupper(move[0])) - 64;
		int row = int(toupper(move[1])) - 48;
		if (!board[row][column].is_empty()) //Checking if board spot is empty.
		{
			return false;
		}
		if (next_mover() == HUMAN) //Blue_Black
		{
			if (board[row - 1][column].is_white()) //Up Case
			{
				int row_temp = row;
				row_temp -= 2;
				while (row_temp >= 1)
				{
					if (board[row_temp][column].is_black())
					{
						return true;
					}
					else
					{
						row_temp--;
					}
				}
			}
			if (board[row - 1][column + 1].is_white()) //Up Right Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp -= 2;
				column_temp += 2;
				while (row_temp >= 1 || column_temp <= 8)
				{
					if (board[row_temp][column_temp].is_black())
					{
						return true;
					}
					else
					{
						row_temp--;
						column_temp++;
					}
				}
			}
			if (board[row][column + 1].is_white()) //Right Case
			{
				int column_temp = column;
				column_temp += 2;
				while (column_temp <= 8)
				{
					if (board[row][column_temp].is_black())
					{
						return true;
					}
					else
					{
						column_temp++;
					}
				}
			}
			if (board[row + 1][column + 1].is_white()) //Lower Right Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp += 2;
				column_temp += 2;
				while (row_temp <= 8 || column_temp <= 8)
				{
					if (board[row_temp][column_temp].is_black())
					{
						return true;
					}
					else
					{
						row_temp++;
						column_temp++;
					}
				}
			}
			if (board[row + 1][column].is_white()) //Lower Case
			{
				int row_temp = row;
				row_temp += 2;
				while (row_temp <= 8)
				{
					if (board[row_temp][column].is_black())
					{
						return true;
					}
					else
					{
						row_temp++;
					}
				}
			}
			if (board[row + 1][column - 1].is_white()) //Lower Left Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp += 2;
				column_temp -= 2;
				while (row_temp <= 8 || column_temp >= 1)
				{
					if (board[row_temp][column_temp].is_black())
					{
						return true;
					}
					else
					{
						row_temp++;
						column_temp--;
					}
				}
			}
			if (board[row][column - 1].is_white()) //Left Case
			{
				int column_temp = column;
				column_temp -= 2;
				while (column_temp >= 1)
				{
					if (board[row][column_temp].is_black())
					{
						return true;
					}
					else
					{
						column_temp--;
					}
				}
			}
			if (board[row - 1][column - 1].is_white()) //Upper Left Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp -= 2;
				column_temp -= 2;
				while (row_temp >= 1 || column_temp >= 1)
				{
					if (board[row_temp][column_temp].is_black())
					{
						return true;
					}
					else
					{
						row_temp--;
						column_temp--;
					}
				}
			}
			else
			{
				//cout << "Couldn't make player 1 move!" << endl;
				return false;
			}
		}
		else if (next_mover() == COMPUTER) //Red_White
		{
			if (board[row - 1][column].is_black()) //Up Case
			{
				int row_temp = row;
				row_temp -= 2;
				while (row_temp >= 1)
				{
					if (board[row_temp][column].is_white())
					{
						return true;
					}
					else
					{
						row_temp--;
					}
				}
			}
			if (board[row - 1][column + 1].is_black()) //Up Right Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp -= 2;
				column_temp += 2;
				while (row_temp >= 1 || column_temp <= 8)
				{
					if (board[row_temp][column_temp].is_white())
					{
						return true;
					}
					else
					{
						row_temp--;
						column_temp++;
					}
				}
			}
			if (board[row][column + 1].is_black()) //Right Case
			{
				int column_temp = column;
				column_temp += 2;
				while (column_temp <= 8)
				{
					if (board[row][column_temp].is_white())
					{
						return true;
					}
					else
					{
						column_temp++;
					}
				}
			}
			if (board[row + 1][column + 1].is_black()) //Lower Right Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp += 2;
				column_temp += 2;
				while (row_temp <= 8 || column_temp <= 8)
				{
					if (board[row_temp][column_temp].is_white())
					{
						return true;
					}
					else
					{
						row_temp++;
						column_temp++;
					}
				}
			}
			if (board[row + 1][column].is_black()) //Lower Case
			{
				int row_temp = row;
				row_temp += 2;
				while (row_temp <= 8)
				{
					if (board[row_temp][column].is_white())
					{
						return true;
					}
					else
					{
						row_temp++;
					}
				}
			}
			if (board[row + 1][column - 1].is_black()) //Lower Left Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp += 2;
				column_temp -= 2;
				while (row_temp <= 8 || column_temp >= 1)
				{
					if (board[row_temp][column_temp].is_white())
					{
						return true;
					}
					else
					{
						row_temp++;
						column_temp--;
					}
				}
			}
			if (board[row][column - 1].is_black()) //Left Case
			{
				int column_temp = column;
				column_temp -= 2;
				while (column_temp >= 1)
				{
					if (board[row][column_temp].is_white())
					{
						return true;
					}
					else
					{
						column_temp--;
					}
				}
			}
			if (board[row - 1][column - 1].is_black()) //Upper Left Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp -= 2;
				column_temp -= 2;
				while (row_temp >= 1 || column_temp >= 1)
				{
					if (board[row_temp][column_temp].is_white())
					{
						return true;
					}
					else
					{
						row_temp--;
						column_temp--;
					}
				}
			}
			else
			{
				//cout << "Couldn't make player 2 move!" << endl;
				return false;
			}
		}
		else
		{
			return false;
		}
		return false;
	}

	void Othello::make_move(const std::string& move)
	{
		if (move == "Pass")
		{
			game::make_move(move);
			return;
		}
		int column = int(toupper(move[0])) - 64;
		int row = int(toupper(move[1])) - 48;
		if (next_mover() == HUMAN) //Blue_Black
		{
			if (board[row - 1][column].is_white()) //Up Case
			{
				int row_temp = row;
				row_temp -= 2;
				while (row_temp >= 1)
				{
					if (board[row_temp][column].is_black())
					{
						board[row][column].piece_change('b');
						int row_temp_2 = row_temp + 1;
						while (row_temp_2 != row)
						{
							if (board[row_temp_2][column].is_white())
							{
								board[row_temp_2][column].flip();
							}
							row_temp_2++;
						}
					}
					row_temp--;
				}
			}
			if (board[row - 1][column + 1].is_white()) //Up Right Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp -= 2;
				column_temp += 2;
				while (row_temp >= 1 || column_temp <= 8)
				{
					if (board[row_temp][column_temp].is_black())
					{
						board[row][column].piece_change('b');
						int row_temp_2 = row_temp + 1;
						int column_temp_2 = column_temp - 1;
						while (row_temp_2 != row && column_temp_2 != column)
						{
							if (board[row_temp_2][column_temp_2].is_white())
							{
								board[row_temp_2][column_temp_2].flip();
							}
							row_temp_2++;
							column_temp_2--;
						}
					}
					row_temp--;
					column_temp++;
				}
			}
			if (board[row][column + 1].is_white()) //Right Case
			{
				int column_temp = column;
				column_temp += 2;
				while (column_temp <= 8)
				{
					if (board[row][column_temp].is_black())
					{
						board[row][column].piece_change('b');
						int column_temp_2 = column_temp - 1;
						while (column_temp_2 != column)
						{
							if (board[row][column_temp_2].is_white())
							{
								board[row][column_temp_2].flip();
							}
							column_temp_2--;
						}
					}
					column_temp++;
				}
			}
			if (board[row + 1][column + 1].is_white()) //Lower Right Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp += 2;
				column_temp += 2;
				while (row_temp <= 8 || column_temp <= 8)
				{
					if (board[row_temp][column_temp].is_black())
					{
						board[row][column].piece_change('b');
						int row_temp_2 = row_temp - 1;
						int column_temp_2 = column_temp - 1;
						while (row_temp_2 != row && column_temp_2 != column)
						{
							if (board[row_temp_2][column_temp_2].is_white())
							{
								board[row_temp_2][column_temp_2].flip();
							}
							row_temp_2--;
							column_temp_2--;
						}
					}
					row_temp++;
					column_temp++;
				}
			}
			if (board[row + 1][column].is_white()) //Lower Case
			{
				int row_temp = row;
				row_temp += 2;
				while (row_temp <= 8)
				{
					if (board[row_temp][column].is_black())
					{
						board[row][column].piece_change('b');
						int row_temp_2 = row_temp - 1;
						while (row_temp_2 != row)
						{
							if (board[row_temp_2][column].is_white())
							{
								board[row_temp_2][column].flip();
							}
							row_temp_2--;
						}
					}
					row_temp++;
				}
			}
			if (board[row + 1][column - 1].is_white()) //Lower Left Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp += 2;
				column_temp -= 2;
				while (row_temp <= 8 || column_temp >= 1)
				{
					if (board[row_temp][column_temp].is_black())
					{
						board[row][column].piece_change('b');
						int row_temp_2 = row_temp - 1;
						int column_temp_2 = column_temp + 1;
						while (row_temp_2 != row && column_temp_2 != column)
						{
							if (board[row_temp_2][column_temp_2].is_white())
							{
								board[row_temp_2][column_temp_2].flip();
							}
							row_temp_2--;
							column_temp_2++;
						}
					}
					row_temp++;
					column_temp--;
				}
			}
			if (board[row][column - 1].is_white()) //Left Case
			{
				int column_temp = column;
				column_temp -= 2;
				while (column_temp >= 1)
				{
					if (board[row][column_temp].is_black())
					{
						board[row][column].piece_change('b');
						int column_temp_2 = column_temp + 1;
						while (column_temp_2 != column)
						{
							if (board[row][column_temp_2].is_white())
							{
								board[row][column_temp_2].flip();
							}
							column_temp_2++;
						}
					}
					column_temp--;
				}
			}
			if (board[row - 1][column - 1].is_white()) //Upper Left Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp -= 2;
				column_temp -= 2;
				while (row_temp >= 1 || column_temp >= 1)
				{
					if (board[row_temp][column_temp].is_black())
					{
						board[row][column].piece_change('b');
						int row_temp_2 = row_temp + 1;
						int column_temp_2 = column_temp + 1;
						while (row_temp_2 != row && column_temp_2 != column)
						{
							if (board[row_temp_2][column_temp_2].is_white())
							{
								board[row_temp_2][column_temp_2].flip();
							}
							row_temp_2++;
							column_temp_2++;
						}
					}
					row_temp--;
					column_temp--;
				}
			}
		}
		else if (next_mover() == COMPUTER) //Red_White
		{
			if (board[row - 1][column].is_black()) //Up Case
			{
				int row_temp = row;
				row_temp -= 2;
				while (row_temp >= 1)
				{
					if (board[row_temp][column].is_white())
					{
						board[row][column].piece_change('w');
						int row_temp_2 = row_temp + 1;
						while (row_temp_2 != row)
						{
							if (board[row_temp_2][column].is_black())
							{
								board[row_temp_2][column].flip();
							}
							row_temp_2++;
						}
					}
					row_temp--;
				}
			}
			if (board[row - 1][column + 1].is_black()) //Up Right Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp -= 2;
				column_temp += 2;
				while (row_temp >= 1 || column_temp <= 8)
				{
					if (board[row_temp][column_temp].is_white())
					{
						board[row][column].piece_change('w');
						int row_temp_2 = row_temp + 1;
						int column_temp_2 = column_temp - 1;
						while (row_temp_2 != row && column_temp_2 != column)
						{
							if (board[row_temp_2][column_temp_2].is_black())
							{
								board[row_temp_2][column_temp_2].flip();
							}
							row_temp_2++;
							column_temp_2--;
						}
					}
					row_temp--;
					column_temp++;
				}
			}
			if (board[row][column + 1].is_black()) //Right Case
			{
				int column_temp = column;
				column_temp += 2;
				while (column_temp <= 8)
				{
					if (board[row][column_temp].is_white())
					{
						board[row][column].piece_change('w');
						int column_temp_2 = column_temp - 1;
						while (column_temp_2 != column)
						{
							if (board[row][column_temp_2].is_black())
							{
								board[row][column_temp_2].flip();
							}
							column_temp_2--;
						}
					}
					column_temp++;
				}
			}
			if (board[row + 1][column + 1].is_black()) //Lower Right Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp += 2;
				column_temp += 2;
				while (row_temp <= 8 || column_temp <= 8)
				{
					if (board[row_temp][column_temp].is_white())
					{
						board[row][column].piece_change('w');
						int row_temp_2 = row_temp - 1;
						int column_temp_2 = column_temp - 1;
						while (row_temp_2 != row && column_temp_2 != column)
						{
							if (board[row_temp_2][column_temp_2].is_black())
							{
								board[row_temp_2][column_temp_2].flip();
							}
							row_temp_2--;
							column_temp_2--;
						}
					}
					row_temp++;
					column_temp++;
				}
			}
			if (board[row + 1][column].is_black()) //Lower Case
			{
				int row_temp = row;
				row_temp += 2;
				while (row_temp <= 8)
				{
					if (board[row_temp][column].is_white())
					{
						board[row][column].piece_change('w');
						int row_temp_2 = row_temp - 1;
						while (row_temp_2 != row)
						{
							if (board[row_temp_2][column].is_black())
							{
								board[row_temp_2][column].flip();
							}
							row_temp_2--;
						}
					}
					row_temp++;
				}
			}
			if (board[row + 1][column - 1].is_black()) //Lower Left Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp += 2;
				column_temp -= 2;
				while (row_temp <= 8 || column_temp >= 1)
				{
					if (board[row_temp][column_temp].is_white())
					{
						board[row][column].piece_change('w');
						int row_temp_2 = row_temp - 1;
						int column_temp_2 = column_temp + 1;
						while (row_temp_2 != row && column_temp_2 != column)
						{
							if (board[row_temp_2][column_temp_2].is_black())
							{
								board[row_temp_2][column_temp_2].flip();
							}
							row_temp_2--;
							column_temp_2++;
						}
					}
					row_temp++;
					column_temp--;
				}
			}
			if (board[row][column - 1].is_black()) //Left Case
			{
				int column_temp = column;
				column_temp -= 2;
				while (column_temp >= 1)
				{
					if (board[row][column_temp].is_white())
					{
						board[row][column].piece_change('w');
						int column_temp_2 = column_temp + 1;
						while (column_temp_2 != column)
						{
							if (board[row][column_temp_2].is_black())
							{
								board[row][column_temp_2].flip();
							}
							column_temp_2++;
						}
					}
					column_temp--;
				}
			}
			if (board[row - 1][column - 1].is_black()) //Upper Left Case
			{
				int row_temp = row;
				int column_temp = column;
				row_temp -= 2;
				column_temp -= 2;
				while (row_temp >= 1 || column_temp >= 1)
				{
					if (board[row_temp][column_temp].is_white())
					{
						board[row][column].piece_change('w');
						int row_temp_2 = row_temp + 1;
						int column_temp_2 = column_temp + 1;
						while (row_temp_2 != row && column_temp_2 != column)
						{
							if (board[row_temp_2][column_temp_2].is_black())
							{
								board[row_temp_2][column_temp_2].flip();
							}
							row_temp_2++;
							column_temp_2++;
						}
					}
					row_temp--;
					column_temp--;
				}
			}
		}
		game::make_move(move);
	}

	void Othello::restart()
	{
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				board[i][j].piece_change('e');
			}
		}
		board[4][4].piece_change('w');
		board[5][4].piece_change('b');
		board[4][5].piece_change('b');
		board[5][5].piece_change('w');
	}

	void Space::flip()
	{
		if (piece_state == 'b')
		{
			piece_state = 'w';
		}
		else if (piece_state == 'w')
		{
			piece_state = 'b';
		}
		else
		{
			cout << "Error flipping piece!" << endl;
		}
	}

	bool Othello::is_game_over() const
	{
		if (moves_completed() == 60)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	game::who Othello::winning() const
	{
		int black = 0; //Blue
		int white = 0; //Red
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (board[i][j].is_black())
				{
					black++;
				}
				else if (board[i][j].is_white())
				{
					white++;
				}
			}
		}
		cout << "Player 1 - Blue - has " << black << " pieces." << endl;
		cout << "Player 2 - Red - has " << white << " pieces." << endl;
		if (black > white)
		{
			cout << "Player 1 wins!" << endl;
			return HUMAN;
		}
		else if (black < white)
		{
			cout << "Player 2 wins!" << endl;
			return COMPUTER;
		}
		else if (black == white)
		{
			cout << "There was a tie!" << endl;
			return NEUTRAL;
		}
		return NEUTRAL;
	}

	void Othello::compute_moves(std::queue<std::string>& moves) const
	{
		string move = "  ";
		for (char i = 'A'; i < 'I'; ++i)
		{
			for (char j = '1'; j < '9'; ++j)
			{
				//cout << i << " " << j << endl;
				move[0] = i;
				move[1] = j;
				//cout << "Checking move: " << move << endl;
				if (is_legal(move))
				{
					moves.push(move);
				}
			}
		}
		if (moves.empty())
		{
			moves.push("Pass");
		}
	}

	int Othello::evaluate() const
	{
		int black = 0; //Blue
		int white = 0; //Red
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (board[i][j].is_black())
				{
					if (i == 1 && j == 1)
					{
						black += 10;
					}
					else if (i == 1 && j == 8)
					{
						black += 10;
					}
					else if (i == 8 && j == 1)
					{
						black += 10;
					}
					else if (i == 8 && j == 8)
					{
						black += 10;
					}
					else
					{
						black++;
					}
				}
				else if (board[i][j].is_white())
				{
					if (i == 1 && j == 1)
					{
						white += 10;
					}
					else if (i == 1 && j == 8)
					{
						white += 10;
					}
					else if (i == 8 && j == 1)
					{
						white += 10;
					}
					else if (i == 8 && j == 8)
					{
						white += 10;
					}
					else
					{
						white++;
					}
				}
			}
		}
		return (white - black);
	}
}