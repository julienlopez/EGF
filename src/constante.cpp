#include "constante.hpp"
#include "monomesimple.hpp"

Constante::Constante(double d): m_valeur(d)
{}

Constante::~Constante()
{}

Constante* Constante::derivee(Variable*) const
{
    return new Constante(0);
}

Fonction* Constante::primitive(Variable* v) const
{
    return new MonomeSimple(v, m_valeur);
}

Constante* Constante::clone() const
{
    return new Constante(*this);
}

void Constante::afficher(std::ostream& o) const
{
    o << m_valeur;
}

Constante::Constante(const Constante& c): m_valeur(c.m_valeur)
{}
