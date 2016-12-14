#include <iostream>
#include <string>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include<unordered_map>
#include <set>
#include <cstring>
#include <iomanip>
#include <list>
#include <bitset>
//#include<bits/stdc++.h>
#define itn int
#define mp make_pair
#define endl "\n"
using namespace std;
typedef long long ll;
int mod = 1e9 + 7 ;
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b); }
int id,arr[5][5],opp;

int terminal()
{
    int sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8;
    
    if(arr[0][0]==id && arr[0][1]==id && arr[0][2]==id)
        return 1;
    
    else if(arr[0][0]==opp && arr[0][1]==opp && arr[0][2]==opp)
        return 2;
    
    else if(arr[1][0]==id && arr[1][1]==id && arr[1][2]==id)
        return 1;
    
    else if(arr[1][0]==opp && arr[1][1]==opp && arr[1][2]==opp)
        return 2;
    
    else if(arr[2][0]==id && arr[2][1]==id && arr[2][2]==id)
        return 1;
    
    else if(arr[2][0]==opp && arr[2][1]==opp && arr[2][2]==opp)
        return 2;
    
    else if(arr[0][0]==id && arr[1][0]==id && arr[2][0]==id)
        return 1;
    
    else if(arr[0][0]==opp && arr[1][0]==opp && arr[2][0]==opp)
        return 2;
    
    else if(arr[0][1]==id && arr[1][1]==id && arr[2][1]==id)
        return 1;
    
    else if(arr[0][1]==opp && arr[1][1]==opp && arr[2][1]==opp)
        return 2;
    
    else if(arr[0][2]==id && arr[1][2]==id && arr[2][2]==id)
        return 1;
    
    else if(arr[0][2]==opp && arr[1][2]==opp && arr[2][2]==opp)
        return 2;
    
    else if(arr[0][0]==id && arr[1][1]==id && arr[2][2]==id)
        return 1;
    
    else if(arr[0][0]==opp && arr[1][1]==opp && arr[2][2]==opp)
        return 2;
    
    else if(arr[0][2]==id && arr[1][1]==id && arr[2][0]==id)
        return 1;
    
    else if(arr[0][2]==opp && arr[1][1]==opp && arr[2][0]==opp)
        return 2;
    
    else
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(arr[i][j]==0)
                    return 0;    //not a terminal state
            }
        }
        return 3 ;// draw
    }
    
}
int alphabeta(int &x,int &y,int a,int b,int player,int turn)
{
    int score=terminal();
    
    int i,j,pts,flag=0;
    /*
    cout<<"\n\n\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"score="<<score<<endl;*/
    if(score)
    {
        if(score==1) return score;  // win
        else if(score==2) return -1;  // lose
        else return 0;  // draw
    }
    
    if(player==1)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]==0)
                {
                    arr[i][j]=id;
                    pts=alphabeta(x, y, a, b, 0,1);
                    //cout<<"pts_p1="<<pts<<endl;
                    if(pts>a)
                    {
                        a=pts;
                        if(turn==0)
                        {
                            x=i;
                            y=j;
                        }
                        
                        //cout<<"pts>a\n"<<"x,y="<<x<<" "<<y<<endl;
                        
                    }
                    if(a>=b)
                    {
                        flag=1;
                        //cout<<"prune\n";
                        arr[i][j]=0;
                        break;
                    }
                    arr[i][j]=0;
                }
            }
            if(flag==1) break;
        }
        
        return a;
    }
    else
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]==0)
                {
                    arr[i][j]=opp;
                    pts=alphabeta(x, y, a, b, 1,1);
                    //cout<<"pts_p2="<<pts<<endl;
                    if(pts<b)
                    {
                        b=pts;
                        //x=i;
                        //y=j;
                        //cout<<"pts<b\n";
                        if(a>=b)
                        {
                            arr[i][j]=0;
                            //cout<<"prune\n";
                            flag=1; break;
                        }
                    }
                    if(a>=b)
                    {
                        arr[i][j]=0;
                        //cout<<"prune\n";
                        flag=1; break;
                    }
                    arr[i][j]=0;
                }
            }
            if(flag==1)
                break;
        }
        return b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int i,j,x=0,y=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            cin>>arr[i][j];
    
    cin>>id;
    opp=2-id+1;
    alphabeta(x,y,-1000,1000,1,0);
    cout<<y<<" "<<x<<endl;
}