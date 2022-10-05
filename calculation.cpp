#include "calculation.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
double calculation::calculat(std::string& parsePolNat) {
	int i = 0;
	std::stack <double> numbers;
	while (i < parsePolNat.size())
	{
		int start = i;
		if (std::isdigit(parsePolNat[i]) || (i == 0 && parsePolNat[i] == '-') || (i > 0 && parsePolNat[i] == '-' && std::isdigit(parsePolNat[i+1]))) {
			while (std::isdigit(parsePolNat[i]) || (i == 0 && parsePolNat[i] == '-') || (i > 0 && parsePolNat[i] == '-' && std::isdigit(parsePolNat[i + 1])) || parsePolNat[i]=='.')
			{
				++i;
			}
			double num = std::stod(parsePolNat.substr(start, i));
			numbers.push(num);
			continue;
		}
		try {
			if (!std::isdigit(parsePolNat[i]) && parsePolNat[i] != ' ') {
				double num2 = numbers.top();
				numbers.pop();
				double num1 = numbers.top();
				numbers.pop();
				numbers.push(operations(num1, num2, parsePolNat[i]));
			}
		}
		catch (std::runtime_error e) {
			std::cerr << e.what();
		}
		++i;
	}
	return numbers.top();
}
std::string calculation::parserToString(std::vector<char>& polNat) {
	std::string str;
	for (std::vector<char>::iterator it = polNat.begin(); it != polNat.end(); ++it) {
		 str+=*it;
	}
	return str;
}
double calculation::operations(double num1, double num2, char opr) {
	switch (opr) {
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num1 - num2;
		break;
	case '*':
		return num1 * num2;
		break;
	case '/':
		return num1 / num2;
		break;
	case '^':
		return pow(num1, num2);
		break;
	}
}
