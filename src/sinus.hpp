#ifndef __SINUS_HPP__
#define __SINUS_HPP__

#include <Fonction>

class Sinus : public Fonction
{
public:
    Sinus();
	virtual ~Sinus();

	virtual Sinus* derivee(Variable* v) const;
	virtual Sinus* primitive(Variable* v) const;

	virtual Sinus* clone() const;

	virtual void afficher(std::ostream& o) const;

private:
    Sinus(const Sinus& s);
};


#endif // __SINUS_HPP__

