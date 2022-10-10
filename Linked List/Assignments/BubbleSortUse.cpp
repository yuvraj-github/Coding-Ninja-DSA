#include <iostream>
using namespace std;
#include "BubbleSort.cpp"

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
int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
Node *bubbleSort(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int n = getLength(head) - 1;
    while (n--)

    {
        Node *prev = NULL;
        Node *cur = head;
        while (cur->next != NULL)
        {
            if (cur->data >= cur->next->data)
            {

                if (prev == NULL)
                {
                    // first node
                    Node *nxt = cur->next;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                    head = prev;
                }

                else
                {

                    Node *nxt = cur->next;
                    prev->next = nxt;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                }
            }
            else
            {

                prev = cur;
                cur = cur->next;
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
        Node *head = takeInput();
        head = bubbleSort(head);
        print(head);
    }
}