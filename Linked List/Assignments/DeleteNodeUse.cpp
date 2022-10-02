#include <iostream>
using namespace std;
#include "DeleteNode.cpp"

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

Node *deleteNode(Node *head, int pos)
{
    Node *temp = head;
    int count = 0;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        Node *a = temp;
        head = temp->next;
        delete a;
        return head;
    }
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL && temp->next != NULL)
    {
        Node *a = temp->next;
        temp->next = a->next;
        delete a;
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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        int pos;
        cin >> pos;
        head = deleteNode(head, pos);
        print(head);
    }
}