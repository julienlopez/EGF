#include "monomesimple.hpp"
#include "constante.hpp"

#include <cassert>

MonomeSimple::MonomeSimple(Variable* v, double multiplicateur, uint exposant)
{
    m_v = v;
    m_multiplicateur = multiplicateur;
    m_exposant = exposant;
    addVariable(v);
}

MonomeSimple::MonomeSimple(const MonomeSimple& m) // : MonomeSimple(m.m_v, m.m_multiplicateur, m.m_exposant) //WARNING necessite gcc4.7
{
	m_v = m.m_v;
    m_multiplicateur = m.m_multiplicateur;
    m_exposant = m.m_exposant;
    addVariable(m_v);
}

MonomeSimple::~MonomeSimple()
{}

Fonction* MonomeSimple::derivee(Variable* v) const
{
    if(v != *getVariables().begin()) return clone();
    if(m_exposant == 1) return new Constante(m_multiplicateur);
    return new MonomeSimple(v, m_multiplicateur*m_exposant, m_exposant-1);
}

MonomeSimple* MonomeSimple::primitive(Variable* v) const
{
    if(v != *getVariables().begin()) return clone();
	//assert(m_exposant != -1); pas besoin tant que exposant m_uint
    return new MonomeSimple(v, m_multiplicateur/(m_exposant+1), m_exposant+1);
}

MonomeSimple* MonomeSimple::clone() const
{
    return new MonomeSimple(*this);
}

void MonomeSimple::afficher(std::ostream& o) const
{
	if(m_multiplicateur == 0) {
		o << "0";
		return;
	}
	if(m_multiplicateur != 1) {
		if(m_multiplicateur == -1) o << "-";
		else o << m_multiplicateur;
	}
	o << m_v->nom();
	if(m_exposant > 1) o << "^" << m_exposant;
}

