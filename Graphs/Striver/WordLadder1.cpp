/********************************************************************** QUESTION **************************************************************************************/

/*

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

 

Constraints:

    1 <= beginWord.length <= 10
    endWord.length == beginWord.length
    1 <= wordList.length <= 5000
    wordList[i].length == beginWord.length
    beginWord, endWord, and wordList[i] consist of lowercase English letters.
    beginWord != endWord
    All the words in wordList are unique.


*/

/********************************************************************** LC **************************************************************************************/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> words;
        words.push(beginWord);

        unordered_set<string> wordlist(wordList.begin(), wordList.end());
        if(wordlist.find(endWord) == wordlist.end())
            return 0;
        
        int length = 1;
        
        while(!words.empty()) {
            int n = words.size();
            while(n--) {
                string curr = words.front();
                words.pop();

                if(curr == endWord)
                    return length;
                
                wordlist.erase(curr);

                for(int i = 0; i < curr.length(); i++) {
                    char t = curr[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        curr[i] = c;
                        if(wordlist.find(curr) != wordlist.end())
                            words.push(curr);
                    }
                    curr[i] = t;
                }
            }
            length++;
        }

        return 0;
    }

/********************************************************************** MY CODE **************************************************************************************/

// 37/50 test cases passed gives TLE T-T
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string, int>> words;

        unordered_map<string, int> wordlist;

        // easier to check using hashmaps whether a word is present or not
        for(int i = 0; i < wordList.size(); i++) {
            wordlist[wordList[i]] = 1;
        }
      
      // set can also be taken but it gives tle for this approach
//         unordered_set<string> wordlist(wordList.begin(), wordList.end());
//         if(wordlist.find(endWord))
//             return 0;

        words.push({beginWord, 1});

        while(!words.empty()) {
          string curr = words.front().first;
          int length = words.front().second;
          words.pop();

          // remove it from wordlist if it exists so that in future it might not mess things up 
          // again by enabling a longer path
          // for eg beginWord is lost -> most -> mist -> list -> lost which is not what we want
          wordlist.erase(curr);

          // if the current string is endWord simply return length of sequence so far
          if(curr == endWord) 
            return length;

          for(int i = 0; i < curr.length(); i++) {
              for(int j = 0; j <= 25; j++) {
                
                // this was giving tle check above solution to see how to remove it
                  string temp = curr;
                  temp[i] = 'a' + j;

                  // we do not want the same word again so check for temp!=curr
                  if(wordlist.find(temp) != wordlist.end() && temp != curr) {
                      words.push({temp, length + 1});
                  } 
              }
          }
        }

        // if endWord not found return 0 as it is not possible
        return 0;
    }
};
