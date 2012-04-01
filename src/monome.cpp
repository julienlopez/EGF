#include "monome.hpp"

#include <cassert>

Monome::Monome(Fonction* f, double multiplicateur, uint exposant)
{
    m_f = f;
    m_multiplicateur = multiplicateur;
    m_exposant = exposant;
    for(auto i = f->getVariables().begin(); i != f->getVariables().end(); ++i)
        addVariable(*i);
}

Monome::Monome(const Monome& m) // : Monome(m.m_v, m.m_multiplicateur, m.m_exposant) //WARNING necessite gcc4.7
{
	m_f = m.m_f;
    m_multiplicateur = m.m_multiplicateur;
    m_exposant = m.m_exposant;
    for(auto i = m_f->getVariables().begin(); i != m_f->getVariables().end(); ++i)
        addVariable(*i);
}

Monome::~Monome()
{}

Monome* Monome::derivee(Variable* v) const
{
    if(v != *m_f->getVariables().begin()) return clone();
    //TODO return new Monome(new Produit(m_f->derivee(), m_f), m_multiplicateur*m_exposant, m_exposant-1);
    return 0;
}

Monome* Monome::primitive(Variable* v) const
{
    if(v != *getVariables().begin()) return clone();
	//assert(m_exposant != -1); pas besoin tant que exposant m_uint
    //TODO return new Monome(v, m_multiplicateur/(m_exposant+1), m_exposant+1);
    return 0;
}

Monome* Monome::clone() const
{
    return new Monome(*this);
}

void Monome::afficher(std::ostream& o) const
{
	if(m_multiplicateur == 0) {
		o << "0";
		return;
	}
	if(m_multiplicateur != 1) {
		if(m_multiplicateur == -1) o << "-";
		else o << m_multiplicateur;
	}
	m_f->afficher(o);
	if(m_exposant > 1) o << "^" << m_exposant;
}

