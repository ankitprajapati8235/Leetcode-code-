class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closetsX = max(x1, min(xCenter, x2));
        int closetsY = max(y1, min(yCenter, y2));

        long long dx = xCenter - closetsX;
        long long dy = yCenter - closetsY;

        long long distanceSquare = dx*dx + dy*dy;
        long long radiusSquare = 1LL * radius * radius;
        if(distanceSquare <= radiusSquare) {
            return true;
        }
        return false;
    }
};