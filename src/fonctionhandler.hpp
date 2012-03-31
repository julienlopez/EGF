#ifndef __VARIABLE_HANDLER_HPP__
#define __VARIABLE_HANDLER_HPP__

#include <Fonction>
#include <Singleton>

class FonctionHandler : public Singleton<FonctionHandler>
{
	friend class Singleton<FonctionHandler>;

	typedef std::set<Fonction*> type_set;

public:
	static void addFonction(Fonction* v);

	~FonctionHandler();

private:
	type_set m_fonctions;

	FonctionHandler();
	FonctionHandler(const FonctionHandler& vh);
	FonctionHandler& operator=(const FonctionHandler& vh);
};

#endif
