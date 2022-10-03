#include <iostream>
using namespace std;
#include "AppendLastNtoFirst.cpp"

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
int findLength(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        return 0;
    }
    return 1 + findLength(temp->next);
}

Node *appendLastNToFirst(Node *head, int n)
{
    // Write your code here
    int count = findLength(head);
    if (n < count && n!=0)
    {
        int k = count - n;
        Node *prev = NULL;
        Node *curr = head;
        while (k > 0)
        {
            prev = curr;
            curr = curr->next;
            k--;
        }
        prev->next = NULL;
        Node *temp = head;
        head = curr;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
    return head;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}