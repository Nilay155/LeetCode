class FoodRatings {
private:
    struct cmp {
            bool operator()(const pair<int,string> &a,const pair<int,string> &b) const {
            if(a.first == b.first) return a.second < b.second;
            else return a.first > b.first;
        }
    };
    unordered_map<string,set<pair<int,string>,cmp>> cuisineRating;
    unordered_map<string,pair<int,string>> foodRatings;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i = 0 ; i < foods.size() ; i++) {
            foodRatings[foods[i]] = {ratings[i],cuisines[i]};
            cuisineRating[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [rating,cuisine] = foodRatings[food];
        foodRatings[food] = {newRating,cuisine};

        cuisineRating[cuisine].erase({rating,food});
        cuisineRating[cuisine].insert({newRating,food}); 
    }
    
    string highestRated(string cuisine) {
        
        return cuisineRating[cuisine].begin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */