class Solution(object):
    def checkOverlap(self, r, x, y, x1, y1, x2, y2):
        closex = max(x1 , min(x2 , x))
        closey = max(y1 , min(y2 , y))
        dist = (closex - x) * (closex - x) + (closey - y) * (closey - y)
        if dist <= r * r:
            return True
        return False