#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <list>
#include "PQA1.h"


using namespace std;


class PQA2 
{
private:
	list<int> Dr, Df, DD, C;

public:
	PQA2();
	~PQA2();

	PQA2 create_PQA2();
	void insert(int x);
	void pass_back(list<int>& l1 , list<int>& l2);
	int delete_last(list<int>& l);
	void BIAS();
	void print_PQA2();
	int delete_min2();
};


