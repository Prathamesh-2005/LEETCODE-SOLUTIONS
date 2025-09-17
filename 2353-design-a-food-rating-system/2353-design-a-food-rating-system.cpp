typedef pair<int,string>p;
class FoodRatings {
public:
    struct cmp {
    bool operator()( pair<int,string>& a,  pair<int,string>& b) {
        if (a.first == b.first) {
            return a.second > b.second; 
        }
        return a.first < b.first; 
    }
};

    unordered_map<string,pair<string,int>>mp; 
    unordered_map<string, priority_queue<p, vector<p>, cmp>> pq;
    int n;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n=foods.size();
        for(int i=0;i<n;i++)
        {
            mp[foods[i]]={cuisines[i],ratings[i]};
            pq[cuisines[i]].push({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        mp[food].second=newRating;

        string cuisine=mp[food].first;
        pq[cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto& heap=pq[cuisine];
        while(!heap.empty())
        {
            string food=heap.top().second;
            int rating=heap.top().first;
            
            if(mp[food].second!=rating)
            {
                heap.pop();
            }
            else{
                return food;
            }
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */