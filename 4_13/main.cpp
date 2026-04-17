// #include <bits/stdc++.h>
// using namespace std;
//
// int func(vector<int>& v,int i,bool flag,vector<vector<int>>& dp)//flag=0 不选自己，flag=1 选自己
// {
//     if (i>=v.size())return 0;
//     if (dp[i][flag]!=-1) return dp[i][flag];
//     int a = func(v,i*2,0,dp)+func(v,i*2+1,0,dp)+v[i];
//     dp[i][1]=a;
//     int b1 = func(v,i*2,0,dp)+func(v,i*2+1,1,dp);
//     int b2 = func(v,i*2,1,dp)+func(v,i*2+1,1,dp);
//     int b3 = func(v,i*2,1,dp)+func(v,i*2+1,0,dp);
//     dp[i][0]=max(b1,max(b2,b3));
//     if (flag==0)return dp[i][0];
//     return dp[i][1];
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> v(n+1,-1);
//     vector dp(n+1,vector(2,-1));
//     for (int i=1;i<=n;i++) cin>>v[i];
//     func(v,1,0,dp);
//     cout<<max(dp[1][1],dp[1][0]);
//
//     return 0;
// }
//1

//1
//2 3
//4 5 6 7
//8 9 10 11

// int main()
// {
//     deque<string> dq;
//     map<string,int>m;
//     int max_num,cur=0;
//     cin>>max_num;
//     string str,temp;
//     getline(cin,str);
//
//     while (getline(cin,str))
//     {
//         stringstream ss(str);
//         while (ss>>temp)
//         {
//             if (cur<max_num)
//             {
//                 if (m.find(temp)==m.end()){dq.push_back(temp);m[temp]=1;cur++;}
//                 else m[temp]++;
//             }
//             else
//             {
//                 if (m.find(temp)==m.end())
//                 {
//                     if (cur>0)
//                     {
//                         m.erase(dq.front());
//                         dq.pop_front();
//                         cur--;
//                         dq.push_back(temp);m[temp]=1;cur++;
//                     }
//                 }
//                 else m[temp]++;
//             }
//         }
//         if (dq.empty()==true)cout<<"null";
//         while (dq.empty()==false)
//         {
//             cout<<dq.front()<<" "<<m[dq.front()]<<" ";
//             m.erase(dq.front());
//             dq.pop_front();
//             cur--;
//         }
//         cout<<"\n";
//     }
//     return 0;
// }

// 28
// zws psp fdz fas gxl qua
//
// jzp ekp vap kgb qyv lay buy wle lbb pee wtv kyn wyv ngc
//
//
//
// neq ikg qjk qqf tde pjj nmr
// cog qbx yjg qve dmb erx yli
// ksx jkx ijo wvt wsp rcc pbg ctf xun cpb byo edp pyj jta
//
// hrv nyo dvv muv rnq yyr
//
//
// ywe jde zmi kxq olj gdk ckb xfz aqw
//
// nrt vmj abm pdd itt utk xyy ecy fmo tat fza zcb rap
// axr anx rnl phd yms qam cyq yhm kku vjn yms wox
//
//
// toz xbi dtt hvd cfv uuu rqi hlz jhv rig iky wxp zhu
// scr olw mwk qyy adi
//
// wga icd cjg afn kyu lcq jpk yht
// zit xce pkf tji yxg wke zfb bhw him klh tdg lwg pos fan
//
// jgy ebc ocp nzf yhn yte zqt cyl ytm vrk ecl
// upz hvd ngk dbg fjl bjv ekw ojq edh cte yzr cik nwc pqa
// hjo eki upj ahq dpx fkl wfs app vlr vdf qlb rxb uja ryg
//
// pwk ywg wmv tln eaq flv nwq
// fvz dox yrc izs jmc obo fdw jml zbr shi qmg yqw chj kno ado
// ind fsx nva gox tva jrk gzl dbe
// ych tbr wmy kml xwx ttn
// efv zkk hro hwt loc ihc hbs hyg oug asz dwb zqn jtl
//
//
// hpc zqa tnp mbq vwu mno kno uhx lie shr
// sum skm soy ymq kqh jlu zwh iwi irb
// cwh vsf nmp iqb nry ovx zws gup tvy diu ina obd
// mqd ccr noq gvo oxi
//
// egi xdb rro vlq fvv hkw xch
// vta ege wtf cem bcc zmv bgx vkt gcv gwq rsw iad
//
// tun dfj hst rlu tbe zrx ugx
//
// xqp shc aur uyz ojh gib mfz ulp kzm kfx hhv
// qjl msx bsz lfy fxr mpf hvj xnr kuc ayq mup hye yxz uvj
// ifh ivr ztu wzr mub ens bzg xgu lxy lvi cqv
// bxh jpz bsb uju dbk tru moa hyk gga ull wsy vdm bsv mvr
//

