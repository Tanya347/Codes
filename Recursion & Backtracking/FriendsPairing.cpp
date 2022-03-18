#include<iostream>
#include<vector>
using namespace std;

int counter = 0;

void FriendsPairingHelper(int i, int n, string ans, vector<bool>& used) {
    if(i > n) {
        counter++;
        cout<<counter<<"."<<ans<<endl;
        return;
    }   
    
    if(!used[i]) {
        used[i] = true;
        string temp = ans + "(" + to_string(i) + "), ";
        FriendsPairingHelper(i + 1, n, temp, used);
        
        for(int j = i + 1; j <= n; j++) {
            if(used[j] == false) {
                used[j] = true;
                string temp = ans + "(" + to_string(i) + "," + to_string(j) + "), ";
                FriendsPairingHelper(i + 1, n, temp, used);
                used[j] = false; 
            }
        }
        used[i] = false;
    }
    else {
         FriendsPairingHelper(i + 1, n, ans, used);
    }
}

void FriendsPairing(int n) {
    string ans = "";
    vector<bool> used(n + 1, 0);
    FriendsPairingHelper(1, n, ans, used);
}

int main() {
    int n;
    cin>>n;
    FriendsPairing(n);
}
