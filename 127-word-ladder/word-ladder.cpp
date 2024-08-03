class Solution {
public:
    bool isValid(string &word,string &nextWord,unordered_map<string,bool> &visited){
        
        if(visited[nextWord]) return false ;
        int n = word.size() ;

        int count = 0 ;
        for(int i  = 0 ; i < n ; i++){
            if(word[i] != nextWord[i]) count++ ;
        }
        if(count == 1) return true ;
        else return false  ;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int mini = INT_MAX;
        int n = wordList.size() ;

        bool flag = false ;
        for(auto& it : wordList){
            if(it == endWord) flag = true ;
        }
        if(!flag) return 0 ;
        
        unordered_map<string,bool> visited ;
        queue<pair<string,int>> q ;

        q.push({beginWord,1}) ;
        visited[beginWord] = true ;

        while(!q.empty()){
            pair<string,int> p = q.front() ;
            q.pop() ;

            string word = p.first ;
            int len = p.second ;

            if(word == endWord){
                mini = min(mini,len) ;
            }

            for(int i = 0 ; i < n ; i++){
                if(isValid(word,wordList[i],visited)){
                    q.push({wordList[i],len+1}) ;
                    visited[wordList[i]] = true ;
                }
            }
        }
        if(mini == INT_MAX) return 0 ;
        return mini ;
    }
};