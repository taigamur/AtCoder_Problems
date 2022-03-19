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
#include <deque>

using namespace std;

typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
static const int MAX = 100005;
#define SIZE 100005


int main(){
    deque<char> deq;
    string S;
    cin >> S;
    rep(i,0,S.size()){
        deq.push_back(S[i]);
    }

    int N;
    cin >> N;

    int state = 1; // 1 or -1;
    rep(i,0,N){
        int T;
        cin >> T;

        if(T == 1){
            state *= -1;
        }else{
            int F;
            cin >> F;
            char C;
            cin >> C;
            if(state == 1){
                if(F == 1){
                    deq.push_front(C);
                }else{
                    deq.push_back(C);
                }
            }else{
                if(F == 1){
                    deq.push_back(C);
                }else{
                    deq.push_front(C);
                }
            }
        }
    }

    string ans = "";
    if(state == 1){
        while(!deq.empty()){
            ans += deq.front();
            deq.pop_front();
        }
    }else{
        while(!deq.empty()){
            ans += deq.back();
            deq.pop_back();
        }
    }

    cout << ans << endl;

}