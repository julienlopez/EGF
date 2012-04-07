#ifndef __MONOMESIMPLE_HPP__
#define __MONOMESIMPLE_HPP__

#include <Fonction>

class MonomeSimple : public Fonction
{
	public:
		MonomeSimple() = delete;
		MonomeSimple(Variable* v, double multiplicateur = 1, uint exposant = 1);
		MonomeSimple(const MonomeSimple& m);
		virtual ~MonomeSimple();

		virtual Fonction* derivee(Variable* v) const;
        virtual MonomeSimple* primitive(Variable* v) const;
        virtual MonomeSimple* clone() const;

		virtual void afficher(std::ostream& o) const;

	protected:
        MonomeSimple(double multiplicateur);

        double multiplicateur() const;
        uint exposant()const;

	private:
        Variable* m_v;
        double m_multiplicateur;
        uint m_exposant;
};


#endif // __MONOME_HPP__
