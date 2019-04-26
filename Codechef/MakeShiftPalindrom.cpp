//Problem link : https://www.codechef.com/DARG2019/problems/TUPALIN
#include <iostream>
#include<vector>
using namespace std;
#define MAX 100005

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>count(MAX, 0);
        
        int val;
        for(int i = 0;i < n; i++) {
            cin >> val;
            count[val]++;
        }
        int countOfOdd = 0;
        for(int i = 0; i < MAX; i++) {
            if(count[i] & 1) {
                countOfOdd++;
            }
        }
        if(countOfOdd > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
