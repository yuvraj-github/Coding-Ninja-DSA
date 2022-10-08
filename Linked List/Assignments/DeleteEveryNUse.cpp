#include <iostream>
using namespace std;
#include "DeleteEveryN.cpp"

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
Node *skipMdeleteN(Node *head, int M, int N)
{
    // Write your code here
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    if (M == 0 && N != 0)
    {
        while (temp != NULL)
        {
            for (int j = 0; j < N && temp != NULL; j++)
            {
                Node *a = temp;
                temp = temp->next;
                head = temp;
                delete a;
            }
        }
        return head;
    }
    int i = 0;
    Node *Prev = NULL;

    while (temp != NULL)
    {
        if (i == M)
        {
            for (int j = 0; j < N && temp != NULL; j++)
            {
                Node *a = temp;
                temp = temp->next;
                delete a;
            }
            Prev->next = temp;
            i = 0;
        }
        else
        {
            Prev = temp;
            temp = temp->next;
            i++;
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
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}