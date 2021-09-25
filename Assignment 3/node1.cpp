

// Name: David VanAsselberg
// Class: CS 3305/Section 1
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 3


// FILE: node1.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.
#include <iostream> // Provides cout and cin
#include "node1.h"//Provides the node1 class
#include <stdio.h>		//provides user input
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
		const node *cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
			++answer;
	
		return answer;
    }
    
    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
		head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry) 
    {
		node *insert_ptr;
    
		insert_ptr = new node(entry, previous_ptr->link( ));
		previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target) 
    // Library facilities used: cstdlib
    {
		node *cursor;
   
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
			if (target == cursor->data( ))
				return cursor;
		return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target) 
    // Library facilities used: cstdlib
    {
		const node *cursor;
   
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
			if (target == cursor->data( ))
			return cursor;
		return NULL;
    }

    node* list_locate(node* head_ptr, size_t position) 
    // Library facilities used: cassert, cstdlib
    {
		node *cursor;
		size_t i;
    
		assert (0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link( );
		return cursor;
	}

	const node* list_locate(const node* head_ptr, size_t position) 
	// Library facilities used: cassert, cstdlib
	{
		const node *cursor;
		size_t i;
    
		assert (0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link( );
		return cursor;
	}

	void list_head_remove(node*& head_ptr)
	{
		node *remove_ptr;

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link( );
		delete remove_ptr;
	}

	void list_remove(node* previous_ptr)
	{
		node *remove_ptr;

		remove_ptr = previous_ptr->link( );
		previous_ptr->set_link( remove_ptr->link( ) );
		delete remove_ptr;
	}

	void list_clear(node*& head_ptr)
	// Library facilities used: cstdlib
	{
		while (head_ptr != NULL)
			list_head_remove(head_ptr);
	}

	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr) 
	// Library facilities used: cstdlib
	{
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;
    
		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data( ));
		tail_ptr = head_ptr;
    
		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link( ); 
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data( ));
			tail_ptr = tail_ptr->link( );
			source_ptr = source_ptr->link( );
		}
    }
	
	
	
	
	
	
	
	
	
	void printList( node *head)
	{
		if(head == NULL){
			return;
		}
		while (head != NULL)
		{
			cout << head->data( ) << " ";
			head = head->link( );
		}
		cout<<endl;
	}
	
	void printList(const node *head)
	{
		if(head == NULL){
			return;
		}
		while (head != NULL)
		{
			cout << head->data( ) << " ";
			head = head->link( );
		}
		cout<<endl;
	}
	
	
	void node::delete_reps(node* start,node** copy)
	{
		node* tail = NULL;
		list_copy(start,*copy,tail);
		struct node *tempNode,*MyList, *duplicateValue;
		node* newtemp = *copy;
		MyList = *copy;
		cout<<endl;
		cout<<"Original list: ";
		if(start == NULL){
			return;
		}
		while (start != NULL)
		{
			cout << start->data_field << " ";
			start = start->link_field;
		}
		cout<<endl;
		cout<<endl;
		while (MyList && MyList->link_field) {
			tempNode = MyList;
			while (tempNode->link_field) {
				if (tempNode->link_field->data_field == MyList->data_field) {
					duplicateValue = tempNode->link_field;
					tempNode->link_field = tempNode->link_field->link_field;
					delete (duplicateValue);
				}else tempNode = tempNode->link_field;
			}MyList = MyList->link_field;
		}
		cout<<"New list after deleting repeated values: ";
		if(newtemp == NULL){
			return;
		}
		while (newtemp != NULL)
		{
			cout << newtemp->data_field << " ";
			newtemp = newtemp->link_field;
		}
		cout<<endl;
		cout<<endl;
	}
	

void node::split_list(node** list1,node** list2, int value) {
	node* temp = NULL;
	node* tail = NULL;
	bool found = false;
	for(int loop = 1; loop <= (int)list_length(*list1);loop++) {
		if(get(*list1,loop) == value)found = true;
		if(found == false)add(&temp,get(*list1,loop));
		if(found == true)add(&*list2,get(*list1,loop));
	}
	list_copy(temp,*list1,tail);
	
}



	int get(node* n1, int position)
	{
		return list_locate(n1,position)->data();
	}
	
	
	
	void add(node** temp, int new_data){ 
		if(*temp == NULL)list_head_insert(*temp,new_data);
		else list_insert(list_locate(*temp,list_length(*temp)),new_data);
	} 
	
	
	void node::sort_list(node** Linkedlist){
		node* Newtemp=*Linkedlist;
		cout<<endl;
		cout<<endl;
		cout<<"Grades list before sorting: ";
		if(Newtemp == NULL)return;
		while (Newtemp != NULL)
		{
			cout << Newtemp->data_field << " ";
			Newtemp = Newtemp->link_field;
		}
		cout<<endl;
		node* newNode=*Linkedlist;
		int DataValue;
		while (newNode!=NULL) {
			node *traverse, *smallest;
			smallest=newNode;
			traverse=newNode->link_field;
			while (traverse!=NULL){
				if (traverse->data_field<smallest->data_field)smallest=traverse;
				traverse=traverse->link_field;
			}DataValue=newNode->data_field;
			newNode->data_field=smallest->data_field;
			newNode=newNode->link_field;
			smallest->data_field=DataValue;
		}
		node* NewtempNode=newNode;
		cout<<endl;
		cout<<"New list after sorting the grades list: ";
		if(NewtempNode == NULL)return;
		while (NewtempNode != NULL)
		{
			cout << NewtempNode->data_field << " ";
			NewtempNode = NewtempNode->link_field;
		}
	}
	

}
