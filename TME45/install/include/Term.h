// -*- explicit-buffer-name: "Term.h<M1-MOBJ/4-5>" -*-

#ifndef TERM_H
#define TERM_H

#include <iostream>
#include "Indentation.h"
#include "Point.h"
#include "Cell.h"
#include "Node.h"

namespace Netlist
{

class Net;
class Node;
class Instance;

class Term
{
public:
  enum Type
  {
    Internal = 1,
    External = 2
  };
  enum Direction
  {
    In = 1,
    Out = 2,
    InOut = 3,
    Tristate = 4,
    Transcv = 5,
    Unknown = 6
  };

  static std::string toString(Type);
  static std::string toString(Direction);
  static Direction toDirection(std::string);

public:
  Term(Cell *, const std ::string &name, Direction);
  Term(Instance *, const Term *modelTerm);
  ~Term();

  inline bool isInternal() const;
  inline bool isExternal() const;
  inline const std ::string &getName() const;
  inline Node *getNode();
  inline Net *getNet() const;
  inline Cell *getCell() const;
  Cell *getOwnerCell() const;
  inline Instance *getInstance() const;
  inline Direction getDirection() const;
  inline Point getPosition() const;
  inline Type getType() const;

  void setNet(Net *);
  void setNet(const std ::string &);
  void setPosition(const Point &);
  void setPosition(int x, int y);
  inline void setDirection(Direction);

  void toXml(std::ostream& os );

private:
  void *owner_;
  std ::string name_;
  Direction direction_;
  Type type_;
  Net *net_;
  Node node_;
};

inline bool Term::isInternal() const { return type_ == Internal; }
inline bool Term::isExternal() const { return type_ == External; }

inline const std::string &Term::getName() const { return name_; }

inline Node *Term::getNode() { return &node_; }
inline Net *Term::getNet() const { return net_; }

inline Cell *Term::getCell() const { return isExternal() ? static_cast<Cell *>(owner_) : NULL; }

inline Instance *Term::getInstance() const { return isInternal() ? static_cast<Instance *>(owner_) : NULL; }

inline Term::Direction Term::getDirection() const { return direction_; }
inline Point Term::getPosition() const { return node_.getPosition(); }
inline Term::Type Term::getType() const { return type_; }

} // namespace Netlist

#endif // TERM_H