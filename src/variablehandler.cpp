#include "variablehandler.hpp"

VariableHandler::VariableHandler() 
{}
	
VariableHandler::VariableHandler(const VariableHandler& vh)
{}
	
VariableHandler& VariableHandler::operator=(const VariableHandler& vh)
{
	return *this;
}

Variable* VariableHandler::getVariable(uchar c)
{
	for(auto i = instance().m_variables.begin(); i != instance().m_variables.end(); ++i)
        if(i->first == c) return i->second;
    Variable* v = new Variable(c);
    return v;
}

void VariableHandler::addVariable(Variable* v) {
	instance().m_variables[v->nom()] = v;
}

VariableHandler::~VariableHandler()
{
	for(auto i = m_variables.begin(); i != m_variables.end(); ++i)
		if(i->second) delete i->second;
}
