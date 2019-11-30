// -*- explicit-buffer-name: "Net.h<M1-MOBJ/4-5>" -*-

#include "Term.h"
#include "Node.h"
#include "Cell.h"
#include "Net.h"

namespace Netlist
{

using namespace std;

Net::Net(Cell *owner, const string &name, Term ::Type dir)
    : owner_(owner),
      name_(name),
      id_(owner->newNetId()),
      type_(dir),
      nodes_()
{
  owner->add(this);
}

Net::~Net()
{
  if (getCell())
    owner_->remove(this);

  while (not nodes_.empty())
    delete *(nodes_.begin());
}

Cell *Net::getCell() const { return owner_; }

const string &Net::getName() const { return name_; }

unsigned int Net::getId() const { return id_; }

Term ::Type Net::getType() const { return type_; }

Node *Net::getNode(size_t id) const
{

  for (vector<Node *>::const_iterator inode = nodes_.begin(); inode != nodes_.end(); ++inode)
  {
    if ((*inode)->getId() == id)
    {
      return *inode;
    }
  }

  return NULL;
}

const vector<Node *> &Net::getNodes() const { return nodes_; }

size_t Net::getFreeNodeId() const
{
  for (size_t inode = 0; inode < nodes_.size(); ++inode)
  {
    if (nodes_[inode] == NULL)
      return inode;
  }

  return getNodes().size();
}

void Net::add(Node *newNode)
{
  for (vector<Node *>::iterator inode = nodes_.begin(); inode != nodes_.end(); ++inode)
  {
    if ((*inode)->getId() == newNode->getId())
    {
      cerr << "[ERROR] Attempt to add duplicated node <" << newNode->getId() << ">." << endl;
      exit(1);
    }
  }

  size_t i = getFreeNodeId();
  nodes_[i] = newNode;
  newNode->setId(i);
}

bool Net::remove(Node *nodeToRemove)
{

  for (vector<Node *>::iterator inode = nodes_.begin(); inode != nodes_.end(); ++inode)
  {
    if (*inode == nodeToRemove)
    {
      delete nodeToRemove; // Il s'agit ici non pas d'un 'remove' comme on a fait avec les autres vecteurs (erase)
      *inode = NULL;       // mais de retirer l'element souhaite du tableau et le remplace par le pointeur NULL.
      return true;
    }
  }

  return false;
}

void Net::toXml(std::ostream &os)
{
  os << indent << "<net name=\"" << getName() << "\" type=" << Term::toString(getType()) << "/>\n";
  if (nodes_.empty())
    os << indent << "</net>\n";
  else
  {
    os << ++indent;
    for (vector<Node *>::iterator inode = nodes_.begin(); inode != nodes_.end(); ++inode)
    {
      (*inode)->toXml(os);
    }
    os << --indent;
    os << indent << "</net>\n";
  }
}

} // namespace Netlist