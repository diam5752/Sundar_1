#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <list>


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
	void BIAS();
};


