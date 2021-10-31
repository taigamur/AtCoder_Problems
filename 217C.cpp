#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
    int N;
    cin >> N;

    vector<int> q(N);
    rep(i,0,N){
        int a;
        cin >> a;
        q[a-1] = i+1;
    }

    rep(i,0,N){
        if(i == N-1){
            cout << q[i] << endl;
            return 0;
        }
        cout << q[i] << " ";
    }

}