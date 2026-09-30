class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        long long  sum=0LL;
        const int mod=1e9+7;
        vector<int>nsearr=nsearray(arr);
        vector<int>psearr=psearray(arr);
        for(int i=0;i<n;i++)
        {
          int leftchoices=i-psearr[i];
          int rightchoices=nsearr[i]-i;
          sum+=(1LL*leftchoices*rightchoices*arr[i])%mod;
          sum=sum%mod;

        }
        return sum;
        
        
        
    }
    vector<int>nsearray(vector<int>&arr)
    {
       int n=arr.size();
       stack<int>nse;
       vector<int>ans(n); 
       for(int i=n-1;i>=0;i--)
       {
        while(!nse.empty()&&arr[nse.top()]>=arr[i])
        {
            nse.pop();
        }
        ans[i]=(nse.empty())?n:nse.top();
        nse.push(i);

       }
       return ans;
    }
    vector<int>psearray(vector<int>&arr)
    {
       int n=arr.size();
       stack<int>pse;
       vector<int>ans(n); 
       for(int i=0;i<n;i++)
       {
        while(!pse.empty()&&arr[pse.top()]>arr[i])
        {
            pse.pop();
        }
        ans[i]=(pse.empty())?-1:pse.top();
        pse.push(i);

       }
       return ans;
    }
};