#ifndef __VARIABLE_HPP__
#define __VARIABLE_HPP__

#include <Global>

#include <set>
#include <map>

class Variable
{
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
    Variable();
     Variable(uchar c);
     Variable(const Variable& v);
     Variable& operator=(const Variable& v);

private:
	static type_map s_variables;
};

#endif
