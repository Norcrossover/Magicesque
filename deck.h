// Kobe Norcross; CS 202; deck.h
/*
 * Represents the node class
 * This will be a dynamically bound class that represents the cards of the game.
 * It allows for both data structures to represent the cards.
 * 
 * Represents the deck Class
 * The Deck is a data structure that represents all of the cards avaliable to draw from.
 * It's a CLL of the Node class.
 * Will allow the Player to draw from it, probably handled by the Game class.
 */
#ifndef DECK_H
#define DECK_H
#include "card.h"



// global constant for the types of cards
char** types = {"atk", "def", "spl"};



class node 
{
	public:
		node();
		node(const card*& new_data);
		//node(const node*& source);
		~node();
		node*& get_next();
		char* get_type() const;
		void set_next(const node*& source);
	protected:
		node * next;
		card * data;
};



class deck
{
	public:
		deck();
		~deck();
		bool shuffle_deck(char* file_name); 		// This is a name that basically just means build the deck from the file
		bool add(node*& new_node);			// Adds a card to the deck
		node*& draw_card();				// Draws a random card from the deck and returns it
	protected:
		node * top;					// top of the deck, or head of the CLL, which ever is preffered
		node * bottom;					// bottom of the deck, or tail
		void destroy(node*& head);			// recursive call to deallocate memory
};
#endif
