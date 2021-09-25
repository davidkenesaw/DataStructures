
// Name: David VanAsselberg
// Class: CS 3305/Section 1
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 3

#include <stdio.h> // Provides user input
#include <iostream> // Provides cout and cin
#include "node1.h"  // Provides the node1 class

using namespace std;
using namespace main_savitch_5;


//functions used by this test program:
void menu();
// Postcondition: The menu has been printed to consol.
int get_choice();
// Postcondition: gets user input for what the user wants to select
void PrintChanges(node* n1);
//Postcondition:The linked list is not empty
// Postcondition: prints changes to the linked list
void case3(node* n1);
//Postcondition:The linked list is not empty
// Postcondition: adds a value to a position of the users choice in a linked list.
void case6(node* n1);
//Postcondition:The linked list is not empty
// Postcondition: Prints the element givin an index by the user
void case9(node* n1, int position);
//Postcondition:The linked list is not empty
// Postcondition: removes a value from the list of the user choice.
int main(int argc, char **argv)
{
	node functions;
	double number = 0;
	int choice = 0;
	node* grades = NULL;
	node* list2 = NULL;
	node* n1Copy = NULL;
	node* deletedReps = NULL;
	node* tail = NULL;
	int position = 0;
	
	//populate const grades2
	const node* grades2 = new node(5);
	//const node* grades3 = new node(5);
	//grades2 = grades3;
	//const node* grades4 = new node(5);
	//grades3 = grades4;
	//const node* grades5 = new node(5);
	//grades4 = grades5;
	//const node* grades6 = new node(5);
	//grades5 = grades6;
	//printList(grades2);
	
	cout<<"In the following program: "<<endl;
	cout<<"- The user should use the following methods to populate an empty Linked List called grades"<<endl;
	cout<<"- Then use the other functions to test there functionality"<<endl;
	cout<<"- copied list will be populated by using the list_copy function"<<endl;
	cout<<"- list2 will be populated by using the split_list function"<<endl;
	cout<<endl;
	do {
        menu();
        choice = get_choice();

        switch(choice) {
        case 1:
            cout<<"length of list: "<<list_length(grades)<<endl;
			
			cout<<endl;
			cout<<"list: ";
			cout<<endl;
			printList(grades);
			cout<<endl;
            break;
        case 2:
			cout<<"Insert a number at the beginning of the list: ";
			cin>>number;
			list_head_insert(grades,number);
			PrintChanges(grades);
            break;
        case 3://not finnished
			if(grades==NULL){
				cout<<"Insert a number at the beginning of the list: ";
				cin>>number;
				list_head_insert(grades,number);
			}
			else case3(grades);
			PrintChanges(grades);
            break;
        case 4:
			if(grades == NULL){
				cout<<"The list is empty"<<endl;
				break;
			}
			
			cout<<"Enter a number to see if it exists in the list: ";
			cin>>number;
			if(list_search(grades,number) != NULL){
				cout<<"the number "<<number<<" is in the list"<<endl;
				cout<<endl;
				cout<<"list: ";
				cout<<endl;
				printList(grades);
				cout<<endl;
			}
			else{
				cout<<"the number "<<number<<" is not in the list"<<endl;
				cout<<endl;
				cout<<"list: ";
				cout<<endl;
				printList(grades);
				cout<<endl;
			}
			break;
        case 5://come back to because it might be wrong
            if(grades2 == NULL){
				cout<<"The list is empty"<<endl;
				break;
			}
			
			cout<<"Enter a number to see if it exists in the list: ";
			cin>>number;
			if(list_search(grades2,number) != NULL){
				cout<<"the number "<<number<<" is in the list"<<endl;
				cout<<endl;
				cout<<"list: ";
				cout<<endl;
				printList(grades);
				cout<<endl;
			}
			else{
				cout<<"the number "<<number<<" is not in the list"<<endl;
				cout<<endl;
				cout<<"list: ";
				cout<<endl;
				printList(grades);
				cout<<endl;
			}
			break;
        case 6:
			if(grades == NULL){
				cout<<"The list is empty"<<endl;
				break;
			}
            case6(grades);
			cout<<endl;
			cout<<"list: ";
			cout<<endl;
			printList(grades);
			cout<<endl;
            break;
        case 7://come back to because it might be wrong
            
            break;
        case 8:
            
			if(grades == NULL){
				cout<<"this method cant be used because the list is empty"<<endl;
				break;
			}
			list_head_remove(grades);
			PrintChanges(grades);
            break;
        case 9:
			if(grades == NULL){
				cout<<"this method cant be used because the list is empty"<<endl;
				break;
			}
            
			cout<<"chose a position in the list to remove"<<endl;
			cin>>position;
			if(position == 1){
				list_head_remove(grades);
				PrintChanges(grades);
				break;
			}
			else case9(grades,position);
			PrintChanges(grades);
            break;
        case 10:
            
			cout<<"Clear original list(1)"<<endl;
			cout<<"Clear Coppied list(2)"<<endl;
			cout<<"Clear deleted reps list(3)"<<endl;
			cout<<"Clear List2 from the split_list function(4)"<<endl;
			cin>>number;
			if(number == 1){
				cout<<"The list is now empty"<<endl;
				list_clear(grades);
			}
				
			
			if(number == 2){
				cout<<"The list is now empty"<<endl;
				list_clear(n1Copy);
			}
			
			if(number == 3){
				cout<<"The list is now empty"<<endl;
				list_clear(deletedReps);
			}
			
			if(number == 4){
				cout<<"The list is now empty"<<endl;
				list_clear(list2);
			}
			
            break;
		case 11:
            if(grades == NULL){
				cout<<"The list is empty"<<endl;
				break;
			}
			list_copy(grades,n1Copy,tail);
			cout<<"coppied list: ";
			cout<<endl;
			cout<<"list: ";
			cout<<endl;
			printList(n1Copy);
			cout<<endl;
            break;
		case 12:
            cout<<"Display original list(1)"<<endl;
			cout<<"Display coppied list(2)"<<endl;
			cout<<"Display List with the deleted repeats(3)"<<endl;
			cout<<"Display List2 created by the split_list function(4)"<<endl;
			cin>>number;
			if(number == 1){
				if(grades == NULL){
					cout<<"The list is empty"<<endl;
					break;
				}
				cout<<"list: ";
				printList(grades);
			}
			else if(number == 2){
				if(n1Copy == NULL){
					cout<<"The list is empty"<<endl;
					break;
				}
				cout<<"list: ";
				printList(n1Copy);
			}
			else if(number == 3){
				if(deletedReps == NULL){
					cout<<"The list is empty"<<endl;
					break;
				}
				cout<<"list: ";
				printList(deletedReps);
			}
			else if(number == 4){
				if(list2 == NULL){
					cout<<"The list is empty"<<endl;
					break;
				}
				cout<<"list: ";
				printList(list2);
			}
            break;
		case 13:
            if(grades == NULL){
				cout<<"cant use function because the list is empty"<<endl;
				break;
			}
			else{
				functions.delete_reps(grades,&deletedReps);
				break;
			}
		case 14:
			if(grades == NULL){
				cout<<"cant use function because the list is empty"<<endl;
				break;
			}
			else{
				functions.sort_list(&grades);
				printList(grades);
				cout<<endl;
			}
			break;
		case 15:
			if(grades == NULL){
				cout<<"cant use function because the list is empty"<<endl;
				break;
			}else{
				cout<<"list: ";
				printList(grades);
				cout<<"What number would you like to split the list by: "<<endl;
				cin>>number;
				functions.split_list(&grades,&list2,number);
				cout<<"list1"<<endl;
				printList(grades);
				cout<<endl;
				cout<<"list2"<<endl;
				printList(list2);
				cout<<endl;
				cout<<endl;
			}
			break;
		case 16:
			cout<<"End Program"<<endl;
			break;
        default:
            cout << "Invalid command." << endl;
            break;
        }
		
    } while(choice != 16);
	return 0;
}



