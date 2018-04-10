// Sundar_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PQA1.h"
#include "PQA2.h"
#include <stdlib.h>     /* srand, rand */
#include <vector>



void testing_PQA1( PQA1 p) {

	int r , limit;
	vector<int> v;

	limit = 10;

	srand(2);
	
	for (int i = 0; i <= limit; i++) {
		r = rand() % 100 + 1;
		v.push_back(r);

		p.insert(r);
	}

	
	p.print_PQA();
	cout << " ****************** from the list ***************************** "  <<endl << endl; 
	for (int n : v) {
		std::cout << n << "  ";
	}
	cout << endl << endl;

	cout << " /////////////////////////////////////////////////////////////  deletemin in testing : " << p.delete_min() << endl;
	
}


int main()
{
	PQA1 p1;

	p1 = p1.create_PQA1();

	//testing_PQA1(p1);

	//PQA2 p2;
	//p2 = p2.create_PQA2();

	//p2.insert(5);


	return 0;
}

