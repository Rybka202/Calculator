#pragma once
#include "rpn.h"
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <stdexcept> 
class calculation
{
	double operations(double, double, char);
public:
	std::string parserToString(std::vector<char>&);
	double calculat(std::string&);
};

