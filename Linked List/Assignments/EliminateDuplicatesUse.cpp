#include<iostream>
using namespace std;
#include "EleminateDuplicates.cpp"

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

Node *removeDuplicates(Node *head) {
    Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;       
        if(prev->data == temp->data) {    
            if(temp->next != NULL) {
                Node *a = temp;
                prev->next = a->next;
                temp = prev;
                delete a;
            } else {
                prev->next = NULL;
            }
        }
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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}