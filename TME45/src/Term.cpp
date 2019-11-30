#include "Node.h"
#include "Net.h"
#include "Term.h"
#include "Instance.h"

namespace Netlist
{

using namespace std;

Term::Term(Cell *cell, const string &name, Direction direction)
    : owner_(cell),
      name_(name),
      direction_(direction),
      type_(External),
      net_(NULL),
      node_(this, Node::noid)
{
  cell->add(this);
}

Term::Term(Instance *instance, const Term *modelTerm)
    : owner_(instance),
      name_(modelTerm->getName()),
      direction_(modelTerm->getDirection()),
      type_(Internal),
      net_(NULL),
      node_(this, Node::noid)
{
  instance->add(this);
}
Term::~Term()
{
  if (isInternal())
    static_cast<Instance *>(owner_)->remove(this);
  static_cast<Cell *>(owner_)->remove(this);
}

string Term::toString(Type type)
{
  string type_temp;
  type_temp = ((type == Internal) ? "Internal" : "External");

  return type_temp;
}

string Term::toString(Direction direction)
{
  string direction_temp;

  switch (direction)
  {
  case In:
    direction_temp = "In";
    break;
  case Out:
    direction_temp = "Out";
    break;
  case InOut:
    direction_temp = "InOut";
    break;
  case Tristate:
    direction_temp = "Tristate";
    break;
  case Transcv:
    direction_temp = "Transcv";
    break;
  case Unknown:
    direction_temp = "Unknown";
    break;

  default:
    direction_temp = "Unknown";
    break;
  }

  return direction_temp;
}

Term::Direction Term::toDirection(string direction)
{
  Direction direction_temp;

  if (direction == "In")
    direction_temp = In;
  if (direction == "Out")
    direction_temp = Out;
  if (direction == "InOut")
    direction_temp = InOut;
  if (direction == "Tristate")
    direction_temp = Tristate;
  if (direction == "Transcv")
    direction_temp = Transcv;
  else
    direction_temp = Unknown;

  return direction_temp;
}

Cell *Term::getOwnerCell() const { return isExternal() ? static_cast<Cell *>(owner_) : static_cast<Instance *>(owner_)->getCell(); }

void Term::setNet(Net *net)
{
  //net_ = net;
  size_t nodeId = node_.getId();
  auto nodes = net->getNodes();
  
  auto inode = nodes.begin();

  bool found = false;

  if(nodeId != Node::noid)
    net_->add(net->getNode(nodeId));
  else
  {
    for (; inode != nodes.end(); ++inode)
    {
      if(*inode == NULL) {
        found = true;
        net_->add(net->getNode((*inode)->getId()));
        break;
      }
    }

    if(not found) net_->add(net->getNode((net->getNodes()).size()));

    
  }
  
}

void Term::setNet(const string &netName)
{
  Net *netTmp = getOwnerCell()->getNet(netName);
  if (netTmp == NULL)
  {
    Net *newNet = new Net(getOwnerCell(), netName, getType());
    setNet(newNet);
  }
  else
  {
    setNet(netTmp);
  }
}

void Term::setPosition(const Point &point)
{
  node_.setPosition(point);
}

void Term::setPosition(int x, int y)
{
  node_.setPosition(x, y);
}

inline void Term::setDirection(Direction direction)
{
  direction_ = direction;
}

void Term::toXml(std::ostream& os ) {
  os << indent << "<term name=\"" << getName() << "\" direction=" << toString(getDirection()) << "/>\n";
}
} // namespace Netlist