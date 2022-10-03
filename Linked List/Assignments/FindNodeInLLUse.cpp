#include <iostream>
using namespace std;
#include "FindNodeInLL.cpp"

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
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int findNode(Node *head, int n){
    // Write your code here.
    int count =0;
    Node *temp = head;
    while (temp != NULL)
    {
        if(temp->data == n) {
            return count;
        }
        count++;
        temp = temp->next;
    }    
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        int n;
        cin>>n;
        cout<<findNode(head,n)<<endl;
    }
}