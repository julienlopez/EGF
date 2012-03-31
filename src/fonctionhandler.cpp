#include "fonctionhandler.hpp"

FonctionHandler::FonctionHandler() 
{}
	
FonctionHandler::FonctionHandler(const FonctionHandler& vh)
{}
	
FonctionHandler& FonctionHandler::operator=(const FonctionHandler& vh)
{
	return *this;
}

void FonctionHandler::addFonction(Fonction* v) {
	instance().m_fonctions.insert(v);
}

FonctionHandler::~FonctionHandler()
{
	for(auto i = m_fonctions.begin(); i != m_fonctions.end(); ++i)
		if(*i) delete *i;
}
