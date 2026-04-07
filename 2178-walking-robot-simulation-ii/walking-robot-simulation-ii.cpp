class Robot {
private:
    int height,width;
    int x,y,direction;
    vector<string> str;
    int totalMoves,curr;
    unordered_map<int,tuple<int,int,int>> directions;
    bool move = false;
public:
    Robot(int width, int height) {
        this -> height = height;
        this -> width = width;
        this -> x = this -> y = 0;
        this -> direction = 0;
        str.resize(4);
        str[0] = "East";
        str[1] = "North";
        str[2] = "West";
        str[3] = "South";

        this -> totalMoves = (width - 1) * 2 + (height - 1) * 2; // total Moves from origin to reach origin
        int w = width - 1, h = height - 1, count = 0, k = 1,t = 0;

        directions[count++] = {3,t++,0};
        while(k++ < w) directions[count++] = {0,t++,0};
        k = 1,t = 0;
        directions[count++] = {0,w,t++};
        while(k++ < h) directions[count++] = {1,w,t++};
        k = 1, t = w;
        directions[count++] = {1,t--,h};
        while(k++ < w) directions[count++] = {2,t--,h};
        k = 1, t = h;
        directions[count++] = {2,0,t--};
        while(k++ < h) directions[count++] = {3,0,t--};

        // for(auto [c,tp] : directions) {
        //     cout << c << "  :  ";
        //     auto [d,u,v] = tp;
        //     cout << d << "  :  " << u << "  :  " << v << "\n";
        // }
        this -> curr = 0;
    }
    
    void step(int num) {
        int nextStop = (curr + num) % totalMoves;
        auto [D,X,Y] = directions[nextStop];
        x = X, y = Y, direction = D;
        curr = nextStop;
        move = true;
    }
    
    vector<int> getPos() {
        if(!move) return {0,0};
        return {x,y};
    }
    
    string getDir() {
        return str[direction];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */