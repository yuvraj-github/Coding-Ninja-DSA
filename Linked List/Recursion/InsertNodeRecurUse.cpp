#include <iostream>
using namespace std;
#include "InsertNodeRecur.cpp"

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *insertNode(Node *head, int pos, int data)
{    
    if (head == NULL)
    {
        return head;
    }
    Node *newNode = new Node(data);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    head->next = insertNode(head->next, pos - 1, data);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}