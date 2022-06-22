Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1;
    
    Node* head = NULL;
    Node* tail = NULL;
    
    while(head1 != NULL && head2 != NULL) {
        
        if(head == NULL) {
            if(head1 -> data < head2 -> data) {
                head = head1;
                tail = head1;
                head1 = head1 -> next;
            } else {
                head = head2;
                tail = head2;
                head2 = head2 -> next;
            }
            
        } else {
        	if(head1 -> data < head2 -> data) {
                tail -> next = head1;
                tail = head1;
                head1 = head1 -> next;
            } else {
                tail -> next = head2;
                tail = head2;
                head2 = head2 -> next;
            }
        }
    }
    
    if(head1 != NULL) {
        tail -> next = head1;
    }
    
    if(head2 != NULL) {
        tail -> next = head2;
    }
    
    return head;
}
