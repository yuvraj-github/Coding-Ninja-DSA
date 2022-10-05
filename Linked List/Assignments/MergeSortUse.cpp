#include <iostream>
using namespace std;
#include "MergeSort.cpp"

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
Node *getMid(Node *head)
{
    Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void whenHeadNull(Node *&currHead, Node *&head, Node *&tail)
{
    head = currHead;
    tail = currHead;
    currHead = currHead->next;
}
void whenHeadNotNull(Node *&currHead, Node *&tail)
{
    tail->next = currHead;
    tail = currHead;
    currHead = currHead->next;
}
Node *mergeLinkedList(Node *head1, Node *head2)
{
    Node *head = NULL, *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            if (head == NULL)
            {
                whenHeadNull(head1, head, tail);
            }
            else
            {
                whenHeadNotNull(head1, tail);
            }
        }
        else
        {
            if (head == NULL)
            {
                whenHeadNull(head2, head, tail);
            }
            else
            {
                whenHeadNotNull(head2, tail);
            }
        }
    }
    while (head1 != NULL)
    {
        if (head == NULL)
        {
            whenHeadNull(head1, head, tail);
        }
        else
        {
            whenHeadNotNull(head1, tail);
        }
    }
    while (head2 != NULL)
    {
        if (head == NULL)
        {
            whenHeadNull(head2, head, tail);
        }
        else
        {
            whenHeadNotNull(head2, tail);
        }
    }
    return head;
}
Node *mergeSort(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = getMid(head);
    Node *head2 = mid->next;
    mid->next = NULL;
    Node *finalHead = mergeLinkedList(mergeSort(head), mergeSort(head2));
    return finalHead;
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
        Node *head = takeinput();
        head = mergeSort(head);
        print(head);
    }

    return 0;
}