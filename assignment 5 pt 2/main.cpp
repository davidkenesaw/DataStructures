#include <stdio.h>
#include <iostream> // Provides cout and cin
#include <string>//provides string functions
#include <cctype>
#include <bits/stdc++.h>//provides standard library functions
using namespace std;
double findMean(int *A,int N);
int main(int argc, char **argv)
{//1 2 3 4 5
	int size = 3;
	
	int *a = new int[size];
	a[0] = 1;
	a[1] = 2;
	a[2] = 5;
	//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" ";
	
	cout<<findMean(a,size);
	return 0;
}
double findMean(int *A,int N){
	if(N == 1)return A[N-1];
	return (findMean(A, N-1)*(N-1) + A[N-1]) / N;
}