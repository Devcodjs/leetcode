class DSU{
public:
    vector<int> par , rank;
    DSU(int n){
        par.resize(n + 1);
        rank.resize(n + 1);

        for(int i = 1; i<= n ;i++){
            par[i] = i;
            rank[i] = 0;
        }
    }

    int findPar(int s){
        if(par[s] == s) return s;
        return par[s] = findPar(par[s]);
    }

    void unionP(int e , int f){
        int ep = findPar(e);
        int fp = findPar(f);

        if(rank[ep] > rank[fp]){
            par[fp] = ep;
        }else if(rank[ep] < rank[fp]){
            par[ep] = fp;
        }else{
            par[fp] = ep;
            rank[ep]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto &e : edges){
            int u = e[0] , v = e[1];
            int up = dsu.findPar(u) , vp = dsu.findPar(v);
            if(up == vp){
                return e;
            }
            dsu.unionP(u , v);
        }
        return {};
    }
};