class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaB = (bx2-bx1) * (by2-by1);
        int areaA = (ax2-ax1) * (ay2-ay1);

        int over_x = max(0, min(bx2, ax2) - max(bx1, ax1));
        int over_y = max(0, min(by2, ay2) - max(by1, ay1));
        
        return areaB + areaA - over_x*over_y;
    }
};