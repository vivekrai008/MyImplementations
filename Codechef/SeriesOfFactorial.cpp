//Problem link : https://www.codechef.com/DARG2019/problems/SUMMOD
#include<iostream>
using namespace std;
#define MAX 100005
#define MOD 1000000007

long long factorial[MAX];
long long factorialCumulatives[MAX];

void precomputeFactorials()
{
    factorial[0] = 1LL;
    for(int i = 1; i < MAX; i++) {
        factorial[i] = factorial[i - 1] * (long long)i;
        if(factorial[i] >= MOD) {
            factorial[i] %= MOD;
        }
    }
}

void computeFactorialCumulatives()
{
    factorialCumulatives[0] = 0LL;
    for(int i = 1; i < MAX; i++) {
        factorialCumulatives[i] = factorialCumulatives[i - 1] + factorial[i];
        if(factorialCumulatives[i] >= MOD) {
            factorialCumulatives[i] %= MOD;
        }
    }
}

int main()
{
    precomputeFactorials();
    computeFactorialCumulatives();
    
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", factorialCumulatives[n]);
    }
    return 0;
}
