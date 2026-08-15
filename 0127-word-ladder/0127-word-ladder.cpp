class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string , int> mp;
        int n = wordList.size();
        for(int i = 0 ; i < n ; i++){
            mp[wordList[i]] = i;
        }
        mp.erase(beginWord);
        queue<pair<string , int>> q;
        q.push({beginWord , 1});
        while(!q.empty()){
            auto [s , cnt] = q.front();
            q.pop();
            if(s == endWord) return cnt;
            int m = s.size();
            for(int j = 0 ; j < m ; j++){
                char ori = s[j];
                for(char i = 'a' ; i <= 'z' ; i++){
                    s[j] = i;
                    if(mp.find(s) != mp.end()){
                        q.push({s , cnt + 1});
                        mp.erase(s);
                    }
                }
                s[j] = ori; 
            }
        }
        return 0;
    }
};