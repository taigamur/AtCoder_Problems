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

    int N;
    cin >> N;

    vi A(N);
    int sum = 0;
    rep(i,0,N){
        cin >> A[i];
        sum += A[i];
    }

    int M;
    if(sum % 2 == 0) M = sum / 2;
    else M = (sum / 2) + 1;

    if(N == 1){
        cout << A[0] << endl;
        return 0;
    }
    

    vector<vector<bool>> dp(105, vector<bool>(100005, false));
    dp[0][0] = true;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= sum; j++){

            if(dp[i][j]) dp[i+1][j] = true;

            if(j >= A[i] && dp[i][j-A[i]]) dp[i+1][j] = true;

        }            
    }

    for(int k = M; M <= sum; k++){
        if(dp[N][k]){
            cout << k << endl;
            return 0;
        }
    }

}