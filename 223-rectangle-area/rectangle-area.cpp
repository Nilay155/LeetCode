class Solution {
private:
    int overlappedArea(int ax1,int ay1,int ax2,int ay2,int bx1,int by1,int bx2,int by2) {
        int yl = max(ay1,by1), yu = min(ay2,by2);
        int xl = max(ax1,bx1), xu = min(ax2,bx2);

        if(yu-yl >= 0 && xu-xl >= 0)
            return rectangleArea(xl,yl,xu,yu);
        else
            return 0;
    }
    int rectangleArea(int x1,int y1,int x2,int y2) {
        return (x2 - x1) * (y2 - y1);
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int A = rectangleArea(ax1,ay1,ax2,ay2);
        int B = rectangleArea(bx1,by1,bx2,by2);
        int AB = overlappedArea(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2);
        cout << A << " : " << B << " : " << AB << "\n";
        return A + B - AB;
    }
};