#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <math.h>
#include <iomanip>
#include <limits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
static const int MAX = 100005;
#define SIZE 10005

struct Node{
    int right, left, parent;
};
// struct Node node[SIZE];

int main(){

    int h,w;
    cin >> h >> w;
    vector<vector<int>> A(h,vector<int>(w,0));

    rep(i,0,h){
        string s;
        cin >> s;
        rep(j,0,s.size()){
            if(s[j] == '+') A[i][j] = 1;
        }
    }

    pair<int,int> p;
    p.first = 0;
    p.second = 0;
    
    vector<vector<pair<int,int>>> dp(h,vector<pair<int,int>>(w));
    dp[0][0] = p;

    rep(i,1,h){
        pair<int,int> b;
        b = dp[i-1][0];
        if( (i) % 2 == 0){
            if(A[i][0] == 1){
                b.first--;
                b.second++;
            }else{
                b.first++;
                b.second--;
            }
            dp[i][0] = b;
        }else{
            if(A[i][0] == 1){
                b.first++;
                b.second--;
            }else{
                b.first--;
                b.second++;
            }
            dp[i][0] = b;
        }
    }
    rep(j,1,w){
        pair<int,int> a;
        a = dp[0][j-1];
        if( j % 2 == 0){
            if(A[0][j] == 1){
                a.first--;
                a.second++;
            }else{
                a.first++;
                a.second--;
            }
            dp[0][j] = a;
        }else{
            if(A[0][j] == 1){
                a.first++;
                a.second--;
            }else{
                a.first--;
                a.second++;
            }
            dp[0][j] = a;
        }
    }
    rep(i,1,h){
        rep(j,1,w){
            pair<int,int> a,b;

            a = dp[i-1][j];
            b = dp[i][j-1];
            
            if( (i+j) % 2 == 0){
                if(A[i][j] == 1){
                    a.first--;
                    a.second++;
                    b.first--;
                    b.second++;
                }else{
                    a.first++;
                    a.second--;
                    b.first++;
                    b.second--;
                }
                if( (a.first - a.second ) > (b.first - b.second )) dp[i][j] = a;
                else dp[i][j] = b;
            }else{
                if(A[i][j] == 1){
                    a.first++;
                    a.second--;
                    b.first++;
                    b.second--;
                }else{
                    a.first--;
                    a.second++;
                    b.first--;
                    b.second++;
                }
                if((a.first - a.second ) > (b.first - b.second )) dp[i][j] = a;
                else dp[i][j] = b;
            }
        }
    }
    
    // rep(i,0,h){
    //     rep(j,0,w){
    //         pair<int,int> p = dp[i][j];
    //         cout << " < " << p.first << " , " << p.second << " > ";
    //     }
    //     cout << endl;
    // }

    pair<int,int> ans = dp[h-1][w-1];
    if(ans.first == ans.second){
        cout << "Draw" << endl;
    }else if(ans.first > ans.second){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
}