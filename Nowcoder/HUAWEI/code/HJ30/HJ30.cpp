#include <iostream>
#include <string>

using namespace std;

void qs(string& c,int i,int j)
{
    if(j-i<3)
        return;
    char a;
    int p=i;
    for(int s=i+2;s<j;s+=2)
        if(c[s]<c[i])
        {
            a=c[s];
            c[s]=c[p+2];
            c[p+2]=a;
            p+=2;
        }
    a=c[p];
    c[p]=c[i];
    c[i]=a;
    qs(c,i,p);
    qs(c,p+2,j);
}

unsigned char rbit(unsigned char a)
{
    a = (((a >> 3) | (((a & 0x04) >> 2) << 1)) << 2) + (((a & 0x03) >> 1) | ((a & 0x01) << 1));
    a=(a>>2)|((a<<2)&0x0C);
    return a;
}

int main()
{
    string a,b,c;
    int i;
    char t[]="0123456789ABCDEF";
    while(cin>>a>>b)
    {
        c=a+b;
        qs(c,0,c.length());
        qs(c,1,c.length());
        for(i=0;i<c.length();++i)
            if(c[i]<='9')
                c[i]=t[rbit(c[i]-'0')];
            else if(c[i]<='F')
                c[i]=t[rbit(c[i]-'A'+10)];
            else if(c[i]<='f'&&c[i]>='a')
                c[i]=t[rbit(c[i]-'a'+10)];
        cout<<c<<endl;
    }
    return 0;
}