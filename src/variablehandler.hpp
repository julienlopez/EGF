#ifndef __VARIABLE_HANDLER_HPP__
#define __VARIABLE_HANDLER_HPP__

#include <Variable>
#include <Singleton>

class VariableHandler : public Singleton<VariableHandler>
{
	friend class Singleton<VariableHandler>;
public:
	static Variable* getVariable(uchar);
	static void addVariable(Variable* v);

	~VariableHandler();

private:
	Variable::type_map m_variables;

	VariableHandler();
	VariableHandler(const VariableHandler& vh);
	VariableHandler& operator=(const VariableHandler& vh);
};

#endif
