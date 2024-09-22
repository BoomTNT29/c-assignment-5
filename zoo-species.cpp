#include "zoo-species.hpp"
#include <iostream>

using namespace std;

Zoo_species::Zoo_species(string name, int count) : Species_name{name}, Species_count{count} {
	// do something
}

int Zoo_species::Set_name(string name) {
	this->Species_name = name;
	return 0;
}

int Zoo_species::Set_count(int count) {
	this->Species_count = count;
	return 1;
}

int Zoo_species::Print() {
	cout << this->Species_name << " " << this->Species_count;
	return 0;
}

string Zoo_species::get_name() {
	return this->Species_name;
}

int Zoo_species::get_count() {
	return this->Species_count;
}

Mammal::Mammal(string name, int count, diet_type dt) : Zoo_species(name, count), Diet_type{dt} {
	// do something
}

int Mammal::Set_diet_type(diet_type dt) {
	this->Diet_type = dt;
	return 0;
}

int Mammal::Print() {
	Zoo_species::Print();
	cout << ' ' << this->get_diet_type() << endl;
	return 0;
}

string Mammal::get_diet_type() {
	// getdiet_type in string format since its very useful
	switch (this->Diet_type) {
		case herbivore:
			return "herbivore";
		case carnivore:
			return "carnivore";
	}
}

Reptile::Reptile(string name, int count, feed_size fs) : Zoo_species(name, count), Feed_size(fs) {
	// do nothing
}

int Reptile::Set_feed_size(feed_size fs) {
	this->Feed_size = fs;
	return 0;
}

int Reptile::Print() {
	Zoo_species::Print();
	cout << ' ' << this->get_feed_size() << endl;
	return 0;
}

string Reptile::get_feed_size() {
	switch(this->Feed_size) {
		case small:
			return "small";
		case medium:
			return "medium";
		case large:
			return "large";
	}
}

Bird::Bird(string name, int count, bird_feed bf) : Zoo_species(name, count), Bird_feed{bf} {
	// do nothing
}

int Bird::Set_bird_feed(bird_feed bf) {
	this->Bird_feed = bf;
	return 0;
}

int Bird::Print() {
	Zoo_species::Print();
	cout << ' ' << this->get_bird_feed() << endl;
	return 0;
}

string Bird::get_bird_feed() {
	switch(this->Bird_feed) {
		case fish:
			return "fish";
		case grain:
			return "grain";
		case insect:
			return "insect";
	}
}

Aquatic::Aquatic(string name, int count, aqua_feed af) : Zoo_species(name, count), Aqua_feed{af} {
	// do nothing
}

int Aquatic::Set_aqua_feed(aqua_feed af) {
	this->Aqua_feed = af;
	return 0;
}

int Aquatic::Print() {
	Zoo_species::Print();
	cout << ' ' << this->get_aqua_feed() << endl;
	return 0;
}

string Aquatic::get_aqua_feed() {
	switch(this->Aqua_feed) {
		case fishfood:
			return "fishfood";
		case livefish:
			return "livefish";
		case plants:
			return "plants";
	}
}

int Aquatic::get_aqua_feed(string st, aqua_feed &aq) {
	if (st == "fishfood") 
}
