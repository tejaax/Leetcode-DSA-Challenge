class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> ps(n, INT_MAX);
        vector<int> ss(n, INT_MAX);

        int l = 0, sum = 0;
        int mn = INT_MAX;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            while(sum > target) {
                sum -= arr[l];
                l++;
            }

            if(sum == target) {
                int len = i - l + 1;
                mn = min(mn, len);
            }

            ps[i] = mn;
        }

        l = n - 1;
        sum = 0;
        mn = INT_MAX;

        for(int i = n - 1; i >= 0; i--) {
            sum += arr[i];

            while(sum > target) {
                sum -= arr[l];
                l--;
            }

            if(sum == target) {
                int len = l - i + 1;
                mn = min(mn, len);
            }

            ss[i] = mn;
        }

        int ans = INT_MAX;

        for(int i = 0; i < n - 1; i++) {
            if(ps[i] != INT_MAX && ss[i + 1] != INT_MAX) {
                ans = min(ans, ps[i] + ss[i + 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};