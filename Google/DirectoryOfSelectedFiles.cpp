/*

I recently had a google interview, and I was asked the below question, let me know if you get it.


Basically I needed to implement cli.


I was given (as strings) as directories e.g.
/a/b/x.txt
/a/b/p.txt
/a/c
/a/d/y.txt
/a/d/z.txt


Also, I was given the selected directories e.g.
/a/d/y.txt
/a/d/z.txt
/a/b/p.txt


My output should be
/a/d
/a/b/p.txt


/a/d
is the answer because it has 2 txt files (y and z), and both are selected.
/a/b/p.txt
is the answer because another file in the directory i.e. /a/b/x.txt is not selected, if it was selected, answer would have been /a/b


Basically, if all items are selected in a particular directory, we need to return the just prev directory.

*/

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    bool is_file;
    int children_count;

    TrieNode() {
        is_file = false;
        children_count = 0;
    }
};

class Trie {
    TrieNode* root;
    
    public:
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const vector<string>& words) {
        TrieNode* ws = root;
        for (const string& word : words) {
            ws->children_count++;
            if (ws->children.find(word) == ws->children.end()) {
                ws->children[word] = new TrieNode();
            }
            ws = ws->children[word];
        }
        ws->is_file = true;
    }
    
    void decrement(const vector<string>& words) {
        TrieNode* ws = root;
        for(const string& word: words) {
            if (ws->children.find(word) == ws->children.end()) {
                return;
            }
            ws -> children_count--;
            ws = ws -> children[word];
        }
    }
    
    string findPath(const vector<string>& words) {
        vector<string> path;
        TrieNode* ws = root;
        for (const string& word : words) {
            ws = ws->children[word];
            if (ws->children_count == 0 || ws->is_file) {
                path.push_back(word);
                break;
            }
            path.push_back(word);
        }
        string result;
        for(int i = 0; i < path.size(); i++) {
            if (i > 0) result += "/";
            result += path[i];
        }
        return result;
    }
};

vector<string> split_path(string path) {
    vector<string> result;
    stringstream ss(path);
    string token;
    while (getline(ss, token, '/')) {
        result.push_back(token);
    }
    return result;
}

vector<string> compress_input(vector<string> all, vector<string> selected) {
    
    Trie t;
    
    for(const string& file_path: all) {
        vector<string> words = split_path(file_path);
        t.insert(words);
    }
    
    for(const string& file_path: selected) {
        vector<string> words = split_path(file_path);
        t.decrement(words);
    }
    
    unordered_map<string, int> mp;
    
    for(const string& file_path: selected) {
        vector<string> words = split_path(file_path);
        string path = t.findPath(words);
        mp[path]++;
    }
    
    vector<string> ans;
    for(auto it: mp) {
        ans.push_back(it.first);
    }
    
    return ans;
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    vector<string> all_files = {"a/b.txt", "b/c.txt", "b/d.txt", "c/e.txt", "c/f/a.txt", "c/f/b.txt", "c/g.txt", "d/a/b.txt"};
    vector<string> selected_files = {"b/c.txt", "b/d.txt", "c/e.txt", "c/f/a.txt", "c/f/b.txt", "d/a/b.txt"};

    vector<string> result = compress_input(all_files, selected_files);
    
    // Print compressed output
    for (const string& path : result) {
        cout << path << endl;
    }
    return 0;
}
