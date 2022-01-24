// Kobe Norcross; CS 202; game.h
/*
 * This file will define the gameplay aspect of Magicesque
 * The game class is needed to basically manage the game and make sure the players are able to play the game.
 * The player class is needed to represent the clients interacting with the app.
 * This file represents the player class
 * The user is represented by the player.
 * 
 * This file represents the game class
 * Handles all of the intricacies of the behind the scenes
 * Makes sure the user of the app is able to interact with the two players 
 */
#ifndef GAME_H
#define GAME_H
#include "deck.h"



const int maxHealth = 10;
const int maxMana = 5;



class player
{
	public:
		player();
		~player();
		void take_damage(int damage);		// removes health from player
		void heal(int heal);			// heals the player
		void gain_mana(const int& manaRegen);	// adds mana
		void display() const;			// displays the hand of cards to the user
	protected:
		hand* hand;				// hand of cards
		int health;				// health of the player
		int mana;				// mana of the player
		bool alive;				// if the player is alive
};



class game
{
	public:
		game();					// inits the game
		~game();				// deallocates all memory created 
		void clear_terminal();			// clears the terminal
		void output_welcome_message();		// outputs a welcome message to the player
		void init_deck();			// initializes the deck 
		void init_players();			// initializes the players with a hand of cards, and other vals
		void display(int player);		// displays the players data to the client
		bool flip_coin();			// flips a coin to see who's turn it is
		bool gameplay();			// handles the gameplay to make sure it runs smooth
		bool status_of_game();			// this will check if the game is still going or ended
	protected:
		player* one;				// 0 if it is this player's turn
		player* two;				// 1 if it is this player's turn 
		deck* deck;				// the deck of cards to draw from 
		int round;				// keeps track of the round
		int turn;				// keeps track of who's turn it is
};
#endif
