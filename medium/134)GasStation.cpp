class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currCost = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            currCost += gas[i] - cost[i];
            if(currCost < 0) {
                currCost = 0;
                index = i + 1;
            }
        }
        if(totalGas < totalCost) return -1;
        return index;
    }
};