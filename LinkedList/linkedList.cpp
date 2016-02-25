#include <linkedList.h> // use -I. argument for compilation
#include <cstdio>
#include <unistd.h>

Node* newNode(int val){
	Node *n = new Node();
	n->val = val;
	n->next = 0;
	n->visited = false;
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

bool hasLoop(Node *head){ //O(n)
	Node *cur = head;	
	bool flag = head->visited;
	while(cur){
		cur->visited = !cur->visited;		
		if(cur->visited == flag) // must be set twice, to make this true
			return true;
		cur = cur->next;

	}
	return false;
}

