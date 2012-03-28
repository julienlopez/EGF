#ifndef __MONOME_HPP__
#define __MONOME_HPP__

#include <Fonction>

class Monome : public Fonction
{
	public:
		Monome(Variable* v, double multiplicateur = 1, uint exposant = 1);
		virtual ~Monome();

		virtual Monome* derivee(Variable* v) const;
        virtual Monome* primitive(Variable* v) const;
        virtual Monome* clone() const;

	protected:

	private:
        Variable* m_v;
        double m_multiplicateur;
        uint m_exposant;
};


#endif // __MONOME_HPP__
