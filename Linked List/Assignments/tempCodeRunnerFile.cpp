#include <iostream>
using namespace std;
#include "SwapNode.cpp"

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
Node *swapNodes(Node *head, int i, int j)
{
    // Write your code here
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *a;
    if (i == 0 && j > 0)
    {
        a = temp;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (i == j)
            {
                prev->next = a;
                temp->next = a->next;
                a->next = NULL;
                head = temp;
                return head;
            }
            else
            {
                prev = temp;
                temp = temp->next;
                i++;
            }
        }
        return head;
    }
    return head;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i, j;
        Node *head = takeinput();
        cin >> i;
        cin >> j;
        head = swapNodes(head, i, j);
        print(head);
    }
    return 0;
}