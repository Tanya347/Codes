#include<bits/stdc++.h>
using namespace std;

int bestPoint(int m, int n, vector<vector<int>> people) {
    vector<int> x_coord;
    vector<int> y_coord;

    for(int i = 0; i < m; i++) { 
        for(int j = 0; j < n; j++) {
            if(people[i][j] == 1) {
                x_coord.push_back(i);
            }
        }
    }

    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            if(people[j][i] == 1) {
                y_coord.push_back(i);
            }
        }
    }

    int x = x_coord[floor(x_coord.size() / 2)];
    int y = y_coord[floor(y_coord.size() / 2)];

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
