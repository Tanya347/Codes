#include<vector>
#include<unordered_map>

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
   
    unordered_map<int, int> map1;
    
    for(int i = 0; i < n; i++) {
        map1[arr1[i]]++;
    }
    
    for(int i = 0; i < m; i++) {
        if(map1[arr2[i]] != 0) {
            cout<<arr2[i]<<endl;
            map1[arr2[i]]--;
        }
    }
}
