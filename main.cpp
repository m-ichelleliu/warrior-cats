#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

struct Cat {
  string name;
  string prefix;
  string suffix;
  int moons_old;
  string gender;
  string clan;
  string position;
  string color;
  string pattern;
  string eyes;
};

int main() {
  srand (time(0));
  ifstream fin;

  fin.open("prefixes");
  const int prefix_num = 281;
  string prefixes[prefix_num];
  for (int i = 0; i < prefix_num; i++) {
    fin >> prefixes[i];
  }
  fin.close();
  
  fin.open("suffixes");
  const int suffix_num = 104;
  string suffixes[suffix_num];
  for (int i = 0; i < suffix_num; i++) {
    fin >> suffixes[i];
  }
  fin.close();

  fin.open("colors");
  const int color_num = 21;
  string colors[color_num];
  for (int i = 0; i < color_num; i++) {
    getline(fin, colors[i]);
  }
  fin.close();

  fin.open("patterns");
  const int pattern_num = 8;
  string patterns[pattern_num];
  for (int i = 0; i < pattern_num; i++) {
    fin >> patterns[i];
  }
  fin.close();

  const int cat_num = 100;
  Cat cats[cat_num];

  // assign traits

  for (int i = 0; i < cat_num; i++) {
    cats[i].prefix = prefixes[rand() % prefix_num];
    cats[i].suffix = suffixes[rand() % suffix_num];
    cats[i].name = cats[i].prefix + cats[i].suffix;
    cats[i].pattern = patterns[rand() % pattern_num];
    cats[i].eyes = colors[rand() % color_num];
    cats[i].color = colors[rand() % color_num];
    if (cats[i].color == "bright green") {
      i--; // if the cat's fur is bright green then it will redetermine its traits
    }
    if (cats[i].eyes == "white") {
      i--;
    }
    if (rand() % 2 == 0) {
      cats[i].gender = "tom";
    } else {
      cats[i].gender = "she-cat";
    }
  }

  // assigning .positions

  for (int i = 0; i < cat_num; i++) {
    if (i % 25 == 0) {
      cats[i].position = "Leader";
      cats[i].suffix = "star";
    } else if (i % 25 == 1) {
      cats[i].position = "Deputy";
    } else if (i % 25 == 2) {
      cats[i].position = "Medicine Cat";
    } else if (i % 25 == 3) {
      cats[i].position = "Medicine Cat Apprentice";
      cats[i].suffix = "paw";
    } else if (i % 25 >= 4 && i % 25 < 14) {
      cats[i].position = "Warrior";
    } else if (i % 25 >= 14 && i % 25 < 19) {
      cats[i].position = "Apprentice";
      cats[i].suffix = "paw";
    } else if (i % 25 >= 19 && i % 25 < 22) {
      cats[i].position = "Queen";
      cats[i].gender = "she-cat";
    } else if (i % 25 >= 22 && i % 25 < 25) {
      cats[i].position = "Elder";
    }
  }

  // print positions

  string clans[] = {"ThunderClan", "ShadowClan", "RiverClan", "WindClan"};
  int clan_print_index = 0;

  for (int i = 0; i < cat_num; i++) {
    if (i % 25 == 0) {
      cout << endl << clans[clan_print_index] << ":" << endl;
      clan_print_index++;
      cout << "Leader: " << endl;
    } else if (i % 25 == 1) {
      cout << "Deputy: " << endl;
    } else if (i % 25 == 2) {
      cout << "Medicine Cat: " << endl;
    } else if (i % 25 == 3) {
      cout << "Medicine Cat Apprentice: " << endl;
    } else if (i % 25 == 4) {
      cout << "Warriors: " << endl;
    } else if (i % 25 == 14) {
      cout << "Apprentices: " << endl;
    } else if (i % 25 == 19) {
      cout << "Queens: " << endl;
    } else if (i % 25 == 22) {
      cout << "Elders: " << endl;
    }
    cout << cats[i].prefix << cats[i].suffix;
    if (cats[i].position == "Leader" || cats[i].position == "Medicine Cat Apprentice" || cats[i].position == "Apprentice")    {
      cout << " (" << cats[i].name << ")";
    }
    cout << ", a";
    switch (cats[i].color[0]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      cout << "n";
    }
    cout << " " << cats[i].color << " " << cats[i].pattern << " " << cats[i].gender << " with " << cats[i].eyes << " eyes" << endl;
  }
}
