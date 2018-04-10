#include "stdafx.h"
#include "PQA2.h"
#include "PQA1.h"

list<int> rest(list<int> l);

PQA2::PQA2()
{
}


PQA2::~PQA2()
{
}

PQA2 PQA2::create_PQA2() {

	PQA2 p2;
	p2.Df = {};
	p2.Dr = {};
	p2.DD = {};
	p2.C = {};

	return p2;
}


void PQA2::insert(int x) {

	if (this->C.size() != 0 && this->C.front() >= x) {
		cout << " INSERT case 1 " << endl;
		this->C.clear(); this->Dr.clear(); this->Df.clear(); this->DD.clear();
		cout << " clearing all qeues ... sizes : " << this->DD.size() << this->C.size() << this->Df.size() << this->Dr.size() << endl;
		this->C.push_back(x);
	}
	else if (this->C.size() != 0 && this->C.back() >= x) {
		cout << " INSERT case 2 " << endl;
		this->Dr.clear(); this->Df.clear(); this->DD.clear();

		int temp_first_C = this->C.front(); // first C temp
		this->Dr = rest(this->C);
		this->C.clear();
		this->C.push_back(temp_first_C);
		this->DD.push_back(x);

	}
	else if (this->DD.size() != 0 && this->DD.front() >= x) {
		cout << " INSERT case 3 " << endl;
		this->DD.clear();
		this->DD.push_back(x);
	}
	else {
		cout << " INSERT case 4 " << endl;
		(this->DD).push_front(x);
	}

	BIAS();
}

void PQA2::BIAS() {

	if (this->Df.size() != 0) {
		//cleanup step
		cout << " BIAS case 1 " << endl;
		if (this->Dr.size() == 0 || this->Dr.front() > this->Df.back()) {
			cout << " first case of case1 in BIAS" << endl;
		}
		else {
			cout << " second case of case1 in BIAS" << endl;
		}
	}
	else if (this->Dr.size() != 0 && (this->DD.size() == 0 || this->Dr.front() <= this->DD.front())) {
		cout << "BIAS case 2 " << endl;
	}
	else if (this->DD.size() != 0) {
		cout << " BIAS case 3" << endl;
	}
	else {
		cout << " DR, Df, DD empty lists ." << endl;
	}


}

