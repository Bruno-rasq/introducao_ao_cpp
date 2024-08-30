#include <iostream>

using namespace std;

int main () 
{
	string result = "* ";
	
	for (int i = 1; i <= 4; i++) {
		cout << result << endl;
		result += "* ";
	}
	
	return 0;
}