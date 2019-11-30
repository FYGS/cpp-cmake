// -*- explicit-buffer-name: "Instance.h<M1-MOBJ/4-5>" -*-

#include "Instance.h"
#include "Term.h"
#include "Cell.h"

namespace Netlist
{

  using namespace std;

Instance::Instance(Cell *owner, Cell *model, const string &name)
  :owner_(owner),
   masterCell_(model),
   name_(name),
   terms_(model->getTerms()),
   position_(/*model->getInstance(name)->getPosition()*/) {
     owner->add(this);
   }

Instance::~Instance() {
  if(getCell()) owner_->remove(this);

  while (not terms_.empty()) delete *terms_.begin();
  
}

const string &Instance::getName() const { return name_; }

Cell *Instance::getMasterCell() const { return masterCell_; }

Cell *Instance::getCell() const { return owner_; }

const vector<Term *> &Instance::getTerms() const { return terms_; }

Term *Instance::getTerm(const string &instanceName) const { 
  
  for(vector<Term*>::const_iterator iterm = terms_.begin(); iterm != terms_.end(); ++iterm) {
    if((*iterm)->getName() == instanceName ) return *iterm;
  }
  return NULL;
}

Point Instance::getPosition() const { return position_; }

bool Instance::connect(const string &name, Net *net) {
  Term *term = getTerm(name);

  if(term == NULL) return false;

  term->setNet(net);
  return true;
}
void Instance::add(Term *term) {
  for (vector<Term *>::iterator iterm = terms_.begin(); iterm != terms_.end(); ++iterm)
  {
    if (getTerm(term->getName()))
    {
      cerr << "[ERROR] Attempt to add duplicated term <" << term->getName() << ">." << endl;
      exit(1);
    }
  }

  terms_.push_back(term);
}

void Instance::remove(Term *termToRemove) {
  for(vector<Term*>::iterator iterm = terms_.begin(); iterm != terms_.end(); ++iterm) {
    if(*iterm == termToRemove) {
      terms_.erase(iterm);
    }
  }
}

void Instance::setPosition(const Point &pos) {
  position_ = pos;
}
void Instance::setPosition(int x, int y) {
  //position_.setX(x);
  //position_.setY(y);
  position_ = Point(x, y);
}

void Instance::toXml(std::ostream& os ){
  os << indent << "<instance name=\"" << getName() << "\" mastercell=\"" << getMasterCell()
           << " x=\"" << getPosition().getX()
           << "\" y=\"" << getPosition().getY() << "\"/>\n";
}
} // namespace Netlist