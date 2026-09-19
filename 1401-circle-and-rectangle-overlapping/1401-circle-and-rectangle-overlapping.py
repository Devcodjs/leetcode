class Solution:
    def checkOverlap(self, r: int, x: int, y: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        closex = max(x1 , min(x2 , x))
        closey = max(y1 , min(y2 , y))
        dist = (closex - x) * (closex - x) + (closey - y) * (closey - y)
        if dist <= r * r:
            return True
        return False
        