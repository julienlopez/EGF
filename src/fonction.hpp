#ifndef __FONCTION_HPP__
#define __FONCTION_HPP__

#include <Variable>

#include <iostream>

class Fonction
{
public:
	Fonction(const Fonction& f) =delete;
	virtual ~Fonction();

	virtual Fonction* derivee(Variable* v) const =0;
	virtual Fonction* primitive(Variable* v) const =0;

	virtual Fonction* clone() const = 0;

	const Variable::type_set& getVariables() const;

	virtual void afficher(std::ostream& o) const = 0;

	friend std::ostream& operator<<(std::ostream& o, const Fonction& f);

protected:
	Fonction();
	void addVariable(Variable* v);

private:
	Variable::type_set m_variables;
};

#endif
