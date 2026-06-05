class Solution {
public:
    int reverse(int num) {
        int ans = 0;

        while(num != 0){
            int lastDigit = num % 10;

            if (ans > INT_MAX / 10||ans < INT_MIN / 10) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }

            ans = ans*10 + lastDigit;

            num = num/10;
        }

        return ans;
    }
};