class UndergroundSystem {
private:
    unordered_map<int,pair<string,int>> users;
    map<pair<string,string>,pair<double,double>> averageTime;
public:
    UndergroundSystem() {
        users.clear();
        averageTime.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        users.insert({id,{stationName,t}});
    }
    
    void checkOut(int id, string stopStation, int t2) {
        auto [startStation,t1] = users[id];
        
        if(averageTime.find({startStation,stopStation}) != averageTime.end()) {
            auto [totalTime,count] = averageTime[{startStation,stopStation}];
            totalTime += (double)(t2 - t1);
            count += double(1);
            averageTime[{startStation,stopStation}] = {totalTime,count};
        } else{
            averageTime[{startStation,stopStation}] = {t2 - t1,1};
        }
        users.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [totalTime,count] = averageTime[{startStation,endStation}];
        return totalTime/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */