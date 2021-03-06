#include <linkedList.h> // use -I. argument for compilation
#include <cstdio>
#include <unistd.h>
#include <unordered_map>

Node* newNode(int val){
	Node *n = new Node();
	n->val = val;
	n->next = 0;
	return n;
}

void append(Node *current, int val){ //append at the specified node
	Node *third;
	if(current->next){ //if not the tail
		third = current->next ;
		current->next = newNode(val);
		current->next->next = third;
	}
	else{// append at the tail
		current->next = newNode(val);
	}
}

void traverse(Node *head, int ms){
	while(head){
		printf("(%d)", head->val); fflush(stdout);
		head = head->next;
		usleep(ms*1000);
	}
	printf("\n");
}

void traverse(Node *head){
	traverse(head, 0);
}

Node* reverse(Node *head){
	Node *cur = head, *next, *prev = 0;
	
	while(cur){	
		next = cur->next;
		cur->next = prev; //mark head tail
		prev = cur;
		cur = next;
	}

	return prev;
}

Node* midNode(Node *head){
	if(head == 0) return 0;
	Node *cur = head, *mid = head;	
	bool flag = false;	
	while(cur->next){
		cur = cur->next;	
		if(flag){
			mid = mid->next;//move 2x as slow
			flag = false;
		}
		else
			flag = true;
	}
	return mid;
}
void createLoop(Node *head, int pos){ // loop back to a certain pos, if pos is negative all out of bound, loop back to head
	int i = 0;
	if(!head)
		return; 

	Node *ptr = head;
	for( ; head->next; i++){	
		if( i == pos){
			ptr = head;	
		}
		head = head->next;
	}
	if( i == pos) { //if hits the last one
		head->next = head;		
	}
	else{	
		head ->next = ptr;	
	}
}

bool hasLoop(Node *head){ //O(n) ,yet use up space as large as making a copy of the linked list. When we are dealing with big linked list, this may not work well
	Node *cur = head;	
	std::unordered_map <Node*, char> hashTable;
	while(cur){ //O(n)
		if( hashTable.count(cur) > 0 ) // check existence O(1)
			return true;				
		else
			hashTable[cur];//store	O(1)

		cur = cur->next;
	}
	return false;
}

bool hasLoopTortoiseHare(Node *head){ // O(n), Tortoise and Hare Algo, best solution 
	Node *slow, *fast1, *fast2;
	slow = fast1 = fast2 = head;	
	
	while(slow && (fast1 = fast2->next) && (fast2 = fast1->next)){
	//fast1 is the first step
	//fast2 is the second step		
		
		if(slow == fast1 || slow == fast2) // match any of the steps	
			return true;
		slow = slow->next; //  slow moves by 1 step
	}

	return false;
}

