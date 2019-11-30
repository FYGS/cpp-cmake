// -*- explicit-buffer-name: "Net.h<M1-MOBJ/4-5>" -*-

#ifndef NET_H
#define NET_H

#include <iostream>
#include "Indentation.h"
#include "Term.h"

namespace Netlist
{
class Term;
class Node;
class Cell;

class Net
{
public:
  Net(Cell *, const std ::string &name, Term ::Type dir);
  //Net(Instance *, const std ::string &name, Term ::Type dir);
  ~Net();

private:
  // Net(const Net &);
  // ...

public:
  Cell *getCell() const;
  const std ::string &getName() const;
  unsigned int getId() const;
  Term ::Type getType() const;
  Node *getNode(size_t id) const;
  const std ::vector<Node *> &getNodes() const;
  size_t getFreeNodeId() const;
  void add(Node *);
  bool remove(Node *);

  void toXml(std::ostream& os );

private:
  Cell *owner_;
  std ::string name_;
  unsigned int id_;
  Term ::Type type_;
  std ::vector<Node *> nodes_;
};

} // namespace Netlist

#endif // NET_H