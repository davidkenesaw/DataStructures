#include <stdio.h>//privides user input
#include <iostream>//provides cout and cin
#include <bits/stdc++.h>//provides standard library functions
#include <stack>//provides stack class
#include <queue>
#include <cctype>//provides isupper
#include <string>//provides isAlpha

using namespace std;

/*
empty() – Returns whether the queue is empty.
size() – Returns the size of the queue.
queue::swap() in C++ STL: Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
queue::emplace() in C++ STL: Insert a new element into the queue container, the new element is added to the end of the queue.
queue::front() and queue::back() in C++ STL– front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
push(g) and pop() – push() function adds the element ‘g’ at the end of the queue. pop() function deletes the first element of the queue.
 * 
 */
bool check(stack<string> list1,queue<string> list){
	while(!list.empty()){
		if(list.front()!=list1.top()){
			return false;
		}
		list1.pop();
		list.pop();
	}
	return true;
}

int main(int argc, char **argv)
{
	string value = "ababa";
	queue<string> list;
	stack<string> list1;
	list.push("1");
	list.push("2");
	list.push("3");
	list.push("4");
	list.push("5");
	list.push("6");
	list1.push("6");
	list1.push("5");
	list1.push("4");
	list1.push("3");
	list1.push("2");
	list1.push("1");
	check(list1,list);
	
	cout<<list.front()<<endl;
	cout<<list.back()<<endl;
	cout<<check(list1,list)<<endl;
	
	return 0;
}

