class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long sum2=0;
        long long temp=n;
        int p=0;
        while(temp>0){
            long long r=temp%10;
            sum2+=r;
            if(r!=0){
                sum+=r*pow(10,p++);
            }
            temp/=10;
        }
        return sum*sum2;
    }
};