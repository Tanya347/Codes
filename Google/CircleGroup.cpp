// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Problem: A circle is define by x-axis position, y-axis position, and a
// radius. A circle group is a collection of circles that overlap. Given a
// list of circles, figure out if they belong to a single circle group

class Circle {
    public:
    int x;
    int y;
    int r;
    Circle(int x, int y, int r) {
        this -> x = x;
        this -> y = y;
        this -> r = r;
    }
};

class DSU {
    public: 
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void unionRank(int u, int v) {
        int u_par = findPar(u);
        int v_par = findPar(v);
        
        if(rank[u_par] < rank[v_par]) {
            parent[u_par] = v_par;
        } else if(rank[u_par] > rank[v_par]) {
            parent[v_par] = u_par;
        } else {
            parent[v_par] = u_par;
            rank[u_par]++;
        }
    }
};

bool isOverlap(const Circle &c1, const Circle &c2) {
    int dist = (c1.x - c2.x)*(c1.x - c2.x) + (c1.y - c2.y)*(c1.y - c2.y);
    return dist <= (c1.r + c2.r)*(c1.r + c2.r); 
}

bool checkCircleGroup(vector<Circle>& circles) {
    int n = circles.size();
    DSU ds(n);
    
    for(int i = 0; i < circles.size(); i++) {
        for(int j = i + 1; j < circles.size(); j++) {
            if(isOverlap(circles[i], circles[j])) {
                ds.unionRank(i, j);
            }
        }
    }
    
    int par = ds.findPar(0);
    for (int i = 1; i < n; i++) {
        if (ds.findPar(i) != par) return false;
    }
    
    return true;
}


int main() {
    
    cout<<"Enter the number of circles you want to input:"<<endl;
    int n;
    cin>>n;
    
    vector<Circle> circles;
    
    for(int i = 0; i < n; i++) {
        int x, y, r;
        cout<<"Enter the center coordinates and radius of circe "<<i + 1<<":"<<endl;
        cin>>x>>y>>r;
        Circle c(x, y, r);
        circles.push_back(c);
    }
    
    cout<<(checkCircleGroup(circles) ? "yes" : "no");
    return 0;
}
