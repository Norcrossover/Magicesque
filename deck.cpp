// Kobe Norcross; CS 202; deck.cpp
/*
*/



#include "deck.h"



node::node() : next(nullptr), data(nullptr) {}



node*& node::get_next()
{
	return next;
}



void node::set_next(const node*& source)
{
	next = source;
}



char* node::get_type() const
{
	return data->get_type();
}



//---------------------------------------------------------------------------------------------
deck::deck() : top(nullptr), bottom(nullptr) {}

	

deck::~deck()
{
	if (top)
	{
		destroy(top);
		delete bottom;
	}
}



/*
if the top node is equal to the bottom, break out of the recursion
*/
void deck::destroy(node*& top)
{
	if (top == bottom)
	{
		node * temp = top->get_next();
		delete top;
		destroy(temp);
	}
	return;
}



/*
Open the test file
if the file opened is good
	while the loop hasn't reached the end of the file
	{
		get the type of the card
		get the card name
		get the int value
		if the card is a spell
		{
			get the mana cost
		}
		allocate memory for a new node with all of the values
		add the node to the deck
	}
	return true
}
return false, there was an error in opening the file
*/
bool deck::shuffle_deck(char* input_file)
{
	ifstream input;
	input.open(input_file);
	char* types[3] = {"atk", "def", "spl"};
	
	if (input.good())
	{
		while (!input.eof())		
		{
			// input type and implement checks in order to see what vals to put
		}
		return true;
	}
	return false;
}



/*
The test file is already pretty random in regards to data, and I don't really want to sort it out. 
I plan on just adding it in the front.
bool deck::add_card(node*& newnode) pseudocode
	if there is no top
	{
		establish this node as the top
		return true
	}
	else if there is no bottom
	{
		establish the bottom
		return true
	}
	else 
	{
		if top->next is bottom
		{
			set new node next to bottom
			set top->next to new node
			return true
		}
		set newnode->next to top->next
		set top->next to newnode
		return true
	}
	return false
*/
bool deck::add_card(node*& new_card)
{
	if (!top)
	{	
		top = new_card;
		return true;
	}
	else if (!bottom)
	{
		bottom = new_card;
		bottom->set_next(top);
		return true;
	}
	else
	{
		if (top->next == bottom)
		{
			new_card->set_next(bottom);
			top->set_next(new_card);
			return true;
		}
		new_card->set_next(top->get_next());
		top->set_next(new_card);
		return true;
	}
	return false;
}
