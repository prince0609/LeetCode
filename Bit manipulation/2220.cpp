class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int cnt = 0;
        for(int i = 0; i<32; i++) {
            int first = (start >> i) & 1;
            int second = (goal >> i) & 1;

            if(first != second) {
                cnt++;
            }
        }

        return cnt;
    }
};