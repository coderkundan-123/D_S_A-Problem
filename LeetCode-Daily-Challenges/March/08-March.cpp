/************cpp solution **********************/
/* T.C : O(n)
   S.C : O(n)
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        string ans;

        for(int i=0; i<n; i++){
            char ch = nums[i][i];

            ans += (ch == '0') ? '1' : '0';
        }

        return ans;
    }
};

/******************* sec Method ********/
/* T.C : O(n^2)
   S.C : O(n)
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;

        for(auto &num : nums){
            st.insert(stoi(num, 0, 2));
        }

        int n = nums.size();
        string ans = "";

        for(int number=0; number<=n; number++){

            if(st.find(number) == st.end()){
                ans = bitset<16>(number).to_string();

                return ans.substr(16-n, n);
            }
        }

        return "";
    }
};
