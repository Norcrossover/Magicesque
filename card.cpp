// Kobe Norcross; CS 202; card.cpp
/*
 *
 */


#include "card.h"
using namespace std;



// card card XD (Implementation) 
card::card() : type(nullptr), name() {}



card::card(const char* type, string new_name)
{
	this->type = new char[strlen(type)+1];
	strcpy(this->type, type);
	this->name = new_name;
}



card::~card()
{
	if (type) delete [] type;
	type = nullptr;
}



void card::display() const
{
}



void card::activate_card() 
{
} 



void card::deactivate_card() 
{
}
//-----------------------------------------------------------------------------------------------------------------
// attack card
attack::attack(int atk, const char* type, string new_name) : card(type, new_name), damage(atk) {}



void attack::activate_card() 
{
	active = true;
	cout << "Card " << name << " set!" << endl;
}



void attack::deactivate_card()
{
	active = false;
}



void attack::display() const
{
	cout << "Card Name: " << name << endl;
	cout << "attack damage: " << damage << endl;
}
//-----------------------------------------------------------------------------------------------------------------
// defense card
//defense::defense(const defense& new_defense_card) : card(new_defense_card), shield(new_defense_card.shield) {}



void defense::activate_card() 
{
	active = true;
	cout << "Card " << name << " set!" << endl;
}



void defense::deactivate_card()
{
	active = false;
	shield = 0;
}


void defense::display() const
{
	cout << "Shield amount: " << shield << endl;
}



//-----------------------------------------------------------------------------------------------------------------
// spell card
spell::spell() : damage(0), mana_cost(0), casting_quip(nullptr) {}



spell::spell(int val, int cost, const char* type, string new_name) : card(type, new_name), damage(val), mana_cost(cost) {} 



spell::~spell()
{
	if (casting_quip) delete casting_quip;
	casting_quip = nullptr;
}



void spell::activate_card()
{
	active = true;
	cout << "Card " << name << " set!" << endl;
}



void spell::deactivate_card()
{
	active = false;
}



void spell::display() const
{
	cout << "Card name: " << name << endl;
	cout << casting_quip << "!!!!!!" << endl;
	cout << "Spell damage: " << damage << endl;
}
