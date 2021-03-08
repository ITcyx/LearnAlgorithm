class Solution 
{
private:
    char a[20000];
public:
    string replaceSpace(string const& s) 
    {
        auto pa=a;
        for(auto ps=s.begin();ps!=s.end();++ps)
            if(*ps==' ')
            {
                *pa='%';
                ++pa;
                *pa='2';
                ++pa;
                *pa='0';
                ++pa;
            }
            else
            {
                *pa=*ps;
                ++pa;
            }
        *pa='\0';
        return a;
    }
};