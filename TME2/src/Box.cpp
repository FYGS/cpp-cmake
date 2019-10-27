//#include <algorithm>
#include "Box.h"

//using namespace tme2;
using namespace std;

 // initialisation variable de classe
 size_t Box::boxAllocateds_ = 0;

 size_t  Box::boxAllocateds() { return boxAllocateds_; }

 // constructeurs
 Box::Box()
 :name_("Unknown"), x1_(1), y1_(1), x2_(-1), y2_(-1)
 {
  /*cout << "Debug: Box::Box() <\"" << name_ << "\" [" << x1_ << " " << y1_ << " " << x2_ << " " << y2_ << "]>" << endl;*/
  cout << "Debug: Box::Box() ";
  cout << *this;
  
  ++boxAllocateds_;
 }
 
 Box::Box( const string& name, long x1, long y1, long x2, long y2 )
 :name_(name), x1_(x1), y1_(y1), x2_(x2), y2_(y2)
 {
  /*cout << "Debug: Box::Box( const std:string& name, long x1, long y1, long x2, long y2 ) <\"" << name_ << "\" [" << x1_ << " " << y1_ << " " << x2_ << " " << y2_ << "]>" << endl;*/
  cout << "Debug: Box::Box( const std:string& name, long x1, long y1, long x2, long y2 ) ";
  cout << *this;
  
  if (x1 > x2) swap( x1_, x2_ );
  if (y1 > y2) swap( y1_, y2_ );
  
  ++boxAllocateds_;
 }
 
 
 Box::Box( const Box& other )
 :name_(other.getName() + "_c"), x1_(other.getX1()), y1_(other.getY1()), x2_(other.getX2()), y2_(other.getY2())
 {
  /*cout << "Debug: Box::Box( const Box& other ) from <\"" << other.getName() << "\" [" << other.getX1() << " " << other.getY1() << " " << other.getX2() << " " << other.getY2() << "]>" << endl;*/
  
  cout << "Debug: Box::Box( const Box& other ) " << *this << " from " << other;
  
 }
    
 Box::~Box()
 {
  /*cout << "Debug: ~Box::Box() <\"" << name_ << "\" [" << x1_ << " " << y1_ << " " << x2_ << " " << y2_ << "]>" << endl;*/
  
  cout << "Debug: ~Box::Box() " << *this;
  
  if(boxAllocateds_ > 0) --boxAllocateds_;
 }
 
 bool Box::intersect(const Box& box2) {
  if (this->isEmpty() || box2.isEmpty()) return false;
  if (  (this->x2_ <= box2.getX1())
     && (this->x1_ >= box2.getX2())
     && (this->y2_ <= box2.getY1())
     && (this->y1_ >= box2.getY2()) ) return false;
  return true;
 }
    
 void Box::print(ostream& sortie) const {
  sortie << "<\"" << this->name_ << "\" [" << this->x1_ << " " << this->y1_ << " " << this->x2_ << " " << this->y2_ << "]>" << endl;
 }
    
    void Box::makeEmpty() {
      this->setName("Unknown");
      this->setX1(1);
      this->setY1(1);
      this->setX2(-1);
      this->setY2(-1);
    }
    
    
    Box& Box::inflate(long dxy) {
      return inflate(dxy, dxy, dxy, dxy);
    }
    
    Box& Box::inflate(long dx, long dy) {
      return inflate(dx, dy, dx, dy);
    }
    
    Box& Box::inflate(long dx1, long dy1, long dx2, long dy2) {
      this->x1_ -= dx1;
      this->y1_ -= dy1;
      this->x2_ += dx2;
      this->y2_ += dy2;

      return (*this);
    }
    
    Box Box::getIntersection(const Box& box2) {
      
      if (! this->intersect(box2)) return Box();
  
      Box box;
      
      box.setName(this->name_ + "." + box2.getName());
      box.setX1(max( this->x1_, box2.getX1() ));
      box.setY1(max( this->y1_, box2.getY1() ));
      box.setX2( min( this->x2_, box2.getX2() ));
      box.setY2( min( this->y2_, box2.getY2() ));
      
      return box;
    }
