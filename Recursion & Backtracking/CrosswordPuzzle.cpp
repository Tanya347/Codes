/************************************************* QUESTION *****************************************************************************/

Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Constraints
The number of words in the word list lie in the range of: [1,6]
The length of words in the word list lie in the range: [1, 10]
Time Limit: 1 second
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

/************************************************* ANSWER *****************************************************************************/

#include<bits/stdc++.h>
using namespace std;

vector<string> crossword(10);
vector<string> words;
bool flag;

void puzzle(int ind) {
    if(!flag) {
        return;
    }

    if(ind == words.size()) {
        if(flag) {
            for(auto word: crossword) 
                cout<<word<<endl;
            
            flag = false;
        }
        return;
    }

    int i, j, p, q, k;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            
            p = i, q = j;

            for(k = 0; k < words[ind].size() && p + k < 10; k++) {
                if(crossword[p + k][q] != '-' && crossword[p + k][q] != words[ind][k])
                    break;
            }

            if(k == words[ind].size()) {
                vector<string> temp = crossword;
                for(k = 0; k < words[ind].size(); k++)
                    crossword[p + k][q] = words[ind][k];
                    puzzle(ind + 1);
                    crossword = temp;
            }

            for(k = 0; k < words[ind].size() && q + k < 10; k++) {
                if(crossword[p][q + k] != '-' && crossword[p][q + k] != words[ind][k])
                    break;
            }

            if(k == words[ind].size()) {
                vector<string> temp = crossword;
                for(k = 0; k < words[ind].size(); k++)
                    crossword[p][q + k] = words[ind][k];
                puzzle(ind + 1);
                crossword = temp;
            }
        }
    }
}

int main() {
    
    flag = true;
    int i, j;

    for(int i = 0; i < 10; i++) {
        cin>>crossword[i];
    }

    string s, w;
    cin>>w;

    for(auto x : w) {
        if(x == ';') {
            words.push_back(s);
            s = "";
        }
        else 
            s += x;
    }

    words.push_back(s);
    puzzle(0);

    return 0;
}
