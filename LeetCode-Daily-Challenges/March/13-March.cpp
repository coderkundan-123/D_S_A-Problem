class Solution {
public:
    //T.C : 0(n * (Tmax (mH(mH+1)/2)));
    typedef long long ll;

    bool check(ll mid, vector<int>& workerTimes, int mH){
        ll h = 0;

        for(int &t : workerTimes){
            double val = (2.0 * mid/t + 0.25);
            if(val < 0) continue;
            h += (ll)(sqrt(val) - 0.5);

            if(h >= mH) {
                return true;
            }
        }

        return h >= mH;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(begin(workerTimes), end(workerTimes));
        ll l = 1;
        ll r = (ll)maxTime * mountainHeight * (mountainHeight + 1)/2;

        ll ans = 0;
        while(l <= r){
            ll mid = l + (r-l)/2;

            if(check(mid, workerTimes, mountainHeight)){
                ans = mid;
                r = mid-1;
            }else {
                l = mid+1;
            }
        }

        return ans;
    }
};
