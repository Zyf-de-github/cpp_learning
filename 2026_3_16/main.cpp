// #include <bits/stdc++.h>
// using namespace std;
//
// class test1 {
//     vector<string>v;
//     int n;
//     void show() {for (int i=0;i<n;i++) {cout<<v[i]<<endl; }}
// public:
//     void test_init() {
//         cin>>n;
//         for (int i=0;i<n;i++) {
//             string s,temp;
//             char before1=0,before2=1,before3=2;
//             cin>>s;
//             for (auto it:s) {
//                 if (it==before1&&before1==before2) {
//                     continue;
//                 }
//                 else if (it==before1&&before3==before2) {
//                     continue;
//                 }
//                 temp=temp+it;
//                 before3=before2;
//                 before2=before1;
//                 before1=it;
//             }
//             v.push_back(temp);
//         }
//         show();
//     }
//
// };
// class test2 {
//
//
// public:
//     void test_init() {
//         int c,d,ans=0;
//         cin>>c>>d;
//         vector<int>v(c);
//         for (int i=0;i<c;i++) {cin>>v[i]; }
//         int ptrl=0,ptrr=0;
//         while (ptrr<c-1) {
//             ptrr++;
//             while (ptrl<ptrr-1&&v[ptrr]-v[ptrl]>d) { ptrl++;}
//             ans+=ptrr-ptrl-1;
//             if (ans>=99997867)ans-=99997867;
//         }
//         while (ptrl<ptrr-1) {
//             ptrl++;
//             if (v[ptrr]-v[ptrl]<=d) {
//                 ans+=ptrr-ptrl-1;
//                 if (ans>=99997867)ans-=99997867;
//             }
//         }
//         cout<<ans<<endl;
//     }
// };
//
// int main() {
//     test2 t;
//     t.test_init();
//     return 0;
// }