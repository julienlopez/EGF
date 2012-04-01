#include "produit.hpp"

Produit::Produit(Fonction* f1, Fonction* f2)
{
    m_f1 = f1;
    m_f2 = f2;
    for(auto i = f1->getVariables().begin(); i != f1->getVariables().end(); ++i)
        addVariable(*i);
    for(auto i = f2->getVariables().begin(); i != f2->getVariables().end(); ++i)
        addVariable(*i);
}

Produit::~Produit()
{}

Produit* Produit::derivee(Variable* v) const
{
    return 0; //TODO Produit::derivee
}

Produit* Produit::primitive(Variable* v) const
{
    return 0; //TODO Produit::primitive
}

Produit* Produit::clone() const
{
    return new Produit(*this);
}

void Produit::afficher(std::ostream& o) const
{
    m_f1->afficher(o);
    o << " x ";
    m_f2->afficher(o);
}

Produit::Produit(const Produit& s)
{
    m_f1 = s.m_f1;
    m_f2 = s.m_f2;
    for(auto i = m_f1->getVariables().begin(); i != m_f1->getVariables().end(); ++i)
        addVariable(*i);
    for(auto i = m_f2->getVariables().begin(); i != m_f2->getVariables().end(); ++i)
        addVariable(*i);
}
