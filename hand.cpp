/* Kobe Norcross; CS 202; hand.cpp
 * 
 * This is the file that implements the Hand class which is a vector of linked lists.
 * Which is representative of the hand of cards the player has. "has a" relationship.
 *
 */



#include "hand.h"



hand::hand() : cards(), number_of_cards(0) {}



hand::~hand()
{
	destroy_hand(cards, number_of_cards);
}



// loops through the vector
bool hand::destroy_hand(vector<node*&>& cards, int num)
{
	if (num == 0) return true;
	else
	{
		destroy_fingers(cards->get_data());
		return destroy_hand(cards, num--);
	}
	return false;
}



// traverses each LL recursively and deletes each node
bool hand::destroy_fingers(node*& head)
{
	if (!head) return true;
	else
	{
		node * temp = head->get_next();
		delete head;
		head = nullptr;
		return destroy_fingers(temp);
	}
	return false;
}



bool hand::add_card(const Node*& source)
{
	// need to copy the node
	char* type_src = source->get_type();
	if (strcmp(type_src, types[0]))
	{
		return true;
	}
	else if (strcmp(type_src, types[1]))
	{
		return true;
	}
	else
	{
		return true;
	}
	return false;
}



bool hand::use_card(card& play)
{
	
}
