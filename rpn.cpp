#include "rpn.h"

int main() {
	string opt;
	bool flag = false;
	string test[] = {"2", "12", "6", "-", "/", "5", "3", "+", "*"};
	int n = 9;
	//string test[] = {"1", "2", "3", "+", "4", "5", "6", "*", "/", "7", ">", "+", "8", "9", "10", "<", "-", "-", "+", "/", "*"};
	//int n = 21;			// running different examples
	cout<<"Option (-l/none):\n";
	cin>> opt;
	if (opt == "-l"){
		flag = true;
	}
	double result = rpn(test, n, flag);
	cout << result << endl;
}
