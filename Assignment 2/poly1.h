#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class polynomial
{
public:
	polynomial();
	polynomial(double aO);//
	polynomial(const polynomial& source);//
	~polynomial();//
	
	polynomial &operator = (const polynomial &source);//
	polynomial &operator = (double aO);//
	
	void add_to_coef(double amount, unsigned int k);//
	void assign_coef(double new_coefficient, unsigned int k);//
	void reserve(unsigned int capacity);//
	void clear();//
	void print();
	
	
	
	double coefficient(unsigned int k)const;
	unsigned int degree()const;
	unsigned int next_term(unsigned int k)const;
	
	
	double eval(double x)const;//
	double operator()(double x)const;//
	
	
	polynomial operator+ (const polynomial& rhs);
	polynomial operator- (const polynomial& rhs);
	
	
	public: 
		double* coeffs;
		unsigned int p_degree;
};

#endif // POLYNOMIAL_H
