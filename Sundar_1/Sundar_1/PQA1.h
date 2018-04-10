#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

class PQA1
{
private:
	list<int> Dr, Df, B, C;

public:

	PQA1();
	~PQA1();

	PQA1 create_PQA1();
	void insert(int x);
	void BIAS();
	int delete_last(list<int>& l);
	//int delete_first(list<int>& l);
	//void pass( list<int>& l1 , list<int>& l2 );
	int delete_min();

	void print_PQA();
};

