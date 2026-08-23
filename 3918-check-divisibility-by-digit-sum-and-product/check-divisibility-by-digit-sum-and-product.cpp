class Solution {
public:
    bool checkDivisibility(int n) {
        int a = n;
        int d_sum =0, d_prod =1;
        while (a != 0){
            int dig = a %10;
            d_sum += dig;
            d_prod *= dig;
            a /= 10;
        }
        if(n % (d_sum+d_prod) == 0) return true;
        return false;
    }
};