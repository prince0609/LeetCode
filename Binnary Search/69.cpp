class Solution {
public:
    int mySqrt(int x) {
        
        if(x <= 1) {
            return x;
        }

        int ans;

        long long l = 1, r = x/2;

        while(l<=r) {
            long long mid = (l+r)/2;

            if(mid*mid == x) {
                return mid;
            }

            if(mid*mid < x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }
};