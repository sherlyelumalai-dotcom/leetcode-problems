class Solution {
private:
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            int currEle = arr[i];

            while(!st.empty() && arr[st.top()] >= currEle) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }

        return ans;
    }

    vector<int> findNGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            int currEle = arr[i];

            while(!st.empty() && arr[st.top()] <= currEle) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }

        return ans;
    }

    vector<int> findPSEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            int currEle = arr[i];

            while(!st.empty() && arr[st.top()] > currEle) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }

        return ans;
    }

    vector<int> findPGEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            int currEle = arr[i];

            while(!st.empty() && arr[st.top()] < currEle) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }

        return ans;
    }

public:
    long long subArrayRanges(vector<int> &arr) {
        vector<int> NSE = findNSE(arr);
        vector<int> NGE = findNGE(arr);
        vector<int> PSEE = findPSEE(arr);
        vector<int> PGEE = findPGEE(arr);

        long long sum = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            long long leftMin = i - PSEE[i];
            long long rightMin = NSE[i] - i;

            long long leftMax = i - PGEE[i];
            long long rightMax = NGE[i] - i;

            sum += (rightMax * leftMax * arr[i]);
            sum -= (rightMin * leftMin * arr[i]);
        }

        return sum;
    }
};