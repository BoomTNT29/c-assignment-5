#ifndef ZOO_SPECIES_HPP
#define ZOO_SPECIES_HPP

#include <string>
#include <iostream>

using namespace std;

enum diet_type
{
	herbivore,
	carnivore
};
enum feed_size
{
	small,
	medium,
	large
};
enum bird_feed
{
	grain,
	insect,
	fish
};
enum aqua_feed
{
	fishfood,
	livefish,
	plants
};

class Zoo_species
{
protected:
	string Species_name;
	int Species_count;

public:
	Zoo_species(string name, int count);
	virtual ~Zoo_species();

	int Set_name(string name);
	int Set_count(int count);
	virtual int Print(ostream &os=cout);

	string get_name();
	int get_count();
};

class Mammal : public Zoo_species
{
private:
	diet_type Diet_type;

public:
	Mammal(string name, int count, diet_type dt);

	int Set_diet_type(diet_type dt);
	int Print(ostream &os=cout);

	string get_diet_type();
	static int get_diet_type(string, diet_type &); // this converts string to enum
};

class Reptile : public Zoo_species
{
private:
	feed_size Feed_size;

public:
	Reptile(string name, int count, feed_size fs);

	int Set_feed_size(feed_size fs);
	int Print(ostream &os=cout);

	string get_feed_size();
	static int get_feed_size(string, feed_size &); // this converts string to enum
};

class Bird : public Zoo_species
{
private:
	bird_feed Bird_feed;

public:
	Bird(string name, int count, bird_feed bf);

	int Set_bird_feed(bird_feed bf);
	int Print(ostream &os=cout);

	string get_bird_feed();
	static int get_bird_feed(string, bird_feed &); // this converts string to enum
};

class Aquatic : public Zoo_species
{
private:
	aqua_feed Aqua_feed;

public:
	Aquatic(string name, int count, aqua_feed af);

	int Set_aqua_feed(aqua_feed af);
	int Print(ostream &os=cout);

	string get_aqua_feed();
	static int get_aqua_feed(string, aqua_feed &); // this converts string to enum
};

#endif