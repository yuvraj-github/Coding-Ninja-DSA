#include <iostream>
using namespace std;
#include "LengthOfLLRecur.cpp"

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
int findLength(Node *temp, int count)
{
    if (temp == NULL)
    {
        return count;
    }
    return findLength(temp->next, count++);
}
int length(Node *head)
{
    Node *temp = head;
    int length = findLength(temp, 0);
    return length;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        cout << length(head) << "\n";
        // print(head);
    }
}