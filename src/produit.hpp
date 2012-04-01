#ifndef __PRODUIT_HPP__
#define __PRODUIT_HPP__

#include <Fonction>

class Produit : public Fonction
{
public:
    Produit(Fonction* f1, Fonction* f2);
	virtual ~Produit();

	virtual Produit* derivee(Variable* v) const;
	virtual Produit* primitive(Variable* v) const;

	virtual Produit* clone() const;

	virtual void afficher(std::ostream& o) const;

private:
    Produit(const Produit& s);

    Fonction* m_f1;
    Fonction* m_f2;
};


#endif // __Produit_HPP__

