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
const char* TYPES[] = {"atk", "def", "spl"};
const int MAX = 256;



class node 
{
	public:
		node();
		node(attack*& new_attack_card);
		node(defense*& new_defense_card);
		node(spell*& new_spell_card);
		node(const node*& source);
		~node();
		node*& get_next();
		int get_type() const;				// retrieves the type based on the presence of a card, no getters needed
		void set_next(const node*& source);
	protected:
		node* next;
		attack* atk;
		defense* def;
		spell* spl;
};



class deck
{
	public:
		deck();
		~deck();
		bool shuffle_deck(char* file_name); 							// This is a name that basically just means build the deck from the file
		bool add_card(node*& new_node);								// Adds a card to the deck
		node*& draw_card();									// Draws a random card from the deck and returns it
	protected:
		node * top;										// top of the deck, or head of the CLL, which ever is preffered
		node * bottom;										// bottom of the deck, or tail
		void destroy(node*& top_of_the_deck);							// recursive call to deallocate memory
		node*& draw_card(node*& previous_node, node*& current_node, int traversal_value);
};



int random(int range_beginning, int range_end);								// helper function for getting a random whole number in a range



#endif
