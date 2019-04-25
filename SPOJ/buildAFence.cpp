//https://math.stackexchange.com/questions/4808/why-does-a-circle-enclose-the-largest-area

#include<iostream>
using namespace std;

#define pii 3.14159265358979323846

int main()
{
    while(true) {
        int halfOfCircumference;
        cin >> halfOfCircumference;
        
        if(halfOfCircumference == 0) return 0;
        
        float radius = halfOfCircumference / pii;
        
        float area = (pii * (radius * radius)) / 2.0;
        
        printf("%.2f\n", area);
    }
    return 0;
}
