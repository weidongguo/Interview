typedef struct Node {
	struct Node *next;
	int	val;
	bool visited;
} Node;

Node* newNode(int val);


void append(Node *current, int val); //append at the specified node


void traverse(Node *head);
void traverse(Node *head, int delay_ms);

Node* reverse(Node *head);

Node* midNode(Node *head);

void createLoop(Node *head, int pos);

bool hasLoop(Node *head);