// class Solution {
// public:
//     int findMaximizedCapital(int k, int w, vector<int> profits, vector<int> capital)
//     {
//         vector<pair<int,int>> v;
//         for (int i=0;i<profits.size();i++)v.push_back({capital[i],profits[i]});//花费 利润
//         sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b)
//         {
//             return a.first<b.first;
//         });
//         priority_queue<int> q;
//         int ptr=0;
//         while (k>0)
//         {
//             while (ptr<v.size()&&v[ptr].first<=w)
//             {
//                 q.push(v[ptr].second);
//                 ptr++;
//             }
//             if (q.empty())break;
//             w+=q.top();
//             q.pop();
//             k--;
//         }
//         return w;
//     }
// };

// int main()
// {
//     int n,w,e,k;
//     cin>>n>>w>>e>>k;
//     vector<tuple<int,int,int>> v(n,{0,0,0});
//     for (int i=0;i<n;i++)cin>>get<0>(v[i]);
//     for (int i=0;i<n;i++)cin>>get<1>(v[i]);
//     for (int i=0;i<n;i++)cin>>get<2>(v[i]);
// Solution s;
//     s.findMaximizedCapital(2,0,{1,2,3},{0,1,1});
//     return 0;
// }

// int main()
// {
//     int n,x,k,m;
//     cin>>n>>x>>k;
//     vector<int> begin_time;
//     vector<vector<long long>> tool_num(100002,vector<long long>(n,0));
//
//     for (int i=0;i<k;i++)
//     {
//         int temp;
//         cin>>temp;
//         begin_time.push_back(temp);
//     }
//     cin>>m;
//     for (int i=0;i<m;i++)
//     {
//         int im,jm;
//         cin>>im>>jm;
//         tool_num[jm+1][im]+=1;
//     }
//     for (int i=1;i<100001;i++)
//     {
//         for (int j=0;j<n;j++)
//         {
//             tool_num[i][j]+=tool_num[i-1][j];
//         }
//     }
//     vector<int> ans;
//     for (int i=0;i<k;i++)
//     {
//         int temp=0;
//         for (int j=0;j<n;j++)
//         {
//             temp+=((tool_num[begin_time[i]+x][j]-tool_num[begin_time[i]][j])>0?1:0);
//         }
//         ans.push_back(temp);
//     }
//     for (auto it:ans)cout<<it<<" ";
//     return 0;
// }

// int main()
// {
//     vector<int> v;
//     int n,ans=0,cur=0;
//     cin>>n;
//     for (int i=0;i<n;i++)
//     {
//         int temp;
//         cin>>temp;
//         v.push_back(temp);
//     }
//     for (int i=0;i<n;i++)
//     {
//         cur=max(0,cur+v[i]);
//         ans=max(ans,cur);
//     }
//     if (ans==0)
//     {
//         ans=v[0];
//         for (int i=0;i<n;i++)
//         {
//             ans=max(ans,v[i]);
//         }
//     }
//     cout<<ans;
//     return 0;
// }