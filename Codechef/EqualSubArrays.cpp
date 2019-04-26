//Problem Link : https://www.codechef.com/DARG2019/problems/EQSBAR
#include<iostream>
#include<vector>
using namespace std;
#define MAX 111111

vector<long long>cumulative(MAX);
vector<long long>lef(MAX);
vector<long long>righ(MAX);

int main()
{
    int n;
    cin >> n;
    vector<long long>v(n);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    lef[0] = v[0];
    for(int i = 1; i < n; i++) lef[i] = lef[i - 1] + v[i];
    
    righ[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; i--) righ[i] = righ[i + 1] + v[i];
    
    int l = 1, r = 1;
    long long countOfCuts = 0, sumOfCuts = 0;
    
    while(r < n - 1) {
        long long outerSum = lef[l - 1] + righ[r + 1];
        long long innerSum = lef[r] - lef[l - 1];
        if(outerSum == innerSum) {
            sumOfCuts += (r + l);
            countOfCuts++;
            r++;
        }
        else if(innerSum > outerSum) {
            //here if we add any positve number in innerSum it will always be increasing
            //thats why we can ignore subarray (l, r + 1), (l, r + 2) and so on.
            l++;
        } else {
            r--;
        }
    }
    
    if(!countOfCuts) cout << "-1" << endl;
    else cout << countOfCuts << " " << sumOfCuts << endl;
    
    return 0;
}
