class Solution {
public:
    // Brute force try each index as starting and check clock wise whether it completes circle or not    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // Brute Force -> O(N2)
        // for(int i=0;i<n;++i){
        //     int tank = gas[i]-cost[i];
        //     if(tank < 0) continue;
        //     int j= (i+1)%n;
        //     while(i != j){
        //         tank = tank + gas[j] - cost[j];
        //         if(tank < 0) break;
        //         j = (j+1)%n;
        //     }
        //     if(j == i) return i;
        // }
        // return -1;

        //Greedy -> O(N) 

        int total_g = accumulate(gas.begin(),gas.end(),0);
        int total_c = accumulate(cost.begin(),cost.end(),0);
        //Not possible case 
        if(total_g < total_c) return -1;
        //If only possible enters here
        int total = 0;
        int ind = 0;
        for(int i=0;i<n;++i){
            int diff = gas[i]-cost[i];
            total += diff;
            if(total < 0){
                ind = i+1;
                total = 0;
            }
        }
        return ind;
    }
};
