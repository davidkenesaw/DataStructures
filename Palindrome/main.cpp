#include <stdio.h>//privides user input
#include <iostream>//provides cout and cin
#include <bits/stdc++.h>//provides standard library functions
#include <stack>//provides stack class
#include <cctype>//provides isupper
#include <string>//provides isAlpha

using namespace std;
void print(stack<string> list){
	while(!list.empty()){
		cout<<" "<<list.top();
		list.pop();
	}
	cout<<endl;
}
string Pal(string value){
	stack<string> list;
	stack<string> temp;
	stack<string> list2 = list;
	transform(value.begin(), value.end(), value.begin(), ::toupper);
	string word = "";
	for(int loop = 0; loop <=(int) value.size();loop++){
		if(!isalpha(value[loop])||loop == (int)value.size()){
			if(!word.empty()){
				list.push(word);
				word = "";
			}
		}
		else word += value[loop];
	}
	list2 = list;
	print(list);
	
	while(!list.empty()){
		temp.push(list.top());
		list.pop();
	}
	print(temp);
	
	if(list2==temp){
		return"Pal";
	}
	else {
		return "Not Pal";
	}
}

int main(int argc, char **argv)
{
	string Value = "This. is this?";
	
	
	
	cout<<Pal(Value);
	
	

	
	
	
	
	
	
	
	return 0;
}
