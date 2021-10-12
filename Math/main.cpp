#include <stdio.h>//privides user input
#include <iostream>//provides cout and cin
#include <bits/stdc++.h>//provides standard library functions
#include <stack>//provides stack class
#include <cctype>//provides isupper
#include <string>//provides isAlpha

using namespace std;
bool OperatorPriority(char op,char Instack){
	int priorityOP;
	int priorityInStack;
	if(op == ')'){
		priorityOP = 5;
	}
	else if(op == '*'||op == '/'){
		priorityOP = 2;
	}
	else if(op == '+'||op == '-'){
		priorityOP = 3;
	}
	
	
	
	if(Instack == ')'){
		priorityInStack = 5;
	}
	else if(Instack == '*'||Instack == '/'){
		priorityInStack = 2;
	}
	else if(Instack == '+'||Instack == '-'){
		priorityInStack = 3;
	}
	
	
	if(priorityInStack<=priorityOP){
		return true;
	}
	else{
		return false;
	}
}
string postfix(string value){
	string output = "";
	stack<char> list;
	
	for(int loop = 0; loop < (int)value.size();loop++){
		if(isalpha(value[loop])||isdigit(value[loop])){
			output += value[loop];
		}
		else if(!isalpha(value[loop])||isdigit(value[loop])){
			if(list.empty()){
				list.push(value[loop]);
			}
			else if(!OperatorPriority(value[loop],list.top())){
				list.push(value[loop]);
				
			}
			else if(OperatorPriority(value[loop],list.top()==1))
			{
				if(value[loop]==')'){
					while(!list.empty()){
						if(list.top()=='('){
							list.pop();
							break;
						}
						output+=list.top();
						list.pop();
					}
				}
				if(value[loop]!=')'){
					output += list.top();
					list.pop();
					list.push(value[loop]);
				}
			}
		}
	}
	while(!list.empty()){
		output+=list.top();
		list.pop();
	}
	return output;
}

int main(int argc, char **argv)
{
	string value = "A-B-C/D*((E+((F-G)/H))*I)/J";

	cout<<OperatorPriority(')','-')<<endl;
	cout<<postfix(value)<<endl;
	return 0;
}
