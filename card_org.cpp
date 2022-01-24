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
	//cout << "Name: " << name << endl;
}



int card::get_value() const 
{
	return 0;
} 



//-----------------------------------------------------------------------------------------------------------------
// attack card
attack::attack(int atk, const char* type, string new_name) : card(type, new_name), damage(atk) {}



/*
attack::attack(const attack& new_atttack_card) : card(new_atttack_card) 
{
	damage = new_atttack_card.damage;
}
*/



void attack::display() const
{
	cout << "attack damage: " << damage << endl;
}



int attack::get_value() const
{
	return damage;
}



//-----------------------------------------------------------------------------------------------------------------
// defense card
//defense::defense(const defense& new_defense_card) : card(new_defense_card), shield(new_defense_card.shield) {}



int defense::get_value() const
{
	return shield;
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



int spell::get_value() const
{
	return damage;
}



void spell::display() const
{
	cout << casting_quip << "!!!!!!" << endl;
	cout << "Spell damage: " << damage << endl;
}
