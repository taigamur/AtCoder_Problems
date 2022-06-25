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

    string S;
    cin >> S;

    vi A; // 必要な数字
    vi list(10,0); //どちらでも

    rep(i,0,10){
        if(S[i] == 'o'){
            A.push_back(i);
            list[i] = 1;
        }else if(S[i] == 'x'){
            list[i] = 0;
        }else if(S[i] == '?'){
            list[i] = 1;
        }
    }

    int ans = 0;
    for(int i = 0; i <= 9999; i++){
        int a = i / 1000;
        int b = (i / 100) % 10;
        int c = (i / 10) % 10;
        int d = i % 10;


        int j = 1;
        rep(i,0,A.size()){
            if(A[i] == a || A[i] == b || A[i] == c || A[i] == d){
                continue;
            }else{
                j = 0;
                break;
            }
        }

        if(j != 0){
            if(list[a] == 0) continue;
            if(list[b] == 0) continue;
            if(list[c] == 0) continue;
            if(list[d] == 0) continue;

            ans++;
        }
    }
    cout << ans << endl;

}