#include "fonction.hpp"

#include <FonctionHandler>

Fonction::~Fonction()
{}

const Variable::type_set& Fonction::getVariables() const
{
    return m_variables;
}

Fonction::Fonction()
{
	FonctionHandler::addFonction(this);
}

void Fonction::addVariable(Variable* v)
{
    m_variables.insert(v);
}

std::ostream& operator<<(std::ostream& o, const Fonction& f)
{
	f.afficher(o);
	return o;
}

