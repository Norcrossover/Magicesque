// Kobe Norcross; CS 202; hand.h
/*
 * This is the declaration of the Hand Class. 
 * It represents the data structure that each player will need in order to have cards.
 * It will be a vector of heads, with each vector array holding a different type of card.
 * So there will only be three array elements needed. 
 * Each part of the array will be pointing to a head node which will represent a LLL.
 */



#include "deck.h"
#ifndef HAND_H 
#define HAND_H 



class hand
{
	public:
		hand();
		~hand();
		bool add_card(const Node*& source);		// adds a card to the designated LLL
		bool use_card();				// removes the card from the hand and does whatever the card needs to do
	protected:
		std::vector<node*& head> cards; 		// data structure
		int number_of_cards;				// keeps track of the cards in hand
		bool add_card(node *& new_node);
		bool use_card();
		bool destroy_hand(vector<node*&>& hand_of_cards, int number_of_cards_left);
		bool destroy_fingers(node*& head);
};



#endif
