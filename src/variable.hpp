#ifndef __VARIABLE_HPP__
#define __VARIABLE_HPP__

#include "global.hpp" //<Global>

#include <set>

class Variable
{
public:
	class Cle
	{
	public:
		bool operator()(const Variable* v1, const Variable* v2) const;
	};
	
	typedef std::set<Variable*, Cle> type_set;
	
	uchar nom() const;
	
private:
	static type_set s_variables;
};

#endif
