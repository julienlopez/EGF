#include "somme.hpp"

Somme::Somme(Fonction* f1, Fonction* f2)
{
    m_f1 = f1;
    m_f2 = f2;
    for(auto i = f1->getVariables().begin(); i != f1->getVariables().end(); ++i)
        addVariable(*i);
    for(auto i = f2->getVariables().begin(); i != f2->getVariables().end(); ++i)
        addVariable(*i);
}

Somme::~Somme()
{}

Somme* Somme::derivee(Variable* v) const
{
    return new Somme(m_f1->derivee(v), m_f2->derivee(v));
}

Somme* Somme::primitive(Variable* v) const
{
    return new Somme(m_f1->primitive(v), m_f2->primitive(v));
}

Somme* Somme::clone() const
{
    return new Somme(*this);
}

void Somme::afficher(std::ostream& o) const
{
    m_f1->afficher(o);
    o << " + ";
    m_f2->afficher(o);
}

Somme::Somme(const Somme& s)
{
    m_f1 = s.m_f1;
    m_f2 = s.m_f2;
    for(auto i = m_f1->getVariables().begin(); i != m_f1->getVariables().end(); ++i)
        addVariable(*i);
    for(auto i = m_f2->getVariables().begin(); i != m_f2->getVariables().end(); ++i)
        addVariable(*i);
}
