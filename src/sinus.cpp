#include "sinus.hpp"

Sinus::Sinus()
{

}

Sinus::~Sinus()
{

}

Sinus* Sinus::derivee(Variable* v) const
{

}

Sinus* Sinus::primitive(Variable* v) const
{

}

Sinus* Sinus::clone() const
{
    return new Sinus(*this);
}

void Sinus::afficher(std::ostream& o) const
{
    o << "sin(" << ")";
}

Sinus::Sinus(const Sinus& s)
{

}
