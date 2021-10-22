#include <stdio.h>
#include <iostream> // Provides cout and cin
#include <string>//provides string functions
#include <cctype>
#include <bits/stdc++.h>//provides standard library functions
using namespace std;
int countVowels(string value);
int main(int argc, char **argv)
{
	string value = "My list of Objects";
	cout<<countVowels(value);
	
	return 0;
}
int countVowels(string value){
	transform(value.begin(), value.end(),value.begin(), ::tolower);
	if(value.size() == 0){
		return 0;
	}
	if(value[0] == 'a'||value[0] == 'e'||value[0] == 'i'||value[0] == 'o'||value[0] == 'u'){
		return countVowels(value.substr(1)) + 1;
	}
	return countVowels(value.substr(1));
	
}
