#include <MonomeSimple>

#include <iostream>

using namespace std;

int main()
{
	cout << "hello world" << endl;

	Variable* u = Variable::getVariable('u');

	MonomeSimple& m = *new MonomeSimple(u, 1.58, 2);

	cerr << m << endl;

	Fonction& m2 = *m.derivee(u);
	cerr << m2 << endl;

	MonomeSimple& m3 = *m.primitive(u);
	cerr << m3 << endl;

	cerr << *m2.derivee(u) << endl;
}
