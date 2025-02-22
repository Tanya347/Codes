// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Design a search data structure to store and display recent searches. If
// a user just clicks the search bar without typing anything, it should
// return the N most recent searches. Given a search string it should save
// the search and also return the N most recent searches

class RecentSearches {
private:
    int maxSize;
    list<string> searchList;  // Doubly linked list to store searches in order
    unordered_map<string, list<string>::iterator> searchMap; // Map to store search term & its position

public:
    RecentSearches(int n) {
        maxSize = n;
    }

    void search(string term) {
        if (searchMap.find(term) != searchMap.end()) {
            // If search term exists, move it to front
            searchList.erase(searchMap[term]);  
        }
        else if (searchList.size() == maxSize) {
            // If at capacity, remove the least recent search
            string last = searchList.back();
            searchMap.erase(last);
            searchList.pop_back();
        }

        // Insert at front
        searchList.push_front(term);
        searchMap[term] = searchList.begin();
    }

    void displayRecentSearches() {
        if (searchList.empty()) {
            cout << "No recent searches." << endl;
            return;
        }
        cout << "Recent Searches: ";
        for (auto& search : searchList) {
            cout << search << "  ";
        }
        cout << endl;
    }
};


int main() {
    
    RecentSearches rs(5);

    rs.search("apple");
    rs.search("banana");
    rs.search("orange");
    rs.search("grape");
    rs.search("mango");

    rs.displayRecentSearches(); // apple, banana, orange, grape, mango

    rs.search("banana");  // Moves banana to front
    rs.displayRecentSearches(); // banana, apple, orange, grape, mango

    rs.search("kiwi");  // Adds kiwi, removes mango (oldest)
    rs.displayRecentSearches(); // kiwi, banana, apple, orange, grape

    rs.search("watermelon");  // Adds watermelon, removes grape
    rs.displayRecentSearches(); // watermelon, kiwi, banana, apple, orange
    
    return 0;
}
