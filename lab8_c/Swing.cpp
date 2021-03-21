// Lab1_c++.cpp : Defines the entry point for the application.
//

#include "Lab1_c++.h"
#define usingNamespaces 0

#if usingNamespace == 0

#pragma message("Not Using namespaces")

int main()
{

	std::cout << "Hello world! " << std::endl;

	return 0;

}
#elif usingNamespace != 0
using namespace std;
#pragma message(" using namespaces")
int main()
{

	cout << "Hello world!" << endl;

	return 0;

}
#endif