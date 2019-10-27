#include "Conteneurs.hpp"
#include "Timer.h"

#include <iostream>

using namespace vector_bench;
using namespace std;

int main ( int argc, char* argv[] )
{
  Timer timer;

  timer.start();
  backInsert    ();
  timer.stop();

  cout << "vector_bench::backInsert() : " << timer << endl;
  
  timer.start();
  frontInsert   ();
  timer.stop();

  cout << "vector_bench::frontInsert() : " << timer << endl;
  
  timer.start();
  sortEachInsert();
  timer.stop();

  cout << "vector_bench::sortEachInsert() : " << timer << endl;

  // list
  timer.start();
  list_bench::backInsert();
  timer.stop();

  cout << "list_bench::backInsert() : " << timer << endl;

  timer.start();
  list_bench::frontInsert   ();
  timer.stop();

  cout << "vector_bench::frontInsert() : " << timer << endl;
  
  timer.start();
  list_bench::sortEachInsert();
  timer.stop();

  cout << "vector_bench::sortEachInsert() : " << timer << endl;

  map_bench::findOccurrence();

  return 0;
}