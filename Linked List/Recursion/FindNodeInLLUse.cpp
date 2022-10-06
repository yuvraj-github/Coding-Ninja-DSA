#include <iostream>
using namespace std;
#include "FindNodeInLL.cpp"

Node *takeinput()
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
int findNodeRecLL(Node *head, int n, int pos)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == n)
    {
        return pos;
    }
    return findNodeRecLL(head->next, n, pos + 1);
}
int findNodeRec(Node *head, int n)
{
    // Write your code here
    int pos = 0;
    return findNodeRecLL(head, n, pos);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int val;
        cin >> val;
        cout << findNodeRec(head, val) << endl;
    }
}