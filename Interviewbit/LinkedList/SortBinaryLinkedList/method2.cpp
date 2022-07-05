ListNode* Solution::solve(ListNode* A) {
    
    //p will be for travelling and q points to prev of p
    //for making required connections
    ListNode* p = A -> next;
    ListNode* q = A;
    
    while(p != NULL) {
        
        // moving p to head and making p point to next element
        if(p -> val == 0) {
            q -> next = p -> next;
            p -> next = A;
            A = p;
            p = q -> next;
        }
        
        // moving p and q one step ahead
        else {
            q = p;
            p = p -> next;
        }
    }
    
    return A;
}
