class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for(int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first > b.first; // sort by position descending
        });

        int fleets = 0;
        double maxTime = 0;

        for(int i = 0; i < n; i++) {
            // if this car takes more time than fleet ahead, it becomes new fleet
            if(cars[i].second > maxTime) {
                fleets++;
                maxTime = cars[i].second;
            }
        }

        return fleets;
    }
};
