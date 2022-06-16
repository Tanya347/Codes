

void heapSort(int arr[], int n) {
    // Write your code
    
    for(int i = 1; i < n; i++) {
        int childIndex = i;
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1)/2;
            if(arr[parentIndex] > arr[childIndex]) {
                
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
                
                childIndex = parentIndex;
            }
            else break;
        }
    }
    
    int size = n;
    
    while(size > 1) {
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        
        size--;
        
        int parentIndex = 0;
     
    	while(parentIndex*2 + 1 < size){
            int lcI = 2*parentIndex + 1;
        	int rcI = 2*parentIndex + 2;
        	int minIndex = parentIndex;
        
            if(arr[minIndex] > arr[lcI]) {
                    minIndex = lcI;
            }

            if(rcI < size && arr[rcI] < arr[minIndex]) {
                    minIndex = rcI;
            }

            if(minIndex == parentIndex){
                    break;
            }

            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = minIndex;
    	}
        
    }
    
}


