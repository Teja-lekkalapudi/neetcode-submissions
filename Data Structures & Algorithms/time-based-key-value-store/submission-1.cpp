class TimeMap {
public:
    //{key,values{value_string,timestamp_int}}
    unordered_map<string,vector<pair<string,int>>> mpp;
    TimeMap() {
        mpp.clear();
    }
    string binary_search(vector<pair<string,int>>& arr,int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        //Initialise ans to n-1 as it is sorted order if there is no element in between it should be latest.
        // Basically as timestamp is increasing it will be last
        int ans = n-1;
        string res = "";
        while(low <= high){
            int mid = (low + high)>>1;
            if(arr[mid].second <= target){
                low = mid+1;
                ans = mid;
                res = arr[mid].first;
            }
            else{
                high = mid-1;
            }
        }
        return res;
    }
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        string value = binary_search(mpp[key],timestamp);
        return value;
    }
};
