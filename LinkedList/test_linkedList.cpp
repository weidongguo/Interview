#include <linkedList.h> // "g++ -I. " add -I. to include current directory as path
#include <iostream>

int main(){
	Node *head = newNode(6);
	for(int i = 0; i < 6; i++){
			append(head,i);	
	}

	traverse(head);
	head = reverse(head);
	traverse(head);
	traverse(midNode(head));

	createLoop(head,3);	
	std::cout << (hasLoop(head) ? "has loop\n": "no loop\n");
	traverse(head, 500);
	
		

	return 0;
}
