#include "polynomial.h"
#include <iostream>
#include <array>
#include <math.h>
using namespace std;

polynomial::polynomial(){//
	coeffs = new double[1];
	coeffs[0]= 0;
	p_degree = 0;
}
polynomial::polynomial(double a0){//
	coeffs = new double[1];
	p_degree = 0;
	coeffs[0] = a0;
}
polynomial::polynomial(const polynomial& source){//
	p_degree = source.p_degree;
	coeffs = new double[p_degree + 1];
	for(unsigned int idx = 0; idx <= p_degree;idx++){
		coeffs[idx] = source.coeffs[idx];
	}
}
polynomial::~polynomial(){//
	delete[] coeffs;
}



polynomial &polynomial::operator = (const polynomial &source){//
	if(this==&source)return *this;
	delete[] coeffs;
	coeffs = new double[source.p_degree+1];
	p_degree = source.p_degree;
	copy(source.coeffs,source.coeffs+p_degree+1,coeffs);
	return *this;
}
polynomial &polynomial::operator = (double a0){//
	p_degree = 0;
	coeffs=new double[1];
	coeffs[0]=a0;
	return *this;
}



void polynomial::add_to_coef(double amount, unsigned int k){
	if(k > p_degree){
		reserve(k);
	}
	coeffs[k] += amount;
}
void polynomial::assign_coef(double new_coefficient, unsigned int k){
	if(k>p_degree){
		reserve(k);
	}
	coeffs[k]=new_coefficient;
}
void polynomial::clear(){
	for(int loop = 0; loop <= p_degree; loop++){
		coeffs[loop] = 0;
	}
	p_degree = 0;
}
void polynomial::reserve(unsigned int capacity){
	unsigned int tempLength = p_degree;
	
	
	if (capacity > p_degree)p_degree = capacity;
	double* temp = new double[capacity+1];
	//cout<<"p_degree "<<p_degree<<endl;
	//cout<<"temp "<<tempLength<<endl;
	//cout<<"capacity "<<capacity+1<<endl;
	for(unsigned int loop = 0; loop < capacity+1;loop++){
		temp[loop] = 0;
		//cout<<temp[loop]<<endl;
	}
	for(unsigned int loop = 0; loop <= tempLength;loop++){
		temp[loop] = coeffs[loop];
	}
	delete[] coeffs;
	coeffs = temp;
	
}




double polynomial::coefficient(unsigned int k)const{
	if(k>p_degree)return 0;
	return coeffs[k];
}
unsigned int polynomial::degree()const{
	return p_degree;
}
unsigned int polynomial::next_term(unsigned int k)const{
	for(unsigned int loop = k+1; loop <= p_degree; loop++){
		if(coeffs[loop]!=(unsigned int)0){
			return (unsigned int) loop;
		}
	}
	return 0;
}


double polynomial::eval(double x)const{
	double answer = 0;
	for(int loop = 0; loop <= p_degree; loop++){
		answer += pow(2,loop) * coeffs[loop];
	}
	return answer;
}
double polynomial::operator()(double x)const{
	double answer = 0;
	for(int loop = 0; loop <= p_degree; loop++){
		answer += pow(2,loop) * coeffs[loop];
	}
	return answer;
}




polynomial polynomial::operator+(const polynomial& rhs){
	polynomial temp(0);
	//temp.p_degree = p_degree + rhs.p_degree;
	int length = 0;
	if(p_degree > rhs.p_degree){
		length = p_degree;
		temp.reserve(p_degree);
	}
	else{
		length = rhs.p_degree; 
		temp.reserve(rhs.p_degree);
	}
	
	for(int loop = 0; loop <= length; loop++){
		temp.coeffs[loop]=coeffs[loop] + rhs.coeffs[loop];
	}
	
	
	return temp;
}
polynomial polynomial::operator-(const polynomial& rhs){
	polynomial temp(0);
	//temp.p_degree = p_degree + rhs.p_degree;
	int length = 0;
	if(p_degree > rhs.p_degree){
		length = p_degree;
		temp.reserve(p_degree);
	}
	else{
		length = rhs.p_degree; 
		temp.reserve(rhs.p_degree);
	}
	
	for(int loop = 0; loop <= length; loop++){
		temp.coeffs[loop]=coeffs[loop] - rhs.coeffs[loop];
	}
	
	
	return temp;
}



void polynomial:: print(){
	
	cout<<endl;
	for(int loop = p_degree; loop >= 0;loop--){
		if(coeffs[loop] == 0){
			if (loop == 0){
				cout<<"0";
			}
		}
		else if (coeffs[loop] < 0){
			cout<<"("<<coeffs[loop]<<")"<< "x^" << loop << " + ";
		}
		else if(loop == 0){
			cout<<coeffs[loop];
		}
		else{
			cout<<coeffs[loop] << "x^" << loop << " + ";
		}
	}
	cout<<endl;
	
}

