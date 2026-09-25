class Solution {
public:
    int findDays(vector<int>& weights, int capacity) {
        int days = 0;
        int load = 0;

        for (int i = 0; i < weights.size(); i++) {
         load+=weights[i];
         if(load>capacity)
        {
            days++;
            load=weights[i];
        }
        }
        days++;
       
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for (int i = 0; i < weights.size(); i++) {
            high += weights[i];
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int requiredDays = findDays(weights, mid);

            if (requiredDays <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};