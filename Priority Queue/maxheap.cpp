#include<vector>

class PriorityQueue {
    // Declare the data members here
	
    vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1)/2;
        
        while(childIndex > 0) {
            if(pq[parentIndex] < pq[childIndex]) {
                swap(pq[parentIndex], pq[childIndex]);
                
                childIndex = parentIndex;
                parentIndex = (childIndex - 1)/2;
            } else {
                break;
            }
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.empty())
            return 0;
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        
        int parentIndex = 0;
        while(2*parentIndex + 1 < pq.size()) {
            int leftChildIndex = parentIndex*2 + 1;
            int rightChildIndex = parentIndex*2 + 2;
            int maxIndex = parentIndex;
            
            if(pq[leftChildIndex] > pq[maxIndex])
                maxIndex = leftChildIndex;
            
            if(rightChildIndex < pq.size() && pq[rightChildIndex] > pq[maxIndex])
                maxIndex = rightChildIndex;
            
            if(maxIndex == parentIndex)
                break;
            
            swap(pq[maxIndex], pq[parentIndex]);
            
            maxIndex = parentIndex;
        }
        
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.empty();
    }
};
