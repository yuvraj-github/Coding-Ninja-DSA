class Stack
{
    Node *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int element)
    {
        Node *newNode = new Node(element);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    int pop()
    {
        if (head == NULL)
        {
            return -1;
        }
        Node *delNode = head;
        int element = head->data;
        head = head->next;
        delete delNode;
        size--;
        return element;
    }

    int top()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
};