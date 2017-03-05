#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
static int count =0;
std::vector <int> fib_nums;

int GCD (int a, int b)
{
	cout << " GCD ( " << a << ", " << b << " ) " << endl; 
 	if (b == 0)
	{
		return a;
	}
	
	int remainder = a % b;
	return (GCD(b,remainder));
}

int main ()
{
	int gcd = GCD (3918848,1653264);
	cout << " GCD : " << gcd  << endl;
	return 0;
}
