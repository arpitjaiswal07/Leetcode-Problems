class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int a,b;
        // if (x1 > min(xCenter, x2))
        // a = x1;

        // else if (x1 < min(xCenter, x2))
        // a = min(xCenter, x2);

        // else if (y1 > min(yCenter, y2))
        // b = y1;

        // else if (y1 < min(yCenter, y2))
        // b = min(xCenter, y2);
        
        a = max(x1, min(xCenter, x2));
        b = max(y1, min(yCenter, y2));
        
        int dist_x = xCenter - a;
        int dist_y = yCenter - b;

        return pow(dist_x,2) + pow(dist_y,2) <= pow(radius,2);
    }
};