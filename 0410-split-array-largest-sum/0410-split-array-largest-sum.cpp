class Solution {
public:
int countpartition(vector<int>&nums,int mid) 
{
            int n=nums.size();
            int count=1;
            long long sum=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]+sum<=mid)
                {
                    sum+=nums[i];
                }
                else
                {
                    count++;
                    sum=nums[i];
                }
            }
            return count;
        }
        

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        long long high =accumulate(nums.begin(),nums.end(),0LL);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int partitions=countpartition(nums,mid);
            if(partitions<=k)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            
        }
        return low;
    }
  };
        