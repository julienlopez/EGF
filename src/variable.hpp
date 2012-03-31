#ifndef __VARIABLE_HPP__
#define __VARIABLE_HPP__

#include <Global>

#include <set>
#include <map>

class VariableHandler;

class Variable
{
	friend class VariableHandler;

public:
	class Cle
	{
	public:
		bool operator()(const Variable* v1, const Variable* v2) const;
	};

	typedef std::set<Variable*, Cle> type_set;
	typedef std::map<uchar, Variable*> type_map;

	uchar nom() const;

	static Variable* getVariable(uchar);

protected:
    Variable() =delete;
   	Variable(uchar c);
    Variable(const Variable& v) = delete;
    Variable& operator=(const Variable& v);

private:
	uchar m_nom;
};

#endif
