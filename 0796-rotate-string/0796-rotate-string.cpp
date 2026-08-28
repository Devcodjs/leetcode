class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        string t = s + s;
        int j = 0;
        while(j < t.size()){
            int i = 0;
            int st = j;
            while(goal[i] == t[j]){
                i++;
                j++;
                if(i == n) return true;
            }
            j = st + 1;
        }
        return false;
    }
};