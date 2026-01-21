class BrowserHistory {
private:
    vector<string> Browser;
    int position = -1;
public:
    BrowserHistory(string homepage) {
        Browser.push_back(homepage);
        position = 0;
    }
    
    void visit(string url) {
        vector<string> newBrowser;
        for(int k = 0 ; k <= position ; k++) newBrowser.push_back(Browser[k]);
        Browser = newBrowser;
        Browser.push_back(url);
        position = Browser.size() - 1;
    }
    
    string back(int steps) {
        if(position-steps >= 0) {
            position -= steps;
            return Browser[position];
        }
        position = 0;
        return Browser[0];
    }
    
    string forward(int steps) {
        if(position + steps < Browser.size()) {
            position += steps;
            return Browser[position];
        }
        position = Browser.size()-1;
        return Browser[(int)Browser.size() - 1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */