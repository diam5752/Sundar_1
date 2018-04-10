#include "stdafx.h"
#include "PQA2.h"


list<int> rest(list<int> l);
void pass(list<int>& l1, list<int>& l2);
void print_list(list<int>& l);
int delete_first(list<int>& l);

PQA2::PQA2()
{
	cout << " object PQA2 created " << endl;
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
			pass_back(this->Df, this->Dr);
		}
		else {
			cout << " second case of case1 in BIAS" << endl;
			delete_last(this->Df);
		}
	}
	else if (this->Dr.size() != 0 && (this->DD.size() == 0 || this->Dr.front() <= this->DD.front())) {
		cout << "BIAS case 2 " << endl;
		pass(this->Dr, this->C);
	}
	else if (this->DD.size() != 0) {
		cout << " BIAS case 3" << endl;
		pass(this->DD, this->C);
		this->Dr.clear(); this->DD.clear();  // AN exw lathos mallon tha einai edw. Des pseudokodika. 
											// den eimai sigouros ti ginetai me to Df = DDpou leei
	} 
	else {
		cout << " DR, Df, DD empty lists ." << endl;
	}


}

int PQA2::delete_last(list<int>& l) {
	cout << " ... delete last ..." << endl;
	cout << "removed last item of list : " << l.front() << endl;
	int temp = l.back();
	l.pop_back();

	return temp;
}

void PQA2::pass_back(list<int>& l1, list<int>& l2) { //pass first(Q1) to rear of Q2   / Df Dr
	cout << "... pass_back ..." << endl;
	cout << "***before passing *** Df size = " << l1.size() << "   Dr size = " << l2.size() << endl;
	int temp = l1.back();
	l1.pop_back();
	l2.push_front(temp);
	cout << "*** after passing ***  Df size = " << l1.size() << "   Dr size = " << Dr.size() << endl;

}

void PQA2::print_PQA2() {

	cout << endl << endl << " *********************************  PQA 2 *********************************" << endl << endl;

	cout << " C : "; print_list(this->C); cout << endl;
	cout << " Df : "; print_list(this->Df); cout << endl;
	cout << " Dr : "; print_list(this->Dr); cout << endl;
	cout << " DD : "; print_list(this->DD); cout << endl;

	cout << endl << " ------------ PQA ------------ " << endl;
	print_list(this->C);  print_list(this->Df);  print_list(this->Dr);  print_list(this->DD);
	cout << endl;

}

int PQA2::delete_min2() {
	cout << " ................... DELETE MIN ....................." << endl;

	BIAS();

	return delete_first(this->C);
}
