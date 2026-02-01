class RideSharingSystem {
public:
    queue<int>ride;
    queue<int>drive;
    set<int>st;
    set<int>curr;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        ride.push(riderId);
        curr.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drive.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int>ans(2,-1);
        while(!ride.empty() && st.find(ride.front())!=st.end())
        {
            st.erase(ride.front());
            ride.pop();
            curr.erase(ride.front());
        }
        if(ride.empty() || drive.empty())
        {
            return {-1,-1};
        }
        int ri=ride.front();
        ans[1]=ri;
        ride.pop();
        ans[0]=drive.front();
        drive.pop();
        return ans;
    }
    
    void cancelRider(int riderId) {
        if(curr.find(riderId)!=curr.end())
        {
            st.insert(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */