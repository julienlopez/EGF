#include "constante.hpp"

Constante::Constante(double d): MonomeSimple(d)
{}

Constante::~Constante()
{}

Constante* Constante::derivee(Variable*) const
{
    return new Constante(0);
}

MonomeSimple* Constante::primitive(Variable* v) const
{
    return new MonomeSimple(v, multiplicateur());
}

Constante* Constante::clone() const
{
    return new Constante(*this);
}

void Constante::afficher(std::ostream& o) const
{
    o << multiplicateur();
}

Constante::operator double() const
{
    return multiplicateur();
}

bool Constante::operator == (const Constante& c) const
{
    return multiplicateur() == c.multiplicateur();
}

Constante::Constante(const Constante& c): MonomeSimple(c.multiplicateur())
{}
