#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void creerClasse(std::string& nom);
void creerInclude(std::string nom);
void creerTest(std::string& nom);

int main(int argc, char* argv[])
{
    for(int i = 1; i<argc; ++i)
    {
        string nom = argv[i];
        creerClasse(nom);
        creerInclude(nom);
        creerTest(nom);
    }
}

void creerClasse(std::string& nom)
{
    string lower = nom;
    string upper = nom;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    ofstream f(("../src/"+lower+".hpp").c_str());
    if(!f)
    {
        cerr << "Erreur lors de l'ouverture du fichier: " << "../src/" << lower << ".hpp" << endl;
        return;
    }

    f << "#ifndef __" << upper << "_HPP__" << endl;
    f << "#define __" << upper << "_HPP__" << endl << endl;
    f << "class " << nom << endl;
    f << "{" << endl;
    f << "public: " << endl << endl;
    f << "protected: " << endl << endl;
    f << "private: " << endl << endl;
    f << "};" << endl << endl;
    f << "#endif" << endl;
    if(!f)
    {
        cerr << "Erreur lors de l'écriture du fichier" << endl;
        return;
    }
    f.close();

    f.open(("../src/"+lower+".cpp").c_str());
    if(!f)
    {
        cerr << "Erreur lors de l'ouverture du fichier: " << "../src/" << lower << ".cpp" << endl;
        return;
    }

    f << "#include \"" << lower << ".hpp\"" << endl << endl;
    if(!f)
    {
        cerr << "Erreur lors de l'écriture du fichier" << endl;
        return;
    }
    f.close();
}

void creerInclude(std::string nom)
{
    ofstream f(("../include/"+nom).c_str());
    if(!f)
    {
        cerr << "Erreur lors de l'ouverture du fichier: " << nom << endl;
        return;
    }
    transform(nom.begin(), nom.end(), nom.begin(), ::tolower);
    f << "#include \"../src/" << nom << ".hpp";
    if(!f)
    {
        cerr << "Erreur lors de l'écriture du fichier" << endl;
        return;
    }
    f.close();
}

void creerTest(std::string& nom)
{
    string lower = nom;
    string upper = nom;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    ofstream f(("../tests/test"+lower+".hpp").c_str());
    if(!f)
    {
        cerr << "Erreur lors de l'ouverture du fichier: " << "../tests/test" << lower << ".hpp" << endl;
        return;
    }
    f << "#ifndef __TEST" << upper << "_HPP__" << endl;
    f << "#define __TEST" << upper << "_HPP__" << endl << endl;

    f << "#include <cppunit/TestFixture.h>" << endl;
    f << "#include <cppunit/extensions/HelperMacros.h>" << endl << endl;

    f << "class Test" << nom << " : public CppUnit::TestFixture" << endl;
    f << "{" << endl;
    f << "\tCPPUNIT_TEST_SUITE(" << nom << ");" << endl;
    f << "\tCPPUNIT_TEST(constructeurValeur);" << endl << endl;
    f << "public:" << endl;
	f << "\tvoid setUp() {}" << endl;
	f << "\tvoid tearDown() {}" << endl << endl;
    f << "protected:" << endl;
	f << "\tvoid constructeurValeur();" << endl << endl;
	f << "};" << endl << endl;
	f << "#endif" << endl;
	if(!f)
    {
        cerr << "Erreur lors de l'écriture du fichier" << endl;
        return;
    }
    f.close();

    f.open(("../tests/test"+lower+".cpp").c_str());
    if(!f)
    {
        cerr << "Erreur lors de l'ouverture du fichier: " << "../tests/test" << lower << ".cpp" << endl;
        return;
    }
    f << "#include \"test" << lower << ".hpp\"" << endl << endl;
    f << "#include <" << nom << ">" << endl << endl;
    f << "CPPUNIT_TEST_SUITE_REGISTRATION( Test" << nom << " );" << endl << endl;
    f << "void Test" << nom << "::constructeurValeur()" << endl;
    f << "{" << endl;
    f << "\tCPPUNIT_ASSERT(0&&\"à faire\");" << endl;
    f << "}" << endl << endl;
    if(!f)
    {
        cerr << "Erreur lors de l'écriture du fichier" << endl;
        return;
    }
    f.close();
}
