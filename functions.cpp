#include "functions.hpp"
#include "input-prog.hpp"
#include "zoo-species.hpp"
#include <sstream>
#include <string>

using namespace std;

int initialize_animals(string fileName, int &mp, int &rp, int &bp,
                       vector<Zoo_species *> &animals) {
  vector<string> animalsstr;

  readFile(fileName, animalsstr);

  for (int i = 0; i < animalsstr.size(); i++) {
    // taking mammals
    if (animalsstr[i].find("mammal") != string::npos) {
      animalsstr[i].erase(0, 7);
      int mam = stoi(animalsstr[i]) + i;
      i++;
      for (; i <= mam; i++) {
        istringstream ss(animalsstr[i]);
        string name;
        int count;
        string dt;
        ss >> name >> count >> dt;

        diet_type d;
        if (Mammal::get_diet_type(dt, d) == 0) {
          Zoo_species *m = new Mammal(name, count, d);
          animals.push_back(m);
        } else {
          return -1;
        }

        mp++;
      }
    }

    // taking reptiles
    if (animalsstr[i].find("reptile") != string::npos) {
      animalsstr[i].erase(0, 8);
      int rep = stoi(animalsstr[i]) + i;
      i++;
      for (; i <= rep; i++) {
        istringstream ss(animalsstr[i]);
        string name;
        int count;
        string dt;
        ss >> name >> count >> dt;

        feed_size d;
        if (Reptile::get_feed_size(dt, d) == 0) {
          Zoo_species *r = new Reptile(name, count, d);
          animals.push_back(r);
        } else {
          return -1;
        }

        rp++;
      }
    }

    // taking birds
    if (animalsstr[i].find("bird") != string::npos) {
      animalsstr[i].erase(0, 5);
      int bir = stoi(animalsstr[i]) + i;
      i++;
      for (; i <= bir; i++) {
        istringstream ss(animalsstr[i]);
        string name;
        int count;
        string dt;
        ss >> name >> count >> dt;

        bird_feed d;
        if (Bird::get_bird_feed(dt, d) == 0) {
          Zoo_species *b = new Bird(name, count, d);
          animals.push_back(b);
        } else {
          return -1;
        }

        bp++;
      }
    }

    // taking aquatics
    if (animalsstr[i].find("aquatic") != string::npos) {
      animalsstr[i].erase(0, 8);
      int aqu = stoi(animalsstr[i]) + i;
      i++;
      for (; i <= aqu; i++) {
        istringstream ss(animalsstr[i]);
        string name;
        int count;
        string dt;
        ss >> name >> count >> dt;

        aqua_feed d;
        if (Aquatic::get_aqua_feed(dt, d) == 0) {
          Zoo_species *a = new Aquatic(name, count, d);
          animals.push_back(a);
        } else {
          return -1;
        }
      }
    }
  }

  return 0;
}
