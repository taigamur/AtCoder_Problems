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

class Edge{
    public: 
    int t, w;
    Edge();
    Edge(int t, int w): t(t), w(w){};
};
// vector<Edge> G[MAX];



int main(){
    int N;
    cin >> N;

    int M;
    cin >> M;

    int K;
    cin >> K;

    vll sum(M+1,0);
    vector<vector<ll>> table(N+1,vector<ll>(M+1,0) );

    rep(j,1,M+1){
        table[0][j] = 1;
        sum[j] = sum[j-1] +  table[0][j];
    }

    rep(i,1,N){
        rep(j,1,M+1){

            if(K == 0){
                table[i][j] = sum[M];
            }else{
                if(j - K > 0){
                    table[i][j] += sum[j-K] % 998244353;
                }
                if(M - j >= K){
                    table[i][j] += (sum[M] - sum[j+K-1] + 998244353) % 998244353;
                }
            }
        }
        rep(j,1,M+1){
            sum[j] = (sum[j-1] + table[i][j]) % 998244353;
        }
    }
    cout << sum[M] % 998244353 << endl;
}