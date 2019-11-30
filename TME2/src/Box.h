//namespace tme2 {

#ifndef  BOX_H
#define  BOX_H  1

#include <iostream>
#include <algorithm> // min, max
#include <string>


class Box {
  public:
    Box();
    Box( const std::string& name, long x1, long y1, long x2, long y2 );
    Box( const Box& other );
    
    ~Box();
    
    static size_t  boxAllocateds();
    
    inline std::string getName() const;
    inline long getX1() const;
    inline long getY1() const;
    inline long getX2() const;
    inline long getY2() const;
    
    inline void setName(const std::string& str);
    inline void setX1(long x1);
    inline void setY1(long y1);
    inline void setX2(long x2);
    inline void setY2(long y2);
    
    inline long getWidth() const;
    inline long getHeight() const;
    
    inline bool isEmpty() const;
    
    bool intersect(const Box& box);
    
    void print(std::ostream& sortie) const;
    
    void makeEmpty();
    Box& inflate(long dxy);
    Box& inflate(long dx, long dy);
    Box& inflate(long dx1, long dy1, long dx2, long dy2);
    
    Box getIntersection(const Box& box2);
  
  private:
    std::string name_;
    long  x1_;
    long  y1_;
    long  x2_;
    long  y2_;
    
    static size_t boxAllocateds_;
    
};

    std::string Box::getName() const { return name_; }
    long Box::getX1() const { return x1_; }
    long Box::getY1() const { return y1_; }
    long Box::getX2() const { return x2_; }
    long Box::getY2() const { return y2_; }
    
    void Box::setName(const std::string& str) { name_ = str; }
    void Box::setX1(long x1) { x1_ = x1; }
    void Box::setY1(long y1) { y1_ = y1; }
    void Box::setX2(long x2) { x2_ = x2; }
    void Box::setY2(long y2) { y2_ = y2; }
    
    long Box::getWidth() const { return std::max((long)0, x2_ - x1_); }
    long Box::getHeight() const { return std::max((long)0, y2_ - y1_); }
    
    bool Box::isEmpty() const { return (x1_ > x2_) || (y1_ > y2_); }
    
    
    inline std::ostream& operator<< (std::ostream& o, const Box& b) {
      b.print(o); 
      return o;
    }






#endif  // BOX_H

//}//namespace
