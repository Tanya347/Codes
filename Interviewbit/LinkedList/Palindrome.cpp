/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseLL(ListNode* B) {
    ListNode* curr = B;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

void split(ListNode* head, ListNode** front, ListNode** back) {
    ListNode* slow = head;
    ListNode* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    *front = head;
    *back = slow -> next;
    slow -> next = NULL;
}

int Solution::lPalin(ListNode* A) {
    if(A == NULL || A -> next == NULL)
        return true;
        
    ListNode* front;
    ListNode* back;
    
    split(A, &front, &back);
    
    back = reverseLL(back);
    
    while(front != NULL && back != NULL) {
        if(front -> val != back -> val)
            return false;
        front = front -> next;
        back = back -> next;
    }
    
    return true;
}
