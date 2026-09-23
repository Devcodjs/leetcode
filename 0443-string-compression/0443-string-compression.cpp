class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int w = 0;
        for(int i = 0 ; i < n ;){
            char c = chars[i];
            int j = i;
            while(j < n && chars[j] == c) j++;
            int cnt = j - i;
            chars[w] = c;
            w++;
            if(cnt > 1){
                string p = to_string(cnt);
                for(auto& l : p){
                    chars[w] = l;
                    w++;
                }
            }
            i = j;
        }
        return w;
    }
};