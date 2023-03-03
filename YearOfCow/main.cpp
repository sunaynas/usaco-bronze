#include <bits/stdc++.h>
using namespace std;

bool dbg = true;

// map<string, int> CMAP = {
//     {"Ox", 0},      {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3},
//     {"Snake", 4},   {"Horse", 5}, {"Goat", 6},   {"Monkey", 7},
//     {"Rooster", 8}, {"Dog", 9},   {"Pig", 10},   {"Rat", 1},

// };

int converter(string animal) {
  //  return CMAP[animal];
  if (animal == "Ox") {
    return 0;
  }
  if (animal == "Tiger") {
    return 1;
  }
  if (animal == "Rabbit") {
    return 2;
  }
  if (animal == "Dragon") {
    return 3;
  }
  if (animal == "Snake") {
    return 4;
  }
  if (animal == "Horse") {
    return 5;
  }
  if (animal == "Goat") {
    return 6;
  }
  if (animal == "Monkey") {
    return 7;
  }
  if (animal == "Rooster") {
    return 8;
  }
  if (animal == "Dog") {
    return 9;
  }
  if (animal == "Pig") {
    return 10;
  }
  if (animal == "Rat") {
    return 11;
  }
}
int delta(int starterpos, string starterAnimal, string mAnimal, string jux) {
  int ret;
  bool nxt = jux == "next";
  if (converter(starterAnimal) > converter(mAnimal)) {
    if (nxt) {
      ret = 12 - converter(starterAnimal) + converter(mAnimal);
    } else {
      ret = -converter(starterAnimal) + converter(mAnimal);
    }
  } else if (converter(starterAnimal) == converter(mAnimal)) {
    if (nxt) {
      return 12;
    } else {
      return -12;
    }
  } else {  // if starter is before
    if (nxt) {
      ret = -converter(starterAnimal) + converter(mAnimal);
    } else {
      ret = -12 - converter(starterAnimal) + converter(mAnimal);
    }
  }

  // if (starterpos < 0 || (starterpos == 0 && !nxt)) {
  //   return -ret;
  // } else
  return ret;
}

#ifndef TESTING
int main() {
  map<string, int> cows;  // storing cows age in relation to hesse
  map<string, string> cowAnimal;
  int n;
  cin >> n;
  cows["Bessie"] = 0;
  cowAnimal["Bessie"] = "Ox";
  for (int i = 0; i < n; i++) {
    //"Mildred born in next Dragon year from Bessie"
    string newcow, garb, jux, animal, oldcow;
    cin >> newcow >> garb >> garb >> jux >> animal >> garb >> garb >> oldcow;
    // put it in the array by finding old cow
    cowAnimal[newcow] = animal;
    auto starterpos = cows[oldcow];
    auto starterAnimal = cowAnimal[oldcow];
    cows[newcow] = starterpos + delta(starterpos, starterAnimal, animal, jux);
    if (newcow == "Elsie") {
      break;
    }
  }
  cout << abs(cows["Elsie"] - cows["Bessie"]) << endl;
  return 0;
}
#endif