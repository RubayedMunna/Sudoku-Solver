#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll maxn=9;

ll arr[maxn][maxn];

bool UsedInBox(ll &row,ll &col,ll num)
{
    ll rowStart=row-row%3;
    ll colStart=col-col%3;

    for(ll i=0;i<3;i++)
    {
        for(ll j=0;j<3;j++)
        {
            if(arr[i+rowStart][j+colStart]==num)
            {
                return false;
            }
        }
    }
    return true;
}

bool UsedInCol(ll &col,ll &num)
{
    for(ll row=0;row<maxn;row++)
    {
        if(arr[row][col]==num)
        {
            return false;
        }
    }
    return true;
}

bool UsedInRow(ll &row,ll &num)
{
    for(ll col=0;col<maxn;col++)
    {
        if(arr[row][col]==num)
        {
            return false;
        }
    }
    return true;
}

bool isSafe(ll row,ll col,ll num)
{
    return UsedInRow(row,num)&&UsedInCol(col,num)&&UsedInBox(row,col,num);
}

bool FindUnassignedLocation(ll &row,ll &col)
{
    ll mn=10,cnt=0;

    for(ll i=0;i<maxn;i++)
    {
        for(ll j=0;j<maxn;j++)
        {
            if(arr[i][j]==0)
            {
                ll cnt=0;
                for(ll k=1;k<=9;k++)
                {
                    if(isSafe(i,j,k))
                    {
                        cnt++;
                    }
                }
                if(cnt<mn)
                {
                    mn=cnt,row=i,col=j;
                }
            }
        }
    }

    if(mn<10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ll SolveSudoku()
{
    ll row,col;
    if(!FindUnassignedLocation(row,col))
    {
        return true;
    }
    for(ll num=1;num<=maxn;num++)
    {
        if(isSafe(row,col,num))
        {
            arr[row][col]=num;

            if(SolveSudoku())
            {
                return true;
            }
            arr[row][col]=0;
        }
    }
    return false;
}

void solve(ll tst)
{

    string str[9];
    for(ll i=0;i<maxn;i++)cin>>str[i];

    for(ll i=0;i<maxn;i++)
    {
        for(ll j=0;j<maxn;j++)
        {
            if(str[i][j]>='0'&&str[i][j]<='9')
            {
                arr[i][j]=str[i][j]-'0';
            }
            else
            {
                arr[i][j]=0;
            }
        }
    }
    SolveSudoku();
    cout<<"Case "<<tst<<": "<<N;
    for(ll i=0;i<maxn;i++)
    {
        for(ll j=0;j<maxn;j++)
        {
            cout<<arr[i][j];
        }
        cout<<N;
    }
}

int main()
{
    Fast;
    ll t=1;
    cin>>t;
    cin.ignore();
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
}
