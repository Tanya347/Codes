/**

 * Definition for binary tree

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

// work like binary search, find mid and then make it new node then make calls on left and right

ListNode* mid(ListNode* start, ListNode* end) {

    ListNode* fast = start;

    ListNode* slow = start;

    while(fast != end && fast -> next != end) {

        fast = fast -> next -> next;

        slow = slow -> next;

    }    

    return slow;

}



TreeNode* convert(ListNode* start, ListNode* end) {

    if(!start || start == end) {

        return NULL;

    }

    ListNode* middle = mid(start, end);

    TreeNode* root = new TreeNode(middle -> val);

    root -> left = convert(start, middle);

    root -> right = convert(middle -> next, end);

    return root;

}

TreeNode* Solution::sortedListToBST(ListNode* A) {

    if( A == NULL)

    return NULL;

    if(A -> next == NULL) {

        return new TreeNode(A -> val);

    }

    return convert(A, NULL);
}
