#include <stdio.h>//privides user input
#include <iostream>//provides cout and cin
#include <bits/stdc++.h>//provides standard library functions
#include <stack>//provides stack class
#include <cctype>//provides isupper
#include <string>//provides isAlpha

using namespace std;

void add(int*& ptr){
	int &value = *ptr;
	value = 5;
}


int main(int argc, char **argv)
{
	int value1 = 1;

	int *ptr = nullptr; 
	ptr=&value1;
	
	add(ptr);

	
	cout<<*ptr<<endl;
	cout<<value1<<endl;

	
	return 0;
}
