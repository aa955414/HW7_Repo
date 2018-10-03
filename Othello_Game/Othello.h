//****************************************************************************
//
// Name: Ethan Roush
//
// Date: 11/23/2017
//
// Description: The header file for Othello; the game for the final project.
//
//****************************************************************************

#include <iostream>
#include <cstdlib>

#include "colors.h"
#include "game.h"

namespace main_savitch_14
{
	class Space
	{
	public:
		Space() { piece_state = 'e'; }
		Space(char& state) { piece_state = state; }
		bool is_black() const { return(piece_state == 'b'); }
		bool is_white() const { return(piece_state == 'w'); }
		void flip();
		bool is_empty() const { return(piece_state == 'e'); }
		void piece_change(const char& state) { piece_state = state; }
	private:
		char piece_state;
	};

	class Othello: public game
	{
	public:
		Othello() { restart(); }
		void make_move(const std::string& move);
		void restart();
		game* clone() const { return new Othello(*this); }
		void compute_moves(std::queue<std::string>& moves) const;
		void display_status() const;
		int evaluate() const;
		bool is_game_over() const;
		bool is_legal(const std::string& move) const;
		who winning() const;
	private:
		Space board[10][10];
	};
}