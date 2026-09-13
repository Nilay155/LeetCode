class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1)
            return false;
        if(sx == fx || sy == fy) 
            return (abs(sx - fx) + abs(sy - fy)) <= t ? true : false;
        
        int dx = fx - sx;
        int dy = fy - sy;

        int target = max(abs(dx), abs(dy));
        sx += (dx > 0 ? target : -target);
        sy += (dy > 0 ? target : -target);

        if(target <= t)
            return true;
        return false;
    }
};