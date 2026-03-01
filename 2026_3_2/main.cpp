






// #include <iostream>
// using namespace std;
// int main()
// {
//     // 请在此输入您的代码
//     int n;
//     int ok=0,good=0;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int temp;
//         cin>>temp;
//         if(temp>=60)ok++;
//         if(temp>=85)good++;
//     }
//     printf("%.0f%\n",ok*100.0/n);
//     printf("%.0f%\n",good*100.0/n);
//     return 0;
// }



// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//   // 请在此输入您的代码
//   int begin_num,end_num;
//   cin>>begin_num;
//   cin>>end_num;
//   int ans=0;
//   int begin_num_year=begin_num/10000;
//   int begin_num_mon=(begin_num%10000)/100;
//   int begin_num_day=begin_num%100;
//   int end_num_year=end_num/10000;
//   int end_num_mon=(end_num%10000)/100;
//   int end_num_day=end_num%100;
//   while(begin_num_day!=end_num_day||
//         begin_num_mon!=end_num_mon||
//         begin_num_year!=end_num_year)
//     {
//       int temp=begin_num_year*10000+begin_num_mon*100+begin_num_day;
//       string s=to_string(temp);
//       for(int i=0;i<4;i++)
//       {
//         if(s[i]!=s[7-i])break;
//         if(i==3)ans++;
//       }
//
//       if(begin_num_mon==1||
//          begin_num_mon==3||
//          begin_num_mon==5||
//          begin_num_mon==7||
//          begin_num_mon==8||
//          begin_num_mon==10||
//          begin_num_mon==12)
//          {
//            if(begin_num_day<31)begin_num_day++;
//            else
//            {
//              begin_num_mon++;
//              begin_num_day=1;
//              if(begin_num_mon>12)
//              {
//                begin_num_mon=1;
//                begin_num_year++;
//              }
//            }
//          }
//       else if(begin_num_mon==4||
//          begin_num_mon==6||
//          begin_num_mon==9||
//          begin_num_mon==11)
//          {
//            if(begin_num_day<30)begin_num_day++;
//            else
//            {
//              begin_num_mon++;
//              begin_num_day=1;
//            }
//          }
//       else
//       {
//         if((begin_num_year%4==0&&begin_num_year%100!=0)&&begin_num_year%400==0)
//         {
//            if(begin_num_day<29)begin_num_day++;
//            else
//            {
//              begin_num_mon++;
//              begin_num_day=1;
//            }
//         }
//         else
//         {
//            if(begin_num_day<28)begin_num_day++;
//            else
//            {
//              begin_num_mon++;
//              begin_num_day=1;
//            }
//         }
//       }
//     }
//     string s=to_string(end_num);
//     for(int i=0;i<4;i++)
//     {
//       if(s[i]!=s[7-i])break;
//       if(i==3)ans++;
//     }
//     cout<<ans<<endl;
//   return 0;
// }




// #include <iostream>
// using namespace std;
// int main()
// {
//     // 请在此输入您的代码
//     int year=2020,mon=10,day=2,week=6;
//     int cury=2000,curm=1,curd=1;
//     int ans=0;
//
//     do{
//         if(curm==1||
//         curm==3||
//         curm==5||
//         curm==7||
//         curm==8||
//         curm==10||
//         curm==12)
//         {
//             (week==1||curd==1)?ans+=2:ans+=1;
//             if(curd==31)
//             {
//                 curd=1;
//                 curm==12?curm=1,cury++:curm++;
//             }
//             else curd++;
//         }
//         else if(curm==4||
//         curm==6||
//         curm==9||
//         curm==11)
//         {
//             (week==1||curd==1)?ans+=2:ans+=1;
//             if(curd==30)
//             {
//                 curd=1;
//                 curm++;
//             }
//             else curd++;
//         }
//         else
//         {
//             if((cury%4==0&&cury%100!=0)||cury%400==0)
//             {
//                 (week==1||curd==1)?ans+=2:ans+=1;
//                 if(curd==29)
//                 {
//                     curd=1;
//                     curm++;
//                 }
//                 else curd++;
//             }
//             else
//             {
//                 (week==1||curd==1)?ans+=2:ans+=1;
//                 if(curd==28)
//                 {
//                     curd=1;
//                     curm++;
//                 }
//                 else curd++;
//             }
//         }
//         week++;
//         week%=7;
//     }while(cury!=year||
//            curm!=mon||
//            curd!=day);
//     cout<<ans<<endl;
//     cout<<week<<endl;
//     return 0;
// }





// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     // 请在此输入您的代码
//     int len=20,roll=20;
//     vector<vector<int>> v(len*3,vector<int>{});
//     int num=1;//数
//     int res=-1;//正反向
//     int cur=0;
//     while(v[len-1].size()<roll)
//     {
//         if(res==-1)
//         {
//             v[cur].push_back(num++);
//             if(cur==0)res*=-1;
//             else cur--;
//         }
//         else
//         {
//             if(v[cur].size()==0)res*=-1;
//             v[cur].push_back(num++);
//             cur++;
//         }
//     }
//     cout<<v[len-1][roll-1]<<endl;
//     return 0;
// }




// #include <iostream>
// using namespace std;
//
// bool is_x(int min_num,int max_num)
// {
//     for(int i=2;i<=min_num;i++)
//     {
//         if(min_num%i==0&&max_num%i==0)return false;
//     }
//     return true;
// }
//
// int main()
// {
//     int dbug=2020;
//     int max_num=1;
//     int ans=0;
//     for(int i=2;i<=dbug;i++)
//     {
//         for(int j=1;j<i;j++)
//         {
//             if(is_x(j,i))ans++;
//         }
//     }
//     cout<<2*ans+1<<endl;
//     return 0;
// }






// #include <iostream>
// using namespace std;
// int main()
// {
//     int dbug=2020;
//     int num=0;
//     int ans=0;
//     for(int i=1;i<=dbug;i++)
//     {
//         string temp=to_string(i);
//         for(int j=0;j<temp.size();j++)
//         {
//             if(temp[j]=='2')ans++;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }







// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     // 请在此输入您的代码
//     int n,x=0;
//     string ans;
//     cin>>n;
//     vector<int> v;
//     for(int i=1;;i++)
//     {
//         x+=i;
//         v.push_back(x);
//         if(x>=n)break;
//     }
//     int num=v.size()+1;//字符串位数
//     int dec=v[v.size()-1]-n;//当前相差的数
//     int seam=0;//最大连续字母片段长度
//
//     for(int i=2;;i++)//判断多少个相同字母片段
//     {
//         if((dec-v[i-2]*(num/i)-(num%i<2?0:v[num%i-2]))<=0)
//         {
//             seam=i;
//             break;
//         }
//     }
//
//     if(seam==2)
//     {
//         for(int i=0;num>0;i++)
//         {
//             if(dec>0)
//             {
//                 ans=(char)('a'+i)+ans;
//                 ans=(char)('a'+i)+ans;
//                 dec-=v[seam-2];
//                 num-=seam;
//             }
//             else
//             {
//                 ans=(char)('a'+i)+ans;
//                 num-=seam-1;
//             }
//         }
//     }
//     else
//     {
//         for(int i=1;i<=(num/seam);i++)
//         {
//             string ans_tmep;
//             int num_temp=num;
//             int dec_temp=dec;
//             int i_temp=i;
//             for(int j=0;num_temp>0;j++)
//             {
//                 if(i_temp>0)
//                 {
//                     for(int k=0;k<seam;k++)
//                     {
//                         ans_tmep=(char)('a'+j)+ans_tmep;
//
//                     }
//                     dec_temp-=v[seam-2];
//                     num_temp-=seam;
//                 }
//                 else
//                 {
//                     if(num_temp>=seam-1)
//                     {
//                         for(int k=0;k<seam-1;k++)
//                         {
//                             ans_tmep=(char)('a'+j)+ans_tmep;
//                         }
//                         dec_temp-=v[seam-3];
//                         num_temp-=seam-1;
//                     }
//                     else
//                     {
//                         num_temp>=2?dec_temp-=v[num_temp-2]:0;
//                         for(int k=0;num_temp>0;k++)
//                         {
//                             ans_tmep=(char)('a'+j)+ans_tmep;
//                             num_temp--;
//                         }
//                     }
//                 }
//                 i_temp--;
//             }
//             if(dec_temp==0)
//             {
//                 ans=ans_tmep;
//                 break;
//             }
//         }
//     }
//
//     cout<<ans;
//     return 0;
// }