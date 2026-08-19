/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if(node == null) return null;
        HashMap<Node , Node> mp = new HashMap<>();
        mp.put(node , new Node(node.val));
        Queue<Node> q = new LinkedList<>();
        q.offer(node);
        while(!q.isEmpty()){
            Node root = q.peek();q.poll();
            for(Node e : root.neighbors){
                if(!mp.containsKey(e)){
                    mp.put(e , new Node(e.val));
                    q.offer(e);
                }
                mp.get(root).neighbors.add(mp.get(e));
            }
        }
        return mp.get(node);
    }
}