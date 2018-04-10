#include "stdafx.h"
#include "PQA1.h"


PQA1::PQA1()
{
	cout << "PQA1 object created." << endl;
}


PQA1::~PQA1()
{
}

PQA1 PQA1:: create_PQA1()
{
	PQA1 p;
	p.Df = {};
	p.Dr = {};
	p.B = {};
	p.C = {};
	

	return p;
}

list<int> rest(list<int> l) {
	cout << "rest implementation " << endl;
	list<int> temp = l;
	temp.pop_front();
	return temp;
}

void PQA1::insert(int x) 
{
	cout << "inserting  " << x << " ..." << endl;
	
	if ( (this->C).size() != 0 && (this->C).front() >= x) {
		cout << "INSERT case 1 " << endl;
		this->B.clear(); this->C.clear(); this->Df.clear(); this->Dr.clear();
		cout << " clearing all qeues ... sizes : " << this->B.size() << this->C.size() << this->Df.size() << this->Dr.size() << endl;
		this->C.push_back(x);
	}
	else if (this->C.size() != 0 && this->C.back() >= x) {  // needs testin the cases
		cout << "INSERT case 2 " << endl;
		this->B.clear(); this->Df.clear(); this->Dr.clear();
		
		int temp_first_C = this->C.front(); // first C temp
		this->B = rest(this->C);
		this->C.clear();
		this->C.push_back(temp_first_C);
		this->Df.push_back(x);

	}
	else {
		cout << "INSERT case 3 " << endl;
		(this->Dr).push_front(x);
		cout << x << " pushed back to Dr and now Dr.size() = " << this->Dr.size() << endl;
	}

	BIAS();
	BIAS();
}

void PQA1::BIAS() 
{
	cout << "... BIAS ..." << endl;

	if (this->Dr.size() != 0) {
		cout << " BIAS case 1 " << endl;
		
		// CLEANUP step 
		if ( this->Df.size() != 0  && this->Df.back() >= this->Dr.front() ) {
			cout << " first case of case_1" << endl;
			delete_last();
		}
		else {
			cout << "second case of case_1" << endl;
			pass(this->Dr, this->Df);
		}

	}
	else if ( this->Df.size() !=0  && (this->B.size() == 0 || this->B.front() >= this->Df.front())) {
		cout << " BIAS case 2 " << endl;
		cout << " *** before merge   C.size() = " << this->C.size() << "  Df.size() =  " << this->Df.size() << endl;
		(this->C).merge(this->Df);
		cout << " *** after merge   C.size() = " << this->C.size() << "  Df.size() =  " << this->Df.size() << endl;

		this->B = {}; this->Df = {};
	}
	else if (this->B.size() != 0) {
		cout << " BIAS case 3 " << endl;
		pass(this->B, this->C);
	}
	else {
		cout << " all lists are empty " << endl;
	}
}

void PQA1::delete_last() {  // na tin kanw san tin katw, pio generic, na valw lista san argument
	cout << " ... delete last ..." << endl;
	cout << "removed last item of Df : " << this->Df.back() << endl;
	this->Df.pop_back();
}

int PQA1::delete_first( list<int>& l) {
	cout << " ... delete first ..." << endl;
	cout << "removed first item of list : " << l.front() << endl;
	int temp = l.front();
	l.pop_front();

	return temp;
}

void PQA1::pass(list<int>& l1, list<int>& l2) { //pass first(Q1) to rear of Q2   / Dr Df
	cout << "... pass ..." << endl;
	cout << "***before passing *** Dr size = " << Dr.size() << "   Df size = " << Df.size() << endl;
		int temp = l1.front();
	l1.pop_front();
	l2.push_back(temp);
	cout << "*** after passing ***  Dr size = " << Dr.size() << "   Df size = " << Df.size() << endl;

}

int PQA1::delete_min() {
	cout << " ................... DELETE MIN ....................." << endl;

	BIAS();

	return delete_first(this->C);
}

void print_list( list<int> l) {
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		std::cout << ' ' << *it ;
	}

}
void PQA1::print_PQA() {
	cout << endl << endl <<" *********************************  PQA  *********************************" << endl << endl;
	
	cout << " C : "; print_list(this->C); cout << endl;
	cout << " B : "; print_list(this->B); cout << endl;
	cout << " Df : "; print_list(this->Df); cout << endl;
	cout << " Dr : "; print_list(this->Dr); cout << endl;

	cout << endl << " ------------ PQA ------------ " << endl;
	print_list(this->C);  print_list(this->B);  print_list(this->Df);  print_list(this->Dr);
	cout << endl;

}

