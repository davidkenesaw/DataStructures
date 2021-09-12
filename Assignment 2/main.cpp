#include <stdio.h>
#include "polynomial.h"
#include <iostream> 
using namespace std;
#include <string>

int main(int argc, char **argv)
{
	
	
	polynomial p1(5);
	
	p1.add_to_coef(-3,2);
	
	p1.add_to_coef(.3,3);
	
	
	
	polynomial p2;
	
	p2 = p1;
	
	p1.add_to_coef(1,2);
	
	p1.add_to_coef(1,3);
	
	p1.add_to_coef(3,4);
	
	
	p1.print();
	p2.print();
	
	polynomial p3 = p1 + p2;
	polynomial p4 = p2 - p1;
	
	p3.print();
	p4.print();
	
	cout<<"eval: "<<p1(2)<<endl;
	cout<<"eval: "<<p1.eval(2)<<endl;
	cout<<"first term: "<<p1.coefficient(0)<<endl;
	cout<<"coefficient: "<<p1.coefficient(3)<<endl;
	cout<<"degree: "<<p1.degree()<<endl;
	cout<<"next term: "<<p1.next_term(2)<<endl;
	return 0;
}
