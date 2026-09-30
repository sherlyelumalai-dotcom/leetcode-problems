class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n= arr.size();
        long long  min=0LL;
        long long max=0LL;
        const int mod=1e9;
        vector<int>nsearr=nsearray(arr);
        vector<int>psearr=psearray(arr);
        vector<int>ngearr=ngearray(arr);
        vector<int>pgearr=pgearray(arr);

        for(int i=0;i<n;i++)
        {
          int leftchoicesmin=i-psearr[i];
          int rightchoicesmin=nsearr[i]-i;
          int leftchoicesmax=i-pgearr[i];
          int rightchoicesmax=ngearr[i]-i;
          min+=(1LL*leftchoicesmin*rightchoicesmin*arr[i]);
          max+=(1LL*leftchoicesmax*rightchoicesmax*arr[i]);
            }
        return max-min;
        
        
        
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
     vector<int>ngearray(vector<int>&arr)
    {
       int n=arr.size();
       stack<int>nge;
       vector<int>ans(n); 
       for(int i=n-1;i>=0;i--)
       {
        while(!nge.empty()&&arr[nge.top()]<=arr[i])
        {
            nge.pop();
        }
        ans[i]=(nge.empty())?n:nge.top();
        nge.push(i);

       }
       return ans;
    }
    vector<int>pgearray(vector<int>&arr)
    {
       int n=arr.size();
       stack<int>pge;
       vector<int>ans(n); 
       for(int i=0;i<n;i++)
       {
        while(!pge.empty()&&arr[pge.top()]<arr[i])
        {
            pge.pop();
        }
        ans[i]=(pge.empty())?-1:pge.top();
        pge.push(i);

       }
       return ans;
    }
};