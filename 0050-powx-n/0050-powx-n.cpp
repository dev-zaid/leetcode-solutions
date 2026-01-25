class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        if (x==0) return 0;
        if (x==1) return 1;
        if (n==1) return x;
        if (n==-1) return 1/x;
        if (x==-1 && n%2==0) return 1;
        if (x==-1 && n%2!=0) return -1;

        long binaryForm = n;
        double ans = 1;

        if(n<0){
            x=1/x;
            binaryForm = -binaryForm;
        }

        while(binaryForm>0){
            // check if the last digit of the binary form is 1;
            if(binaryForm % 2 == 1){
                ans *= x;
            }

            x*=x;
            binaryForm /= 2;
        }

        return ans;
    }
};