class Solution {
public:

    int binary_search(vector<int> &arr, int l, int r, int target) {

        if(l>r) {
            return l; 
        }

        int mid = r - ( r - l)/2;

        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }

        return binary_search(arr, l, r, target);
    }

    int searchInsert(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
};