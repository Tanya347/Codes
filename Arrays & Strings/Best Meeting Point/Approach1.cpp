#include<bits/stdc++.h>
using namespace std;

int median(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr[floor(arr.size() / 2)];
}

int bestPoint(int m, int n, vector<vector<int>> people) {
    vector<int> x_coord;
    vector<int> y_coord;

    for(int i = 0; i < m; i++) { 
        for(int j = 0; j < n; j++) {
            if(people[i][j] == 1) {
                x_coord.push_back(i);
                y_coord.push_back(j);
            }
        }
    }

    int x = median(x_coord);
    int y = median(y_coord);

    int distance = 0;
    for(int i = 0; i < x_coord.size(); i++) {
        distance += abs(x_coord[i] - x) + abs(y_coord[i] - y);
    }

    return distance;
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> people(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin>>people[i][j];
        }
    }
    cout<<bestPoint(m, n, people);
}
