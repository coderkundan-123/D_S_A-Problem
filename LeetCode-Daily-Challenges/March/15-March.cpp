/* T.C :O(n log M)
        n = number of elements in the sequence (seq.size())
        m = number of operations performed (append, addAll, multAll, getIndex)
   S.C :O(n)
*/

class Fancy {
public:
    long long M = 1e9+7;
    typedef long long ll;
    
    vector<ll> seq;
    ll add = 0;
    ll mult = 1;

    //Binary exponentiation for fermat's little Therom -> power(mult, M-2)
    ll power(ll a, ll b){
        if(b == 0)
            return 1;
        ll half = power(a,b/2);
        ll ans = (half * half) % M;

        if(b % 2 == 1){
            ans = (ans * a) % M;
        }

        return ans;
    }
    Fancy() {
        
    }
    
    void append(int val) {
        ll x = ((val - add) % M + M) * power(mult, M-2)%M;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add  = (add + inc) % M;
    }
    
    void multAll(int m) {
        mult = (mult * m) % M;
        add = (add * m) % M;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size())
            return -1;
        return (seq[idx]*mult + add)% M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
