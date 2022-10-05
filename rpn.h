#pragma once
#include <stack>
#include <string>
#include <vector>
class rpn
{
	int prior(char);
public:
	void parse(std::string, std::vector<char>&);
	std::string withoutSpaces(std::string);
	void show_vector(std::vector<char>&);
	void correct_vector(std::vector<char>&);
};


