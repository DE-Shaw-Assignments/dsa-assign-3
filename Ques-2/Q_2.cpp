class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int currentNo = 0;
        int change[1001] = {0};
        for (int i = 0; i < trips.size(); i ++) {
            int numP=trips[i][0];
            change[trips[i][1]] += numP;
            change[trips[i][2]] -=numP ;
        }
        for (int i = 0; i <= 1000; i ++) {
            currentNo += change[i];
            if (currentNo > capacity) return false; 
        }
        return true;
   
    }
};