#include <stdio.h>//privides user input
#include <iostream>//provides cout and cin
#include <bits/stdc++.h>//provides standard library functions
#include <stack>//provides stack class
#include <cctype>//provides isupper
#include <string>//provides isAlpha

using namespace std;

class ArrayList{
public:
	int* array;
	int size;
	ArrayList(){
		size = 0;
		array = new int[size];
	}
	void addHead(int value){
		
		int* temp;
		if(size == 0){
			size++;
			temp = new int[size];
			temp[0] = value;
			delete array;
			array = temp;
			return;
		}
		size++;
		temp = new int[size];
		temp[0] = value;
		for(int loop = 1; loop < size; loop++){
			temp[loop] = array[loop-1];
		}
		delete array;
		array = temp;
	}
	void addEnd(int value){
		
		size++;
		int* temp = new int[size];
		
		for(int loop = 0; loop < size-1;loop++){
			temp[loop]=array[loop];
		}
		temp[size-1]=value;
		delete array;
		array = temp;
	}
	void deleteEnd(){
		
		if(size == 0){
			cout<<"array empty"<<endl;
			return;
		}
		
		size--;
		int* temp = new int[size];
		for(int loop = 0; loop < size; loop++){
			temp[loop]=array[loop];
		}
		delete array;
		array = temp;
		
	}
	void deleteHead(){
		if(size == 0){
			cout<<"array empty"<<endl;
			return;
		}
		size--;
		int* temp = new int[size];
		for(int loop = 0; loop < size; loop++){
			temp[loop] = array[loop+1];
		}
		delete array; 
		array = temp;
	}
	//void search(int index){
		
	//}
	//bool exists(int value){
		
	//}
	void print(){
		if(size == 0){
			cout<<"arrayList is empty";
			return;
		}
		for(int loop = 0; loop < size; loop++){
			cout<<array[loop]<<" ";
		}
	}
	
};



int main(int argc, char **argv)
{
	
	ArrayList list;
	list.addEnd(1);
	list.addEnd(2);
	//list.addHead(4);
	//list.addHead(3);
	//list.addHead(2);
	//list.addHead(1);
	list.addEnd(3);
	
	
	list.addEnd(4);
	list.addEnd(5);
	//list.deleteEnd();
	//list.deleteEnd();
	//list.deleteEnd();
	//list.deleteEnd();
	//list.deleteEnd();
	list.deleteEnd();
	list.deleteHead();
	list.deleteHead();
	list.deleteHead();
	list.deleteHead();
	list.deleteHead();
	list.print();
	
	return 0;
}
