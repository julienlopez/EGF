#ifndef __MONOME_HPP__
#define __MONOME_HPP__

#include <Fonction>

class Monome : public Fonction
{
	public:
		Monome() = delete;
		Monome(Fonction* f, double multiplicateur = 1, uint exposant = 1);
		Monome(const Monome& m);
		virtual ~Monome();

		virtual Monome* derivee(Variable* v) const;
        virtual Monome* primitive(Variable* v) const;
        virtual Monome* clone() const;

		virtual void afficher(std::ostream& o) const;

	protected:

	private:
        Fonction* m_f;
        double m_multiplicateur;
        uint m_exposant;
};


#endif // __MONOME_HPP__
