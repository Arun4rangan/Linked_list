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
struct test* make_newnodes (struct test *ptr,int val, struct test *previous, char *letters);

//Free all the memory used up by linked list 
void delete_All_nodes(struct test *ptr);

//Free all the memory used up by linked list 
struct test* delete_specific_node(struct test *ptr, int value);

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
	struct test *A = (struct test*)malloc(sizeof(first));
	
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
	
	// Iteration Check : 
	A = head;
	while(A!=NULL ){
		printf("%d\n",A->value);
		A = A->next;
	}
	
	A = end;
	
	while(A!=NULL){
		printf("%s\n",A->word);
		A = A->prev;
	}
	
	A = head;
	
	A = delete_specific_node(A, 5);
	
	if(A != NULL){
		end = A;
	}
	
	A = end;
	while(A!=NULL ){
		printf("%d\n",A->value);
		A = A->prev;
	}
	
	return 0;
	
}

//Make a new node function
struct test* make_newnodes (struct test *ptr, int val, struct test *previous, char *letters){
	// Allocate memory for the new node 
	struct test *B = (struct test*)malloc(sizeof(first));
	
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

 // delete all the nodes from linked list 
void delete_All_nodes(struct test *ptr){
	struct test * ptr_2;
	while (ptr != NULL){
		ptr_2 = ptr->next;
		ptr->next = NULL;
		ptr->prev = NULL;
		ptr->value = NULL;
		free(ptr);
		ptr = ptr_2;
	}
	 return;
}


// delete a specific node from the linked list
struct test* delete_specific_node(struct test *ptr, int value){
	while(ptr->next->value != value){
		ptr= ptr->next;
		//if the value dosen't exist within the linked list, function returns NULL;
		if(ptr->next == NULL){
			return NULL;
		}
	}
	
	// If node is the last node on linked list, it frees the node and sends the current pointer to append to end pointer
	if(ptr->next->next == NULL){
		free(ptr->next);
		ptr->next =NULL;
		return ptr;
	}
	
	struct test * ptr_2 = ptr->next;
	ptr->next = ptr->next->next;
	free(ptr_2);
	ptr_2 = ptr;
	ptr= ptr->next;
	ptr->prev = ptr_2;
	return NULL;
}
