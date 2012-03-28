#include <Monome>

#include <iostream>

using namespace std;

int main()
{
	cout << "hello" << endl;

	Variable* u = Variable::getVariable('u');

	Monome m(u);

}
