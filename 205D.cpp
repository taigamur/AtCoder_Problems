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
    int N,Q;
    cin >> N >> Q;

    vll A(N); // 入力の値
    vll B(N); // 埋まっていない個数

    rep(i,0,N){
        cin >> A[i];
        if(i == 0){
            B[0] = A[i] - 1;
        }else{
            B[i] = B[i-1] + (A[i] - A[i - 1] - 1);
        }
    }
    
    rep(i,0,Q){
        ll q;
        cin >> q;
        int t = lower_bound(B.begin(), B.end(), q) - B.begin();

        if(t == N){
            cout << A[N-1] + (q - B[N-1]) << endl;
        }else{
            cout << A[t] - ( B[t] - q + 1 ) << endl;
        }
    }
    

}