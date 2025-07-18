class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i, j = 0;
        int n = nums.size();

        while(j<n) {
            if(nums[j] == val) {
                break;
            }
            j++;
        }

        i = j + 1;
        
        while(i<n && j<n) {
            if(nums[i] != val) {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }

        return j;
    }
};