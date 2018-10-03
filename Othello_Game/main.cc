//****************************************************************************
//
// Name: Ethan Roush
//
// Date: 11/23/2017
//
// Description: The main file for Othello; the game for the final project.
//
//****************************************************************************

#include <iostream>
#include <cstdlib>

#include "colors.h"
#include "game.h"
#include "Othello.h"

using namespace std;
using namespace main_savitch_14;

int main()
{
	Othello my_game;
	my_game.play();
	//my_game.winning();
	return(EXIT_SUCCESS);
}