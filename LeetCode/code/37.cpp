class Solution
{
public:
    bool check(unsigned char a[9][9],int const& i,int const& j)
    {
        int m;
        for(m=0;m<9;++m)
        {
            if(m!=i&&a[m][j]==a[i][j])
                return false;
            if(m!=j&&a[i][m]==a[i][j])
                return false;
        }
        int p=(i/3)*3,q=(j/3)*3,n;
        for(m=0;m<3;++m)
            for(n=0;n<3;++n)
                if((p+m!=i||q+n!=j)&&a[p+m][q+n]==a[i][j])
                    return false;
        return true;
    }
    bool dfs(unsigned char a[9][9],int const& i,int const& j)
    {
        if(j<8)
        {
            if(a[i][j]!=0)
                return dfs(a,i,j+1);
            for(int n=1;n<10;++n)
            {
                a[i][j]=n;
                if(check(a,i,j)&&dfs(a,i,j+1))
                    return true;
            }
            a[i][j]=0;
            return false;
        }
        else if(i<8)
        {
            if(a[i][j]!=0)
                return dfs(a,i+1,0);
            for(int n=1;n<10;++n)
            {
                a[i][j]=n;
                if(check(a,i,j)&&dfs(a,i+1,0))
                    return true;
            }
            a[i][j]=0;
            return false;
        }
        else
        {
            if(a[8][8]!=0)
                return true;
            for(int n=1;n<10;++n)
            {
                a[8][8]=n;
                if(check(a,8,8))
                    return true;
            }
            a[8][8]=0;
            return false;
        }
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        unsigned char a[9][9];
        for(auto p1=board.begin();p1!=board.end();++p1)
            for(auto p2=p1->begin();p2!=p1->end();++p2)
                if(*p2=='.')
                    a[p1-board.begin()][p2-p1->begin()]=0;
                else
                    a[p1-board.begin()][p2-p1->begin()]=*p2-'0';
        dfs(a,0,0);
        for(auto p1=board.begin();p1!=board.end();++p1)
            for(auto p2=p1->begin();p2!=p1->end();++p2)
                if(*p2=='.')
                    *p2=a[p1-board.begin()][p2-p1->begin()]+'0';
    }
};