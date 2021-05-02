class Solution 
{
public:
    int mySqrt(int& x) 
    {
        if(x==0)
            return 0;
        long long i=1,j=x,m=(i+j)/2;
        while(j-i>1)
        {
            if(m*m>x)
                j=m;
            else
                i=m;
            m=(i+j)/2;
        }
        return m;
    }
};