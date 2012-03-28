#include "fonction.hpp"

Fonction::~Fonction()
{}

const Variable::type_set& Fonction::getVariables() const
{
    return m_variables;
}

void Fonction::addVariable(Variable* v)
{
    m_variables.insert(v);
}
