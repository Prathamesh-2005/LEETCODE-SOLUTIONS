class MovieRentingSystem {
public:
    typedef pair<int,int>p;

    unordered_map<int,set<p>>avail;  // movie -> price and shop 
    unordered_map<int,set<p>>mp;     //movie -> shop and price
    set<tuple<int,int,int>>rents;     // p s m 
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto & v:entries)
        {
            int s=v[0];
            int m=v[1];
            int p=v[2];
            avail[m].insert({p,s});
            mp[m].insert({s,p});
        }
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
        int cnt=0;
        if(avail.count(movie))
        for(auto& [price,shop]:avail[movie])
        {
            ans.push_back(shop);
            cnt++;
            if(cnt==5)
            {
                break;
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        auto it=mp[movie].lower_bound({shop,INT_MIN});
        int price=it->second;
        avail[movie].erase({price,shop});
        rents.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        auto it=mp[movie].lower_bound({shop,INT_MIN});
        int price=it->second;
        avail[movie].insert({price,shop});
        rents.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        int cnt=0;
        for(auto& [price,shop,movie]:rents)
        {
            ans.push_back({shop,movie});
            cnt++;
            if(cnt==5)
            {
                break;
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */