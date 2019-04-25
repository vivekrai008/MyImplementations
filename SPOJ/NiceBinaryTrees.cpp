#include<iostream>
using namespace std;

string str;
int i;

int depth()
{
    if(str[i++] == 'l') {
        return 1;
    }
    return max(depth(), depth()) + 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> str;
        i = 0;
        cout << depth() - 1 << endl;
    }
    return 0;
}
