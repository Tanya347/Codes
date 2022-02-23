#include<iostream>
using namespace std;


    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        // write your code here

        if(sr == dr && sc == dc) {
            cout<<psf<<endl;
            return;
        }

        //horizontal
        for(int i = 1; i <= dc - sc; i++) {
            string temp = psf;
            temp += "h";
            temp += i + 48;
            printMazePaths(sr, sc + i, dr, dc, temp);
        }

        //vertical
        for(int i = 1; i <= dr - sr; i++) {
            string temp = psf;
            temp += "v";
            temp += i + 48;
            printMazePaths(sr + i, sc, dr, dc, temp);
        }

        //diagonal
        for(int i = 1; i <= dc - sc && i <= dr - sr; i++) {
            string temp = psf;
            temp += "d";
            temp += i + 48;
            printMazePaths(sr + i, sc + i, dr, dc, temp);
        }
        
    }

int main() {
        int n ;
        int m ;
        cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }
