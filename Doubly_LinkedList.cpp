//	Doubly Linked List
//
//	A set of structs that are linked togather by pointers, linked list. This sepcifc Linked list 
//  also has two pointers pointing at previous node and as well as the next node. 
//
//
// Parameters  - Main               
// ==========                
//	 words[][30]	Array of words to append into the linked list 
// 	 numb			Iterative value and number to append to linked list
//	 *head			Pointer to keep the memory location of the head of the linked list  
//	 *end 			Pointer to the end of the linked list memory (to traverse the list backwards)
//	 *A				Memorry allocated vaiable to store root value 
//	 
//
// Parameters  - make_newnode            
// ==========     
//   *B		        Memory allocated variable to store the new node information ( Function returns this variable to be used for the next iterations)
//	 
//




#include<stdlib.h>
#include<stdio.h>
#include <string.h>

// Initializing Struct with two pointer variables and values to go in linked list 
struct test {
	int value;
	char word[20];
	struct test *next;
	struct test *prev;
};

// Funciton to create new node
test* make_newnodes (struct test *ptr,int val, struct test *previous, char *letters);

// global declared stucture used to allocate memory 
struct test first;

// main function
int main(){
	//Initalize values that goes into the linked list
	char words[][30] = {"first","Second","Third","Fourth","Fifth","Sixth"};
	int numb = 1;
	
	// Initalize pointers to head/end of the linked list 
	struct test *head;
	struct test *end;
	struct test *previous;
	struct test *A = (test*)malloc(sizeof(first));
	
	//Set values for head node 
	head = A;
	A->value = 0;
	A->prev = NULL;
	strcpy(A->word, "Arun_made");
	
	// While loop through to to append values to new nodes 
	while(numb<6){
		previous = A;
		A = make_newnodes(A , numb, previous, words[numb]);
		numb = numb+1;
	}
	
	// Set the last node memory to the end pointer
	end = A; 
	
	// To print from the top down 
	A = head;
	
	while(A!=NULL ){
		printf("%d\n",A->value);
		A = A->next;
	}
	
	// To print from the end to start
	A = end;
	
	while(A!=NULL){
		printf("%s\n",A->word);
		A = A->prev;
	}
	
}

//Make a new node function
test* make_newnodes (struct test *ptr, int val, struct test *previous, char *letters){
	// Allocate memory for the new node 
	struct test *B = (test*)malloc(sizeof(first));
	
	// Append values 
	ptr->next = B;
	ptr = ptr->next;
	ptr->value = val;
	strcpy(ptr->word, letters);
	ptr->prev = previous;
	ptr->next = NULL;
	
	// Return the memory location of the new node
	return B;
}
