#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, last = 0;
    cin >> n;
    vector<long long> v(n);
    unordered_map<long long, long long> um;

    for (long long i=0; i<n; i++){
        cin >> v[i];
        if (v[i]==0){
            if (i!=0 && v[i-1] == 1) last = i;
            um[last]++;
        }
    }

    last = 0;
    long long res = 0;
    for (long long i=0; i<n; i++){
        if(v[i] == 1){
            res+= (um[last]+1)*(um[i+1]+1);
            last = i+1;
        }
    }

    cout << res << endl;
}