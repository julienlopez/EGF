#include "variable.hpp"

Variable::type_set Variable::s_variables;

bool Variable::Cle::operator()(const Variable* v1, const Variable* v2) const
{
	return v1->nom() < v2->nom();
}

uchar Variable::nom() const
{
	return 'x';
}
