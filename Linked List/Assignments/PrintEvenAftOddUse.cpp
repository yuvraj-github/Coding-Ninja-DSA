#include <iostream>
using namespace std;
#include "PrintEvenAftOdd.cpp"

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
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
Node *evenAfterOdd(Node *head)
{
	//write your code here
    Node *eh=NULL, *et=NULL, *oh=NULL, *ot=NULL;
    if(head == NULL) {
        return head;
    }
    while (head != NULL)
    {
        if(head->data%2 == 0) {
            if(eh == NULL) {
                eh = head;
                et = head;
            } else {
                et->next = head;
                et = head;
            }
        } else {
            if(oh == NULL) {
                oh = head;
                ot = head;
            } else {
                ot->next = head;
                ot = head;
            }
        }
        head = head->next;
    }
    if(eh != NULL) {
        et->next = NULL;
        head = eh;
    }    
    if(oh != NULL) {
        ot->next = eh; 
        head = oh;       
    }
    return head;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        head = evenAfterOdd(head);
        print(head);
    }
    return 0;
}