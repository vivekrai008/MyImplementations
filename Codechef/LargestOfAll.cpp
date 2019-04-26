//Problem Link : https://www.codechef.com/DARG2019/problems/LOALL
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string str;
    
    int val;
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        str += to_string(val);
    }
    
    sort(str.begin(), str.end());
    cout << str << endl;
    return 0;
}
