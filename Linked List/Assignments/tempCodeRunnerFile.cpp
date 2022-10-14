  if(head == NULL || head->next == NULL) {
        return;
    }
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *a= temp->next;
        if(a->next != NULL) {
            temp->next = a->next;           
            delete a;
        } 
        temp = temp->next;      
    }    