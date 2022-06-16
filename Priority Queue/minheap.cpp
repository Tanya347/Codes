#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        
         if(isEmpty())
            return INT_MIN;
        
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        
        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;
        
        while(leftChildIndex < pq.size()) {
            
            int minIndex = parentIndex;
            
            if(pq[minIndex] > pq[leftChildIndex]) {
                minIndex = leftChildIndex;
            }

            if(rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]) {
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex){
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
     }
        
        return ans;
    }
        
    
//     int removeMin() {
//         // Write your code here
        
//         if(isEmpty())
//             return 0;
        
//         int ans = pq[0];
//         pq[0] = pq[pq.size() - 1];
//         pq.pop_back();
        
//         int pI = 0, rcI, lcI;
        
//         while(2*pI + 1 < pq.size()){
            
//             lcI = 2*pI + 1;
//             rcI = 2*pI + 2;
//             int minIndex = lcI;
            
//             if(rcI > pq.size())
//                 minIndex = lcI; 
        
//             else if(pq[rcI] < pq[lcI])
//                 minIndex = rcI;
//             else 
//                 minIndex = lcI;
            
//             int temp = pq[pI];
//             pq[pI] = pq[minIndex];
//             pq[minIndex] = temp;
            
//             pI = minIndex;
//         }
        
//         return ans;
//     }
   
};
