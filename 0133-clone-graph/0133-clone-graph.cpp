/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node* , Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node] = new Node(node->val);
        while(!q.empty()){
            Node* root = q.front();q.pop();
            for(auto& e : root->neighbors){
                if(mp.find(e) != mp.end()){
                    mp[root]->neighbors.push_back(mp[e]);
                }else{
                    mp[e] = new Node(e->val);
                    mp[root]->neighbors.push_back(mp[e]);
                    q.push(e);
                }
            }
        }
        return mp[node];
    }
};