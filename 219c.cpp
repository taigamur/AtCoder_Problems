#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    string X;
    cin >> X;
    int N;
    cin >> N;
    
    vector<int> val(26);
    for(int i = 0; i < 26; i++){
        val[X[i]-'a'] = i;
    }

    vector<vector<int>> list(N,vector<int>());
    for(int i = 0; i < N; i++){
        string t;
        cin >> t;
        for(int j = 0; j < t.size(); j++){
            list[i].push_back(val[t[j]-'a']);
        }
    }
    sort(list.begin(),list.end());
    for(int i = 0; i < N; i++){
        string s;
        for(int j = 0; j < list[i].size(); j++){
            s += X[list[i][j]];
        }
        cout << s <<endl;
    }
}