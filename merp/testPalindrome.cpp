
// Name: David VanAsselberg
// Class: CS 3305/Section 1
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 4


#include <stdio.h>//privides user input
#include <iostream>//provides cout and cin
#include <bits/stdc++.h>//provides standard library functions
#include <stack>//provides stack class
#include <cctype>//provides isupper
#include <string>//provides isAlpha

using namespace std;

//functions used by testPalindrome
void menu();
//Postcondition: prints the menu
void printString(stack<string> list);
//precondition:stack is string
//Postcondition: prints stack
void printChar(stack<char> list);
//precondition:stack is char
//Postcondition: prints stack
string formatChar(string value);
//Postcondition: takes all punctuation and spaces out of string of characters. ignores capitalization
string formatString(string value);
//Postcondition: takes all punctuation out of string. ignores capitalization
bool swapWordsString(stack<string> list);
//Postcondition:swaps the position of a stack and returns true if the original and the swapped equal each other
bool swapWordsChar(stack<char> list);
//Postcondition:swaps the position of a stack and returns true if the original and the swapped equal each other
string character_by_character(string s);
//I know the assignment said to take the books code but i learn better by doing it first so i wanted to 
//make and use my own code for this function. hope thats okay
//Postcondition:returns Palindrome if string of characters is a palindrome
string word_by_word(string s);
//Postcondition:returns Palindrome if string of words is a palindrome

int main(int argc, char const* argv[])
{
	string value;
	int choice;
	
	do{
		
		cout<<"Enter in a string to see if its a Palindrome: ";
		getline(cin,value);
		cout<<endl;
		menu();
		cin>>choice;
		switch(choice){
			case 1://tests character_by_character function
				cout<<"You selected:    Option 1"<<endl;
				cout<<"You entered:     "<<value<<endl;
				cout<<"Judgment:        "<<character_by_character(value)<<endl;
				cout<<endl;
				value = "";
			break;
			case 2://tests word_by_word function
				cout<<"You selected:    Option 2"<<endl;
				cout<<"You entered:     "<<value<<endl;
				cout<<"Judgment:        "<<word_by_word(value)<<endl;
				cout<<endl;
			break;
			case 3://ends program
				cout<<"end program"<<endl;
			break;
			default://if user enters bad input
				cout<<"Bad input, Please enter a number 1-3"<<endl;
			break;
		}
		cin.get();
	}while(choice !=3);
	
    return 0;
}
void menu(){//prints out menu
	cout<<"-----MAIN MENU-----"<<endl;
	cout<<"1. Test character-by-character palindrome"<<endl;
	cout<<"2. Test word-by-word palindrome"<<endl;
	cout<<"3. Exit program"<<endl;
	cout<<endl;
	cout<<"Enter option number: ";
}
void printString(stack<string> list){//prints string stack
	while(!list.empty()){
		cout<<" "<<list.top();
		list.pop();
	}
}
void printChar(stack<char> list){//prints char stack
	while(!list.empty()){
		cout<<list.top();
		list.pop();
	}
}
string formatChar(string value){//takes all punctuation and spaces out of string of characters. ignores capitalization
	transform(value.begin(), value.end(),value.begin(), ::toupper);
	for(int loop = 0; loop < (int)value.length();loop++){
		if(!isalpha(value[loop])){
			value.erase(value.begin() + loop);
			loop-=1;
		}
	}
	return value;
}
string formatString(string value){//Postcondition: takes all punctuation out of string. ignores capitalization
	transform(value.begin(), value.end(),value.begin(), ::toupper);
	for(int loop = 0; loop < (int)value.length();loop++){
		if(!isalpha(value[loop])&&value[loop] != ' '){
			value.erase(value.begin() + loop);
			loop-=1;
		}
	}
	if(value[value.length()-1]==' '){
		value.erase(value.begin() + value.length()-1);
	}
	
	return value;
}
bool swapWordsString(stack<string> list){//Postcondition:swaps the position of a stack and returns true if the original and the swapped equal each other
	
	stack<string> list2 = list;
	stack<string> list1;
	while(!list.empty()){
		list1.push(list.top());
		list.pop();
	}
	if(list2==list1){
		return true;
	}
	return false;
}
bool swapWordsChar(stack<char> list){//Postcondition:swaps the position of a stack and returns true if the original and the swapped equal each other
	
	stack<char> list2 = list;
	stack<char> list1;
	while(!list.empty()){
		list1.push(list.top());
		list.pop();
	}
	if(list2==list1){
		return true;
	}
	return false;
}
string character_by_character(string s){//Postcondition:returns Palindrome if string of characters is a palindrome
	s = formatChar(s);
	stack<char> list;
    for(int loop = 0; loop < (int)s.length();loop++){
		list.push(s[loop]);
	}
	if(swapWordsChar(list)==true)return "Palindrome";
	else return "Not Palindrome";
	
}
string word_by_word(string s){//Postcondition:returns Palindrome if string of words is a palindrome
	s = formatString(s);
    stringstream ss(s);
    string word;
	stack<string> list;
    while (ss >> word) {
		list.push(word);
    }
	if(swapWordsString(list)==true)return "Palindrome";
	else return "Not Palindrome";
}