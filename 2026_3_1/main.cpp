










// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     // 请在此输入您的代码
//     int len=2,roll=2;
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