#include <bits/stdc++.h>
using namespace std;

int main() {
    int find=2025;
    int times=0;
    int ans=2;
    for (int i=2;times<find-1;i++) {
        for (int j=2;j<i;j++) {
            if (i%j==0) {break;}
            if (j==i-1) {
                times++;
                ans=i;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

