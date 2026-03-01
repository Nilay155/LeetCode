class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        unordered_map<long long,long long> meetingCount;
        sort(meetings.begin(),meetings.end());

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> currentMeetings;
        priority_queue<long long,vector<long long>,greater<long long>> freeRooms;
        for(long long i = 0 ; i < n ; i++) freeRooms.push(i);

        for(int i = 0 ; i < m ; i++) {
            long long s = meetings[i][0], e = meetings[i][1];

            // Find Rooms that finish meetings before the current meeting start
            while(!currentMeetings.empty() && currentMeetings.top().first <= s) {
                freeRooms.push({currentMeetings.top().second});
                currentMeetings.pop();
            }
            
            // In case all rooms are full at the current start, then freeRooms.empty() == true
            if(freeRooms.empty()) {
                // all rooms are busy and no - one is free before the current start_meeting
                if(!currentMeetings.empty()) {
                    long long end = currentMeetings.top().first;
                    freeRooms.push({currentMeetings.top().second});
                    currentMeetings.pop(); // the meeting ending the earliest ends first and that room gets added
                    currentMeetings.push({(long long)(end + e - s),freeRooms.top()});
                    meetingCount[freeRooms.top()] += 1;
                    freeRooms.pop();
                }
            } 
            else {
                currentMeetings.push({(long long)(e),freeRooms.top()});
                meetingCount[freeRooms.top()] += 1;
                freeRooms.pop();
            }
        }
        long long count = 0, ans = -1;

        for(auto [room,cnt] : meetingCount) {

            if(count < cnt) {
                count = cnt;
                ans = room;
            } else if(count == cnt) {
                count = cnt;
                ans = min(ans,room);
            }
        }
        return ans;
    }
};