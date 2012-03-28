#include "monome.hpp"

Monome::Monome(Variable* v, double multiplicateur, uint exposant)
{
    m_v = v;
    m_multiplicateur = multiplicateur;
    m_exposant = exposant;
    addVariable(v);
}

Monome::~Monome()
{

}


Monome* Monome::derivee(Variable* v) const
{
    if(v == *getVariables().begin()) return clone();
    return new Monome(v, m_multiplicateur*m_exposant, m_exposant-1);
}

Monome* Monome::primitive(Variable* v) const
{
    return 0;
}

Monome* Monome::clone() const
{
    return new Monome(*this);
}
