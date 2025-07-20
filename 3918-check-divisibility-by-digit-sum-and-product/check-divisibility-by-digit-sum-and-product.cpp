class Solution {
public:
    bool checkDivisibility(int n) {
        int x=n;
        long long sum=0,mul=1;
        while(x>0){
            int rem=x% 10;
            sum+=rem;
            mul*=rem;
            x=x/10;
        }
        long long ans=sum+mul;
        return (n % ans==0);
    }
};