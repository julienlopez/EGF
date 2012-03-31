#include "variable.hpp"
#include "variablehandler.hpp"

#include <cassert>

bool Variable::Cle::operator()(const Variable* v1, const Variable* v2) const
{
	return v1->nom() < v2->nom();
}

uchar Variable::nom() const
{
	return m_nom;
}

Variable* Variable::getVariable(uchar c)
{
    return VariableHandler::getVariable(c);
}

Variable::Variable(uchar c): m_nom(c)
{
	VariableHandler::addVariable(this);
}

Variable& Variable::operator=(const Variable& v)
{
	m_nom = v.m_nom;
	return *this;
}
