#include<unordered_map>

int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> freq;
    
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        int x = arr[i];
        int y = 0 - x;
        
        if(x == 0) {
            count += (freq[x]*(freq[x] - 1)) / 2;
        }
    
        else if(freq[y] > 0) {
        
            count += freq[x]*freq[y];
        }
        
        freq[x] = 0;
        freq[y] = 0;
    }
    
    return count;
    
//     int cnt = 0;
//     unordered_map<int,int> ourmap;
    
//     for (int i = 0; i < n; i++)
//     {
//     	int complement = -arr[i];
//         if(ourmap.find(complement) != ourmap.end()){
//             cnt += ourmap[complement];
//         }
        
//        ourmap[arr[i]]++;
//     } 	
//     return cnt;
}
