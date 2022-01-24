// Kobe Norcross; CS 202; deck.cpp
/*
*/



#include "deck.h"



node::node() : next(nullptr), atk(nullptr), def(nullptr), spl(nullptr) {}



node::node(attack*& new_card)
{
	atk = new_card;
}



node::node(defense*& new_card)
{
	def = new_card;
}



node::node(spell*& new_spl)
{
	spl = new_spl;
}



node*& node::get_next()
{
	return next;
}



void node::set_next(node*& source)
{
	next = source;
}



int node::get_type() const
{
	if (atk) return 0;
	if (def) return 1;
	return 2;
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
	char* type;
	string new_name, new_quip;
	int new_card_value;
	
	if (input.good())
	{
		while (!input.eof())		
		{
			// input type and implement checks in order to see what vals to put
			type = new char[4];
			input.getline(type, MAX, ';');
			input.getline(new_name, MAX, ';');
			input >> new_card_value;

			if (strcmp(type, TYPES[0])
			{
				attack* new_atk_card(type, new_name, new_card_value);
				add(new node(new_atk_card));
			}
			else if (strcmp(type, TYPES[1])
			{
				defense* new_def_card(type, new_name, new_card_value);
				add(new node(new_def_card));
			}
			else
			{
				input.get();				// gets the extra semi colon
				input.getline(new_quip, MAX, '\n');
				spell* new_spl_card(type, new_name, new_card_value, new_quip);
				add(new node(new_spl_card));
			}
			delete type;
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



/*
	This function will be called by a wrapper function from the game class.
	Psuedo Code:
	get a random traversal value;
	return the call to the recursive function;	
*/
node*& deck::draw_card()
{
	int traversal = random(1, num_cards);
	return draw_card(top, top->next, traversal-1);
}



/*
	This function is the recursive call of the draw_card function.
	Psuedo Code:
	base case check: if traversal == 0
		set the previous node to curr->next;
		if (curr node == bottom node)
			set the previous node to bottom
		// don't need to delete the node since I'm going to use it in the hand
		return current node;
	return draw_card(curr, curr->get_next(), traversal-1);
*/
node*& deck::draw_card(node*& prev, node*& curr, traversal)
{
	if (traversal == 0)
	{
		prev->set_next(curr->get_next());
		if (curr->get_next() == bottom)
		{
			prev = bottom;
		}
		curr->set_next(nullptr);
		return curr;		
	}
	return draw_card(curr, curr->get_next(), traversal-1);
}



int random(int min, int max) 
{
	static bool first = true;
	if (first)
	{
		srand(time(nullptr));
		first = false;
	}
	return min + rand() %((max + 1) - min);	
}
