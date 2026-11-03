class Solution {
public:
     pair<long long, bool> countFactorsAndPrime(int n) {
        int cnt = 0;

        if (n <= 1) return {0, false};

        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                cnt++;

                if (i != n / i) {
                    cnt++;
                }
            }
        }

        return {cnt, cnt == 0};
    }

     long long smallestFactor(int n) {
        if (n <= 1) return -1;

        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                return i;
            }
        }

        return n; // n is prime
    }
    long long minimumMaxValue(int n, int index, int value) {
        pair<long long ,long long> x=countFactorsAndPrime(value);
        if(x.second&&index>0) return  -1;
        if(value==1) return  -1;
        if(value-smallestFactor(value)<2*index) return -1;
        int64_t a =n-index-1;
        int64_t ans=value;
        cout<<smallestFactor(value)<<endl;

        if(a>=1) ans+=smallestFactor(value);
        // cout<<<<endl;
        
        a--;
        if(a>0)  ans+=a*2;
       
        return ans;
    }
};