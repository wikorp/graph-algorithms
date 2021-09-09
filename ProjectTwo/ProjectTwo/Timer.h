#pragma once
#include "GraphM.h"
#include "GraphL.h"
#include <iostream>
using namespace std;

class Timer
{
public:
	 GraphL l;
	 GraphM m;
	 void test();
	 void measure();
	 void generate(int nodes_number, int density, bool direcected);
};

