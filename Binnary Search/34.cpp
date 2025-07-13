class Solution {
public:
vector <int>  binary_search_first_last(vector<int> &arr, int target) {

    vector <int> ans = {-1, -1};
    int l = 0, r = arr.size() - 1;
    while(l<=r ) {
        int mid = (l+r) / 2;
        if(arr[mid] == target) {
            ans[0] = mid;
            r = mid - 1;
        }
        else if(arr[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    l = 0, r = arr.size() - 1;

    while(l<=r ) {
        int mid = (l+r) / 2;
        if(arr[mid] == target) {
            ans[1] = mid;
            l = mid + 1;
        }
        else if(arr[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return ans;

}
        
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return binary_search_first_last(nums, target);
    }
};