//Tutorial Video : https://www.youtube.com/watch?v=Pa4YwO8B8-w&t=1s
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef unsigned long long int ulli;

int primes[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

ulli dp[68][68];

string convertNumInBinary(ulli num)
{
    string numInBinary = "";
    while (num) {
        numInBinary += ((num % 2) + '0');
        num = num / 2;
    }
    reverse(numInBinary.begin(), numInBinary.end());
    return numInBinary;
}

ulli rec(int len, int sum)
{
    if(len == 0) { return (sum == 0); }
    
    if(dp[len][sum] != -1) return dp[len][sum];
    
    ulli ret = 0;
    ret += rec(len - 1, sum - 0);
    ret += rec(len - 1, sum - 1);
    
    return dp[len][sum] = ret;
}

ulli ans(ulli num)
{
    string numInBinary = convertNumInBinary(num);
    
    ulli ret = 0;
    
    int len = numInBinary.size();
    
    for(int primeItr = 18; primeItr >= 0; primeItr--) {
        
        int sum = primes[primeItr];
        int remain = len;
        
        for(int i = 0; i < len; i++) {
            remain--;
            int binaryDigit = numInBinary[i] - '0';
            
            for(int digit = 0; digit < binaryDigit; digit++) {
                ret += rec(remain, sum - digit);
            }
            sum -= binaryDigit;
        }
    }
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int t;
    scanf("%d", &t);
    while(t--) {
        ulli a, b;
        scanf("%llu %llu", &a, &b);
        printf("%llu\n", ans(b + 1) - ans(a));
    }
    return 0;
}
