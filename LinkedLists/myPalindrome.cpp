Node* reverseLL(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void split(Node *head, Node** front, Node** back) {
    
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    *front = head;
    *back = slow -> next;
    slow -> next = NULL;
}

// 3 9 2 1 9 3
bool isPalindrome(Node *head)
{
    //Write your code here
    if(head == NULL || head -> next == NULL)
        return true;
    
    Node* front;
    Node* back;
    split(head, &front, &back);
    back = reverseLL(back);

    while(front != NULL && back != NULL) {
        if(front -> data != back -> data)
            return false;
        
        front = front -> next;
        back = back -> next;
    }    
    
    return true;
}
