#include<unordered_map>
#include<climits>

int highestFrequency(int arr[], int n) {
    // Write your code here
    
    unordered_map<int, int> count;
    int max_number = INT_MIN, index = 0;
    
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    for(int i = 0; i < n; i++) {
        if(count.find(arr[i]) != count.end()) {
            if(count[arr[i]] > max_number) {
                max_number = count[arr[i]];
                index = i;
            }
        }
    }
    
    return arr[index];
    
}
