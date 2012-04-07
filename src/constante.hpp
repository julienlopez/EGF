#ifndef __CONSTANTE_HPP__
#define __CONSTANTE_HPP__

#include <MonomeSimple>

class Constante : public MonomeSimple
{
public:
    Constante(double d);
    virtual ~Constante();

	virtual Constante* derivee(Variable* v) const;
	virtual MonomeSimple* primitive(Variable* v) const;

	virtual Constante* clone() const;

	virtual void afficher(std::ostream& o) const;

	operator double() const;

private:
    double m_valeur;
    Constante(const Constante& s);
};

#endif // __CONSTANTE_HPP__

