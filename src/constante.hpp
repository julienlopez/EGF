#ifndef __CONSTANTE_HPP__
#define __CONSTANTE_HPP__

#include <Fonction>

class Constante : public Fonction
{
public:
    Constante(double d);
    virtual ~Constante();

	virtual Constante* derivee(Variable* v) const;
	virtual Fonction* primitive(Variable* v) const;

	virtual Constante* clone() const;

	virtual void afficher(std::ostream& o) const;

private:
    double m_valeur;
    Constante(const Constante& s);
};

#endif // __CONSTANTE_HPP__

