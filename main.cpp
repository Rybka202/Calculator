#include <iostream>
#include <string>
#include <vector>
#include "rpn.h"
#include "calculation.h"
int main() {
	std::string expression;
	std::cout << "Enter the expression:\n";
	std::getline(std::cin, expression);
	std::vector<char> polNat;
	rpn Polish;
	calculation Result;
	Polish.parse(Polish.withoutSpaces(expression), polNat);
	Polish.correct_vector(polNat);
	std::cout << "Reverse Polish notation:\n";
	Polish.show_vector(polNat);
	std::string strExpr = Result.parserToString(polNat);
	std::cout << "Result:\n";
	std::cout << Result.calculat(strExpr) << std::endl;
}