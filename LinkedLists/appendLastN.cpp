int length(Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head -> next;
    }
    return count;
}

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(head == NULL || n == 0)
        return head;
    
    int l = length(head);
    
    if(n > l)
        return NULL;
    
    int i = 0;
    
    Node* temp = head;
    //reaching the node just before the new head
    while(i < l - n - 1 && temp != NULL) {
        i++;
        temp = temp -> next;
    }
    
    Node* lastNode = temp;
    
    //reaching the last node
    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    
    temp -> next = head;
    head = lastNode -> next;
    lastNode -> next = NULL;
    return head;
  
