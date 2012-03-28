#include "variable.hpp"

Variable::type_map Variable::s_variables;

bool Variable::Cle::operator()(const Variable* v1, const Variable* v2) const
{
	return v1->nom() < v2->nom();
}

uchar Variable::nom() const
{
	return 'x';
}

Variable* Variable::getVariable(uchar c)
{
    for(type_map::const_iterator i = s_variables.begin(); i != s_variables.end(); ++i)
        if(i->first == c) return i->second;
    Variable* v = new Variable(c);
    s_variables[c] = v;
    return v;
}

Variable::Variable()
{}

Variable::Variable(uchar c)
{}

Variable::Variable(const Variable& v)
{}

Variable& Variable::operator=(const Variable& v)
{}
