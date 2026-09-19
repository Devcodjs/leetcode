class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        int closex = max(x1, min(x , x2));
        int closey = max(y1, min(y , y2));
        int dist = (closex - x) * (closex - x) + (closey - y) * (closey - y);
        if(dist <= r * r) return true;
        return false;
    }
};