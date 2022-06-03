#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
    ll N;
    cin >> N;
    ll M = 998244353;
    ll P = 499122177;

    ll t = 10;
    ll A;

    ll ans = 0;
    while( 1 ){
        ll sum;
        if(N / t == 0){
            A = N % t;
            A = A - t/10 + 1;
            A = A % M;
            sum = (A * (A + 1)) * P;
            break;
        }else{
            A = t - t / 10 + 1;
            A--;
            A = A % M;
            sum = (A * (A + 1)) * P;
        }
        t = t * 10;
        ans += sum % M;
    }

    cout << ans % M << endl;
    



}