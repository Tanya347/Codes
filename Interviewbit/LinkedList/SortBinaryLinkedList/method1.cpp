/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    int zeroCount = 0, oneCount = 0;
    ListNode* temp = A;
    
    while(temp != NULL) {
        if(temp -> val == 0)
        zeroCount++;
        else 
        oneCount++;
        temp = temp -> next;
    }
    
    int i = 0;
    temp = A;
    while (i < zeroCount) {
        temp -> val = 0;
        temp = temp -> next;
        i++;
    }
    
    //q p
    //1 0 1 0 1 1 0
    
    i = 0;
    while(i <oneCount) {
        temp -> val = 1;
        temp = temp -> next;
        i++;
    }
    
    return A;
}
