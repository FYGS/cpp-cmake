#include "Conteneurs.hpp"
#include "GPL_2_text.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm> // sort
#include <iostream>

using namespace std;

// vector
void vector_bench::backInsert() {
  vector<string> tab_vector;

  int i = 0;
  while (GPL_2_text[i] != "NULL")
  {
    tab_vector.push_back(GPL_2_text[i]);
    i++;
  }

  cout << "tab_vector size (nombre d'éléments): " << tab_vector.size() << endl;
  
  sort(tab_vector.begin(), tab_vector.end());

  cout << "tab_vector trié: " << endl;
  for(const string& str : tab_vector) {
    cout << str << " ";
    if(str == "NULL") cout << endl << endl;
  }
}

void vector_bench::frontInsert() {
  vector<string> tab_vector;

  int i = 0;
  while (GPL_2_text[i] != "NULL")
  {
    tab_vector.insert(tab_vector.begin(), GPL_2_text[i]);
    i++;
  }

  cout << "tab_vector size (nombre d'éléments): " << tab_vector.size() << endl;
  
  sort(tab_vector.begin(), tab_vector.end());

  cout << "tab_vector trié: " << endl;
  for(const string& str : tab_vector) {
    cout << str << " ";
    if(str == "NULL") cout << endl << endl;
  }
  
}

void vector_bench::sortEachInsert() {
  vector<string> tab_vector;

  int i = 0;
  while (GPL_2_text[i] != "NULL")
  {
    tab_vector.push_back(GPL_2_text[i]);
    sort(tab_vector.begin(), tab_vector.end());
    i++;
  }

  cout << "tab_vector size (nombre d'éléments): " << tab_vector.size() << endl;

  cout << "tab_vector trié: " << endl;
  for(const string& str : tab_vector) {
    cout << str << " ";
    if(str == "NULL") cout << endl << endl;
  }
}

// list
void list_bench::backInsert() {
  list<string> tab_vector;

  int i = 0;
  while (GPL_2_text[i] != "NULL")
  {
    tab_vector.push_back(GPL_2_text[i]);
    i++;
  }

  cout << "tab_vector size (nombre d'éléments): " << tab_vector.size() << endl;
  
  tab_vector.sort();

  cout << "tab_vector trié: " << endl;
  for(const string& str : tab_vector) {
    cout << str << " ";
    if(str == "NULL") cout << endl << endl;
  }
}

void list_bench::frontInsert() {
  list<string> tab_vector;

  int i = 0;
  while (GPL_2_text[i] != "NULL")
  {
    tab_vector.push_front(GPL_2_text[i]);
    i++;
  }

  cout << "tab_vector size (nombre d'éléments): " << tab_vector.size() << endl;
  
  tab_vector.sort();

  cout << "tab_vector trié: " << endl;
  for(const string& str : tab_vector) {
    cout << str << " ";
    if(str == "NULL") cout << endl << endl;
  }
  
}

void list_bench::sortEachInsert() {
  list<string> tab_vector;

  int i = 0;
  while (GPL_2_text[i] != "NULL")
  {
    tab_vector.push_back(GPL_2_text[i]);
    tab_vector.sort();
    i++;
  }

  cout << "tab_vector size (nombre d'éléments): " << tab_vector.size() << endl;

  cout << "tab_vector trié: " << endl;
  for(const string& str : tab_vector) {
    cout << str << " ";
    if(str == "NULL") cout << endl << endl;
  }
}

// map
void map_bench::findOccurrence() {
  map<string, int> tab_vector;

  map<string, int>::const_iterator it;
  int compteur = 0;

  int i = 0;
  while (GPL_2_text[i] != "NULL")
  {
    tab_vector.find(GPL_2_text[i]);

    if (it != tab_vector.end()) // found
    {
      // incrémenter compteur
      ++compteur;
      // it->second = compteur;
    }
    else
    {
      tab_vector.insert({GPL_2_text[i], 1});
    }

    tab_vector.insert({GPL_2_text[i], compteur});
    

    i++;
  }

  cout << "tab_vector size (nombre d'éléments): " << tab_vector.size() << endl;
  
  int nombre_mot = 0;

  for(auto itr = tab_vector.begin(); itr != tab_vector.end(); ++itr) {
    cout << itr->first << ":" << itr->second << " ";
    nombre_mot += itr->second;
  }

  cout << "\nLe nombre de mot du texte : " << nombre_mot << endl;
}