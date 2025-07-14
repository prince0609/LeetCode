class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = nums.size() - 1;

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        if(high == 0) {
            return nums[high];
        }

        while(low <= high) {
            int mid = (low + high) / 2;

            
             if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }
            

            if(nums[mid] == nums[mid+1]) {
                mid = mid + 1;
            }

            if((mid - low + 1) % 2 == 0) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return -1;
    }
};