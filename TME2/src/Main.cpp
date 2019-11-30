
#include "Box.h"

using namespace std;
//using namespace tme2;

Box testFunction ( Box ab )
{
  cerr << "  + testFunction() called.\n";

  Box area( "area", 0, 0, 15, 50 );

  if (area.intersect(ab)) {
	  cerr << "  | Intersection between:\n";
    cerr << "  |   " << area << "\n";
    cerr << "  |   " << ab << "\n";
    cerr << "  | Gives:\n";
  
    cerr << "  |   " << area.getIntersection( ab ) << endl;
    //boxDelete( intersection ); // désalouer
  } else {
    cerr << "  No intersection.\n";
  }
  
  //boxDelete(area); // désalouer
  return ab;
}


int  main ( int argc, char* argv[] )
{
  {
    Box b0;
  Box b1( "b1", 15, 10, 30, 20 );

  //cerr << "Allocated boxes: " << Box::boxAllocateds() << endl;

  cerr << "\nTest 1\n";
  cerr << b1 << "\n";
  testFunction( b1 );

  cerr << "\nTest 2\n";
  b1.inflate( 5, 5, 5, 5 );
  cerr << b1 << "\n";
  testFunction( b1 );

  cerr << "\nTest 3\n";
  cerr << "+ Box \"" << b1.getName() << "\" empty:  " << boolalpha << b1.isEmpty() << endl;
  cerr << "| Box \"" << b1.getName() << "\" width:  " << b1.getWidth() << endl;
  cerr << "| Box \"" << b1.getName() << "\" height:  " << b1.getHeight() << endl;
  b1.inflate( -11 );
  cerr << "+ Box \"" << b1.getName() << "\" empty:  " << boolalpha << b1.isEmpty() << " (inflated -11)" << endl;
  cerr << "| Box \"" << b1.getName() << "\" width:  " << b1.getWidth() << endl;
  cerr << "| Box \"" << b1.getName() << "\" height:  " << b1.getHeight() << endl;
  }


  //cerr << "Allocated boxes: " << Box::boxAllocateds() << endl;
  return 0;

}
