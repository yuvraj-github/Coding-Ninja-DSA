class Queue {
	int size;
	Node *head;
	Node *tail;

   public:
    Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		return size;
	}

    bool isEmpty() {
		return head == NULL;
	}

    void enqueue(int data) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

    int dequeue() {
        if(head == NULL) {
			return -1;
		}
		int element = head->data;
		Node *a = head;
		head= head->next;
		delete a;
		size--;
		return element;
    }

    int front() {
        if(head == NULL) {
			return -1;
		}
		return head->data;
    }
};