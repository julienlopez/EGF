#ifndef __SOMME_HPP__
#define __SOMME_HPP__

#include <Fonction>

class Somme : public Fonction
{
public:
    Somme(Fonction* f1, Fonction* f2);
	virtual ~Somme();

	virtual Somme* derivee(Variable* v) const;
	virtual Somme* primitive(Variable* v) const;

	virtual Somme* clone() const;

	virtual void afficher(std::ostream& o) const;

private:
    Somme(const Somme& s);

    Fonction* m_f1;
    Fonction* m_f2;
};


#endif // __Somme_HPP__

