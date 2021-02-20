#include <iostream>

using namespace std;

int main()
{
    long a;
    cin>>a;
    long b;
    while(a%2==0)
    {
        cout<<2<<" ";
        a/=2;
    }
    for(b=3;b<=a&&b*b<=a;b+=2)
    {
        if(a%b!=0)
            continue;
        cout<<b<<" ";
        a/=b;
        if(a%b==0)
            b-=2;
    }
    if(a!=1)
        cout<<a<<" ";
    return 0;
}