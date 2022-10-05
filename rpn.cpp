#include "rpn.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstdlib>

void rpn::parse(std::string expr, std::vector<char>& polNat) {
	std::stack <char> stk;
	for (int i = 0; i < expr.size(); ++i) {
		if (!std::isdigit(expr[i]) && expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && expr[i] != '^' && expr[i] != '(' && expr[i] != ')' && expr[i] != '.') {
			std::cout << "Invalid symbols entred\n";
			return std::exit(0);
		}
		if ((i == 0 && expr[i] == '-')||(i>0 && expr[i-1]=='(' && expr[i] == '-')) {
			polNat.push_back(' ');
			polNat.push_back(expr[i]);
			continue;
		}
		if (expr[i] == '.') {
			polNat.push_back(expr[i]);
			continue;
		}
		if (std::isdigit(expr[i])) {
			while (std::isdigit(expr[i])) {
				polNat.push_back(expr[i]);
				i++;
			}
			polNat.push_back(' ');
			i--;
		}
		else{
			if (stk.empty() && expr[i] != ')' && i!=0 && expr[i]!='-')
				stk.push(expr[i]);
			else {
				if (!stk.empty() && prior(stk.top()) - prior(expr[i]) >= 0 && prior(stk.top())!=4 && expr[i] != ')') {
					while (!stk.empty() && prior(stk.top()) != 4) {
						polNat.push_back(stk.top());
						stk.pop();
					}
					stk.push(expr[i]);
				}
				else {
					if (expr[i] != ')')
						stk.push(expr[i]);
				}
			}
		}
		if (!stk.empty() && expr[i] == ')') {
			while (stk.top()!='(') {
				polNat.push_back(stk.top());
				stk.pop();
			}
			stk.pop();
		}
			
	}
	while(!stk.empty()) {
		polNat.push_back(stk.top());
		stk.pop();
	}
}
int rpn::prior(char opr) {
	switch (opr) {
	case '-': case '+':
		return 1;
		break;
	case '*': case '/':
		return 2;
		break;
	case '^':
		return 3;
		break;
	case '(': case ')':
		return 4;
		break;
	}
}
void rpn::show_vector(std::vector<char>& polNat) {
	for (std::vector<char>::iterator it = polNat.begin(); it != polNat.end();++it) {
		std::cout << *it;
	}
	std::cout << "" << std::endl;
}
std::string rpn::withoutSpaces(std::string expr) {
	for (int i = 0; i < expr.size(); ++i) {
		if (expr[i] == ' ')
			expr.erase(i, 1);
	}
	return expr;
}
void rpn::correct_vector(std::vector<char>& polNat) {
	for (int i = 0; i < polNat.size();++i) {
		if (polNat[i] == ' ' && !std::isdigit(polNat[i + 1]) && polNat[i + 1] == ' ') {
			polNat.erase(polNat.begin() + i);
			++i;
			continue;
		}
		if (polNat[i] == ' ' && !std::isdigit(polNat[i + 1]) )
			polNat.erase(polNat.begin()+i);
	}
	for (int i = 0; i < polNat.size(); ++i) {
		if ((polNat[i] == '-' && i == 0) || (i > 0 && polNat[i] == '-' && polNat[i - 1] == ' ') || polNat[i]=='.') {
			continue;
		}
		if (!std::isdigit(polNat[i]) && polNat[i] != ' ' && i<polNat.size()-1 && std::isdigit(polNat[i + 1]))
			polNat.emplace(polNat.begin() + i+1, ' ');
	}
}

