#include <iostream>
#include <vector>
using namespace std;

//class to store the count of various elements
class eleCount {
    
    public:
    
    int element;
    int count;
    
    eleCount() {
        count = 0;
    }
};

vector<int> majorityGeneral(int arr[], int n, int k) {
    //for majority element k must be greater than 1
    
    if(k < 2)
        return {};
        
    //create a temporary array of size k - 1 
    //using the class
    
    eleCount temp[k - 1];
    
    //k - 1 because if we divide n/k there can be two 
    //possibilities either it completely divides n or 
    //it can leave remainder
    
    //in both cases majority element will occur k - 1 times
    
    //traverse the array
    for(int i = 0; i < n; i++) {
        
        int j = 0;
        
        //If arr[i] is already present in the element
        //count array, then increment its count
        
        while(j < k - 1) {
            if(temp[j].element == arr[i]) {
                temp[j].count += 1;
                break;
            }
            j++;
        }
        
        //If arr[i] is not present in temp[]
        if(j == k - 1) {
            
            int l = 0;
            
            //if temp is empty, then place arr[i] in the
            //available space and set count as 1
            
            while(l < k - 1) {
                if(temp[l].count == 0) {
                    temp[l].element = arr[i];
                    temp[l].count = 1;
                    break;
                }
                l++;
            }
            
            //If all the position in the temp[] are filled,
            //then decrease count of every element by 1
            
            if(l == k - 1)
                for(l = 0; l < k - 1; l++)
                temp[l].count -= 1;
            
        }
    }
    
    //check actual counts of potential candidates in temp[]
    //and insert in the answer vector
    
    vector<int> ans;
    for(int i = 0; i < k - 1; i++) {
        
        int c = 0; //actual count
            for(int j = 0; j < n; j++)
                if(arr[j] == temp[i].element)
                    c++;
        
        //if actual count is more than n/k push to vector
        if(c > n / k)
            ans.push_back(temp[i].element);
    }
    
    return ans;
}

int main() {
	//code
	
	int arr[7] = {4, 5, 5, 5, 8, 4, 4};
	vector<int> ans = majorityGeneral(arr, 7, 3);
	for(int i = 0; i < ans.size(); i++) {
	    cout<<ans[i]<<" ";
	}
	return 0;
}
