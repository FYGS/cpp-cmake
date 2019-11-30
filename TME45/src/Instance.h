// -*- explicit-buffer-name: "Instance.h<M1-MOBJ/4-5>" -*-

#ifndef INSTANCE_H
#define INSTANCE_H

#include <iostream>
#include<vector>
#include "Indentation.h"
//#include "Node.h"
#include "Point.h"
//#include "Cell.h"

namespace Netlist
{

class Point;
class Term;
class Net;
class Cell;

class Instance
{
public:
  Instance(Cell *owner, Cell *model, const std ::string &);
  ~Instance();
  const std ::string &getName() const;
  Cell *getMasterCell() const;
  Cell *getCell() const;
  const std ::vector<Term *> &getTerms() const;
  Term *getTerm(const std ::string &) const;
  Point getPosition() const;

  bool connect(const std ::string &name, Net *);
  void add(Term *);
  void remove(Term *);
  void setPosition(const Point &);
  void setPosition(int x, int y);

  void toXml(std::ostream& os );

private:
  Cell *owner_;
  Cell *masterCell_;
  std ::string name_;
  std ::vector<Term *> terms_;
  Point position_;
};

} // namespace Netlist

#endif // INSTANCE_H