class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))
        {
            return "";
        }
        auto &curr=mp[key];
        string ans="";
        int l=0;
        int h=curr.size()-1;

        while(l<=h){
            int mid=l+(h-l)/2;

            if(curr[mid].second<=timestamp)
            {
                ans=curr[mid].first;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */