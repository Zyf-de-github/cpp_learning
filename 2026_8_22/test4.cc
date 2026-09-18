#include "bits/stdc++.h"
using namespace std;


pair<int, int> func(vector<int>& v, int p) {
    long long total = 1,nozero_total=1;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        total *= v[i];
        if(v[i])nozero_total *= v[i];
    }
    for (int i = 0; i < size - 1; i++) {
        if(v[i]==0)continue;
        long long temp = total / v[i];
        long long temp2 = nozero_total / v[i];
        for (int j = i + 1; j < size; j++) {
            if(v[j]==0)continue;
            long long x = temp / v[j];
            long long x2 = temp2 / v[j];
            if (x * (v[i] + v[j]) % (long long)(1e9 + 7) == p)return{i, j};
            if (x2 * (v[i] + v[j]) % (long long)(1e9 + 7) == p)return{i, j};
        }
    }
    return {-1, -1};
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int>v(n, 0);
        for (int j = 0; j < n; j++)cin >> v[j];
        int p;
        cin >> p;
        pair<int, int>ans = func(v, p);
        if (ans.first == -1 || ans.second == -1)cout << -1 << endl;
        else cout << ans.first + 1 << ' ' << ans.second + 1 << endl;
    }
    return 0;
}

// 1
// 3
// 2 3 4
// 20