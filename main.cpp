#include "functions.hpp"
#include "zoo-species.hpp"

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(void) {
  vector<Zoo_species *> animals;
  int mp = 0, rp = 0, bp = 0; // three pointers to break the vector

  if (initialize_animals("db.txt", mp, rp, bp, animals) != 0) {
    cout << "Error: db.txt is corrupted, Error in initializing animals" << endl;
    return -1;
  }

  string command;

  while (1) {
    getline(cin, command);

    if (command == "exit") {
      // saving the data
      ofstream ofile("db.txt");

      ofile << "total species " << animals.size() << endl;
      ofile << "mammals " << mp << endl;
      for (int i = 0; i < mp; i++)
        animals[i]->Print(ofile);
      ofile << "reptiles " << rp << endl;
      for (int i = mp; i < mp + rp; i++)
        animals[i]->Print(ofile);
      ofile << "birds " << bp << endl;
      for (int i = mp + rp; i < mp + rp + bp; i++)
        animals[i]->Print(ofile);
      ofile << "aquatics " << animals.size() - mp - rp - bp << endl;
      for (int i = mp + rp + bp; i < animals.size(); i++)
        animals[i]->Print(ofile);

			ofile.close();
      return 1;
    }

    // taknig in first word of command
    istringstream ss(command);
    string cmd;
    ss >> cmd;

    if (cmd == "add") {
      // checking input format
      string type, name, countstr, en, check;
      int count;
      try {
        ss >> ws >> type >> name >> countstr >> en >> ws >> check;

        count = stoi(countstr);

        if (check != "" || type == "" || name == "" || countstr == "" ||
            en == "" || count <= 0) {
          cout << "Error: Invalid command" << endl;
          continue;
        }
      } catch (invalid_argument) {
        cout << "Error: Invalid command" << endl;
        continue;
      }

      // checking type
      if (!(type == "M" || type == "R" || type == "B" || type == "Q")) {
        cout << "Error: Invalid type" << endl;
        continue;
      }

      // checking if animal already exists and incrementing count
			bool flag = false;
      if (type == "M") {
        for (int i = 0; i < mp; i++)
					if (animals[i]->get_name() == name) {
						animals[i]->Set_count(animals[i]->get_count() + count);
						flag = true;
						break;
					}
			} else if (type == "R") {
				for (int i = mp; i < rp + mp; i++)
					if (animals[i]->get_name() == name) {
						animals[i]->Set_count(animals[i]->get_count() + count);
						flag = true;
						break;
					}
			} else if (type == "B") {
				for (int i = rp + mp; i < bp + mp + rp; i++)
					if (animals[i]->get_name() == name) {
						animals[i]->Set_count(animals[i]->get_count() + count);
						flag = true;
						break;
					}
			} else if (type == "Q") {
				for (int i = bp + mp + rp; i < animals.size(); i++)
					if (animals[i]->get_name() == name) {
						animals[i]->Set_count(animals[i]->get_count() + count);
						flag = true;
						break;
					}
			}

			// skip the rest
			if (flag) {
				cout << 0 << endl;
				continue;
			}

      // adding animal
      Zoo_species *a;
      if (type == "M") {
        diet_type dt;
        if (Mammal::get_diet_type(en, dt) != 0) {
          cout << "Error: Invalid diet type" << endl;
          continue;
        }

        a = new Mammal(name, count, dt);
        // inserting in the correct position
        animals.insert(animals.begin() + mp, a);
        mp++;
      } else if (type == "R") {
        feed_size fs;
        // checking reptile feed
        if (Reptile::get_feed_size(en, fs) != 0) {
          cout << "Error: Invalid reptile feed" << endl;
          continue;
        }

        a = new Reptile(name, count, fs);
        // inserting in the correct position
        animals.insert(animals.begin() + rp + mp, a);
        rp++;
      } else if (type == "B") {
        bird_feed bf;
        // checking bird feed
        if (Bird::get_bird_feed(en, bf) != 0) {
          cout << "Error: Invalid bird feed" << endl;
          continue;
        }

        a = new Bird(name, count, bf);
        // inserting in the correct position
        animals.insert(animals.begin() + bp + rp + mp, a);
        bp++;
      } else if (type == "Q") {
        aqua_feed af;
        // checking aquatic feed
        if (Aquatic::get_aqua_feed(en, af) != 0) {
          cout << "Error: Invalid aquatic feed" << endl;
          continue;
        }

        a = new Aquatic(name, count, af);
        animals.push_back(a);
      }

      cout << 0 << endl; // success!
    }

    else if (cmd == "delete") {
      // checking input format
      string type, name, countstr, check;
      int count;
      try {
        ss >> ws >> type >> name >> countstr >> ws >> check;

        count = stoi(countstr);

        if (check != "" || type == "" || name == "" || countstr == "" ||
            count <= 0) {
          cout << "Error: Invalid command" << endl;
          continue;
        }
      } catch (invalid_argument) {
        cout << "Error: Invalid command" << endl;
        continue;
      }

      // checking type
      if (!(type == "M" || type == "R" || type == "B" || type == "Q")) {
        cout << "Error: Invalid type" << endl;
        continue;
      }

      // deleting animal
      bool flag = true;
      if (type == "M") {
        int i;
        for (i = 0; i < mp; i++) {
          if (animals[i]->get_name() == name) {
            if (animals[i]->get_count() < count) {
              cout << "Error: Invalid count" << endl;
              break;
            } else if (animals[i]->get_count() > count) {
              animals[i]->Set_count(animals[i]->get_count() - count);
              flag = false;
              break;
            }
            delete animals[i];
            animals.erase(animals.begin() + i);
            mp--;
            flag = false;
            break;
          }
        }
        if (flag) {
          cout << "Error: Animal not found" << endl;
          continue;
        }
      } else if (type == "R") {
        int i;
        for (i = mp; i < mp + rp; i++) {
          if (animals[i]->get_name() == name) {
            if (animals[i]->get_count() < count) {
              cout << "Error: Invalid count" << endl;
              break;
            } else if (animals[i]->get_count() > count) {
              animals[i]->Set_count(animals[i]->get_count() - count);
              flag = false;
              break;
            }
            delete animals[i];
            animals.erase(animals.begin() + i);
            rp--;
            flag = false;
            break;
          }
        }
        if (flag) {
          cout << "Error: Animal not found" << endl;
          continue;
        }
      } else if (type == "B") {
        int i;
        for (i = mp + rp; i < mp + rp + bp; i++) {
          if (animals[i]->get_name() == name) {
            if (animals[i]->get_count() < count) {
              cout << "Error: Invalid count" << endl;
              break;
            } else if (animals[i]->get_count() > count) {
              animals[i]->Set_count(animals[i]->get_count() - count);
              flag = false;
              break;
            }
            delete animals[i];
            animals.erase(animals.begin() + i);
            bp--;
            flag = false;
            break;
          }
        }
        if (flag) {
          cout << "Error: Animal not found" << endl;
          continue;
        }
      } else if (type == "Q") {
        int i;
        for (i = mp + rp + bp; i < animals.size(); i++) {
          if (animals[i]->get_name() == name) {
            if (animals[i]->get_count() < count) {
              cout << "Error: Invalid count" << endl;
              break;
            } else if (animals[i]->get_count() > count) {
              animals[i]->Set_count(animals[i]->get_count() - count);
              flag = false;
              break;
            }
            delete animals[i];
            animals.erase(animals.begin() + i);
            flag = false;
            break;
          }
        }
        if (flag) {
          cout << "Error: Animal not found" << endl;
          continue;
        }
      }

      cout << 0 << endl; // success!
    }

    else if (cmd == "show") {
      // checking input format
      string type, check;

      ss >> ws >> type >> ws >> check;

      if (check != "" || type == "") {
        cout << "Error: Invalid command" << endl;
        continue;
      }

      // checking type
      if (!(type == "M" || type == "R" || type == "B" || type == "Q" ||
            type == "A")) {
        cout << "Error: Invalid type" << endl;
        continue;
      }

      // showing animals
      if (type == "M") {
        cout << "mammals " << mp << endl;
        for (int i = 0; i < mp; i++)
          animals[i]->Print();
      } else if (type == "R") {
        cout << "reptiles " << rp << endl;
        for (int i = mp; i < mp + rp; i++)
          animals[i]->Print();
      } else if (type == "B") {
        cout << "birds " << bp << endl;
        for (int i = mp + rp; i < mp + rp + bp; i++)
          animals[i]->Print();
      } else if (type == "Q") {
        cout << "aquatics " << animals.size() - mp - rp - bp << endl;
        for (int i = mp + rp + bp; i < animals.size(); i++)
          animals[i]->Print();
      } else if (type == "A") {
        cout << "total species " << animals.size() << endl;
        cout << "mammals " << mp << endl;
        for (int i = 0; i < mp; i++)
          animals[i]->Print();
        cout << "reptiles " << rp << endl;
        for (int i = mp; i < mp + rp; i++)
          animals[i]->Print();
        cout << "birds " << bp << endl;
        for (int i = mp + rp; i < mp + rp + bp; i++)
          animals[i]->Print();
        cout << "aquatics " << animals.size() - mp - rp - bp << endl;
        for (int i = mp + rp + bp; i < animals.size(); i++)
          animals[i]->Print();
      }
    }

    else {
      cout << "Error: Invalid command" << endl;
    }
  }
}
