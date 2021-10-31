#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        if(n == 0)
            return false;
        auto wordDictSet = unordered_set<string>();
        for(string word : wordDict){
            wordDictSet.insert(word);
        }
        vector<bool> exist = vector<bool>(s.size()+1);
        exist[0] = true;
        for(int i = 0; i <= s.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(exist[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
                    exist[i] = true;
            }
        }

        return exist[s.size()];

    }
};