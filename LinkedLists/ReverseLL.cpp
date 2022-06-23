//Approach 1


Node *reverseLinkedListRec(Node *head)
{
    //if no node present or only one node present simply return null
 	if(head == NULL || head -> next == NULL) {
        return head;
    }   
    
    //recieve reversed sub linked list
    Node* smallAns = reverseLinkedListRec(head -> next);
    
    //travel the linked list to find tail
    Node* temp = smallAns;
    
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    
    //attach current head to tail
    head -> next = NULL;
    temp -> next = head;
    
    //return new head
    return smallAns;
}



//Approach 2


class Pair {
    public:
    Node* h;
    Node* t;
    
    Pair() {
        
    }
    
    Pair(Node* h, Node* t) {
        this -> h = h;
        this -> t = t;
    }
};

Pair helper(Node *head) {
	if(head == NULL || head -> next == NULL) {
        Pair ans(head, head);
        return ans;
    }    
    
    Pair smallAns = helper(head -> next);
    
    head -> next = NULL;
    smallAns.t -> next = head;
    smallAns.t = smallAns.t -> next;
    
	return smallAns;
}

Node *reverseLinkedListRec(Node *head)
{
 	return helper(head).h;   
}



//Approach 3

Node *reverseLinkedListRec(Node *head)
{
 	if(head == NULL || head -> next == NULL) {
        return head;
    }   
    
    Node* ans = reverseLinkedListRec(head -> next);
    
    Node* tail = head -> next;
    head -> next = NULL;
    tail -> next = head;
    
    return ans;
}



//Approach 4
// A slight variation of Approach 3 which I have coded on my own


Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head == NULL || head -> next == NULL)
        return head;
    
    
    Node *curr = head -> next;
    head -> next = NULL;
    
    Node *temp = reverseLinkedListRec(curr);
    
    curr -> next = head;

    return temp;
    
}


//Approach 5

Node *reverseLinkedList(Node *head) {
    // Write your code here
    Node* c = head;
    Node* n;
    Node* p = NULL;
    
    while(c != NULL) {
        n = c -> next;
        c -> next = p;
        p = c;
        c = n;
    }
    
    return p;
}
