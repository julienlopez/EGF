#ifndef __FONCTION_HPP__
#define __FONCTION_HPP__

#include <Variable>

class Fonction
{
public:
	virtual ~Fonction();

	virtual Fonction* derivee(Variable* v) const =0;
	virtual Fonction* primitive(Variable* v) const =0;

	virtual Fonction* clone() const = 0;

	const Variable::type_set& getVariables() const;

protected:
	void addVariable(Variable* v);

private:
	Variable::type_set m_variables;
};

#endif
