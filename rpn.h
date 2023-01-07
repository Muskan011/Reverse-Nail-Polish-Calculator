#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

double rpn(string *strs, int n, bool flag) {
	double result = 0.0;
	vector<double> vec;
	double a;
	double b;
	for(int i = 0; i < n; i++){
		if(strs[i] == "+"){
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			a = vec.back();
			vec.pop_back();
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			b = vec.back();
			vec.pop_back();
			vec.push_back(a+b);
		}
		else if(strs[i] == "-"){
			a = vec.back();
			vec.pop_back();
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			b = vec.back();
			vec.pop_back();
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			vec.push_back(b-a);
		}
		else if(strs[i] == "*"){
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			a = vec.back();
			vec.pop_back();
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			b = vec.back();
			vec.pop_back();
			vec.push_back(a*b);

		}
		else if(strs[i] == "/"){
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			a = vec.back();
			vec.pop_back();
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			b = vec.back();
			vec.pop_back();
			if (a == 0){
				cout<<"Error: Division by 0\n";
				return -1;
			}
			vec.push_back(b/a);

		}
		else if(strs[i] == "**"){
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			a = vec.back();
			vec.pop_back();
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			b = vec.back();
			vec.pop_back();
			if(b < 0 && a < 1){
				cout<<"Error: root of negative number\n";
				return -1;
			}
			if(a == 0 && b == 0){
				cout<<"Error: 0^0\n";
				return -1;
			}
			
			vec.push_back(pow(b, a));
		}
		else if(strs[i] == "<"){
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			a = vec.back();
			vec.pop_back();
			vec.push_back(floor(a));

		}
		else if(strs[i] == ">"){
			if(vec.empty()){
				cout<<"Error: Insufficient number of operands\n";
				return -1;
			}
			a = vec.back();
			vec.pop_back();
			vec.push_back(ceil(a));
		}
		else{
			double num = stof(strs[i]);
			vec.push_back(num);
		}
		
	}
	result = vec.back();
	vec.pop_back();
	if(!vec.empty()){
		cout<<"Error: Insufficient number of operators\n";
		return -1;
	}
	if(flag){		// part 2 implementation begins
		vector<string> str_vec;
		string substr1, substr2;
		for(int i = 0; i < n; i++){
			if(strs[i] == "+" || strs[i] == "-" || strs[i] == "*" || strs[i] == "/" 
				|| strs[i] == "**"){
					substr1 = str_vec.back();
					str_vec.pop_back();
					substr2 = str_vec.back();
					str_vec.pop_back();
					string pre = "(" + strs[i] + " " + substr2 + " " + substr1 + " " + ")";
					str_vec.push_back(pre);
			}
			else if(strs[i] == "<" || strs[i] == ">"){
				substr1 = str_vec.back();
				str_vec.pop_back();
				string pre = "(" + strs[i] + " " + substr1 + " " + ")";
				str_vec.push_back(pre);
			}
			else{
				str_vec.push_back(strs[i]);
			}
		}
		string prefix = str_vec.back();
		//cout<<prefix<<endl;      // Debugging
		vector<string> str_vector;				// taken help from https://www.geeksforgeeks.org/program-to-parse-a-comma-separated-string-in-c/
												// converted prefix string into vec of string parsing with ' '.
		stringstream str_stream(prefix);
		while (str_stream.good()) {
			string substr;
			getline(str_stream, substr, ' ');
			str_vector.push_back(substr);
		}
		int counter = 0;
		for (size_t j = 0; j < str_vector.size(); j++){ 
			if(str_vector[j][0] == '('){
				for(int k = counter; k > 0; k--)
					cout<<"  ";
				counter++;
			}
			else if(str_vector[j][0] == ')'){
				counter--;
				for(int k = counter; k > 0; k--)
					cout<<"  ";
			}
			else{
				for(int k = counter; k > 0; k--)
					cout<<"  ";
			}
			cout<<str_vector[j]<<endl;			// Debugging
		}
	}
	return result;
}
