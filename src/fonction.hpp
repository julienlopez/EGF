#ifndef __FONCTION_HPP__
#define __FONCTION_HPP__

#include <Variable>

class Fonction
{
public:
	virtual ~Fonction();
	
	virtual Fonction* derivee(Variable* v) const =0;
	virtual Fonction* primitive(Variable* v) const =0;
	
private:
	Variable::type_set m_variables;
};

#endif
