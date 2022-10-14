#include <iostream>
using namespace std;
#include "DeleteALternateNode.cpp"

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
void deleteAlternateNodes(Node *head) {
    if(head == NULL || head->next == NULL) {
        return;
    }
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *a= temp->next;
        if(a->next != NULL) {
            temp->next = a->next;           
            delete a;
        } 
        temp = temp->next;      
    }    
}
int main()
{
    Node *head = takeInput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}