void menu(){
	//menu printed out to the console
	cout<<"------------- MAIN MENU ------------------"<<endl;
	cout<<"1. Test function std::size_list_length"<<endl;
	cout<<"2. Test function void list_head_insert"<<endl;
	cout<<"3. Test function void list_insert"<<endl;
	cout<<"4. Test function node *list_search"<<endl;
	cout<<"5. Test function const node *list_search"<<endl;
	cout<<"6. Test function node *list_locate"<<endl;
	cout<<"7. Test function const node *list_locate"<<endl;
	cout<<"8. Test function void list_head_remove"<<endl;
	cout<<"9. Test function void list_remove"<<endl;
	cout<<"10. Test function void list_clear"<<endl;
	cout<<"11. Test function void list_copy"<<endl;
	cout<<"12. Display List"<<endl;
	cout<<"13. Test function void delete_reps"<<endl;
	cout<<"14. Test function void sort_list"<<endl;
	cout<<"15. Test function void split_list"<<endl;
	cout<<"16. Exit program"<<endl;
	cout<<endl;
	cout<<"Enter option number: "<<endl;
}

int get_choice()
{
	//gets user input
    int command;

    cout << ">";
    cin >> command;

    return command;
}

void PrintChanges(node* n1){
	//prints changes to the list
	cout<<"After change"<<endl;
	cout<<"------------"<<endl;
	cout<<"list: ";
	printList(n1);
	cout<<endl;
}


void case3(node* n1){
	// Postcondition: adds a value to a position of the users choice in a linked list.
	double number = 0;
	int position = -1;

	
	
	cout<<"Insert a number into the list: ";
	cin>>number;
	
	cout<<"chose a position to insert a number after"<<endl;
	while(position <= 0||position > (int)list_length(n1)){
		cin>>position;
		if((position <= 0||position > (int)list_length(n1))){
			cout<<"The position you chose is out of bounds of the list"<<endl;
			cout<<"chose a position to insert the number after"<<endl;
		}
	}
	list_insert(list_locate(n1,position),number);
		
}



void case6(node* n1){
	// Postcondition: Prints the element givin an index by the user

	
	int position = -1;
	
	cout<<"chose a position in the list to retrieve its element"<<endl;
	while(position <= 0||position > (int)list_length(n1)){
		cin>>position;
		if((position <= 0||position > (int)list_length(n1))){
			cout<<"The position you chose is out of bounds of the list"<<endl;
			cout<<"chose a position in the list to retrieve its element"<<endl;
		}
	}
	cout<<"The position "<<position<<" contains the number "<<list_locate(n1,position)->data()<<endl;
		
}



void case9(node* n1, int position){
	//Postcondition:The linked list is not empty
	position-=1;
	do{
		
		if((position < 1||position > (int)list_length(n1))){
			cout<<"The position you chose is out of bounds of the list"<<endl;
			cout<<"chose a position in the list to remove"<<endl;
			cin>>position;
			position-=1;
		}
	}while(position < 0||position > (int)list_length(n1));
	
	list_remove(list_locate(n1,position));
		
}
