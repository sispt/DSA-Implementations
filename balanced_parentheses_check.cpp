#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool arePaired(char open, char close) {
	if (open == '[' && close == ']' || open == '{' && close == '}' || open == '(' && close == ')') {
		return true;
	}
	else {
		return false;
	}
}
bool isBalanced(string exp) {
	stack<char>s;
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(') {
			s.push(exp[i]);
		}
		else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')') {
			if (!s.empty() && arePaired(s.top(), exp[i])) {
				s.pop();
			}
			else {
				return false;
			}
		}
	}
	return s.empty();
}
int main() {

}
