Node *evenAfterOdd(Node *head)
{
	//write your code here
    Node* oddStart = NULL;
    Node* evenStart = NULL;
    Node* even = NULL;
    Node* odd = NULL;
    Node* temp = head;
    
    // find place where even and odd start and also maintain even and odd that point to tail of 
    // even and odd ll, basically we are creating two separate linked list even and odd
    while(temp != NULL) {
        
    	if(temp -> data % 2 == 0) {
            if(!evenStart) {
                evenStart = temp;
                even = temp;
            	temp = temp -> next;
            } else {
                even -> next = temp;
            	even = temp;
            	temp = temp -> next;
            }
        }
        
        else {
            
            if(!oddStart) {
                oddStart = temp;
                odd = temp;
                temp = temp -> next;
            } else {
                odd -> next = temp;
                odd = temp;
                temp = temp -> next;
            }
        }
        
    }
    
    
    if(!evenStart || !oddStart) {
        return head;
    } 

    // attach even ll to odd ll and return oddStart;
    odd -> next = evenStart;
    even -> next = NULL;
    return oddStart;
}
