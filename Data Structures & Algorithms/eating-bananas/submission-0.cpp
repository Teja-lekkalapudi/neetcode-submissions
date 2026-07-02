class Solution {
public:
    bool hours(vector<int>& piles,int k,int h){
        int count = 0;
        int n = piles.size();
        for(int i=0;i<n;++i){
            int hour = (piles[i] + k - 1) / k;
            count = count + hour;
        }
        return (count <= h) ? true : false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low <= high){
            int mid = (low + high)>>1;
            bool temp = hours(piles,mid,h);
            if(temp){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};
