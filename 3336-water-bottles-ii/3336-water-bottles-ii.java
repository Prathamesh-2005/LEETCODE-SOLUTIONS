class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles;
        int empty=numBottles;

        while(empty>=numExchange)
        {
            empty=empty-numExchange;
            empty++;
            ans++;
            numExchange++;
        }
        return ans;
    }
}