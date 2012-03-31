#include <Monome>

#include <iostream>

using namespace std;

int main()
{
	cout << "hello world" << endl;

	Variable* u = Variable::getVariable('u');

	Monome& m = *new Monome(u, 1.58, 2);

	cerr << m << endl;

	Monome& m2 = *m.derivee(u);
	cerr << m2 << endl;
}
