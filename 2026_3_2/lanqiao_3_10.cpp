// #include <bits/stdc++.h>
// using namespace  std;
//
// string del_zreo(string x)//删除导前零
// {
//     while (x.size()>1&&x[0]=='0')
//     {
//         string s(x.begin()+1,x.end());
//         x=s;
//     }
//     return x;
// }
//
// string add_num(string num1, string num2)
// {
//     string ans = "";
//     int mid=0,size1=num1.size(),size2=num2.size();
//     if (size1<size2||(size1==size2&&num1<num2))swap(num1,num2);
//     size1=num1.size(),size2=num2.size();
//     reverse(num1.begin(),num1.end());
//     reverse(num2.begin(),num2.end());
//     for (int i=0;i<size1;i++)
//     {
//         if (i<size2)
//         {
//             mid=num1[i]+num2[i]-'0'-'0'+mid;
//             ans=char(mid%10+'0')+ans;
//             mid=mid/10;
//         }
//         else
//         {
//             mid=num1[i]-'0'+mid;
//             ans=char(mid%10+'0')+ans;
//             mid=mid/10;
//         }
//     }
//     if (mid)ans='1'+ans;
//     return ans;
// }
//
// string sub_num(string num1, string num2)
// {
//     string ans = "";
//     int mid=0,size1=num1.size(),size2=num2.size();
//     if (size1<size2||(size1==size2&&num1<num2))swap(num1,num2);
//     size1=num1.size(),size2=num2.size();
//     reverse(num1.begin(),num1.end());
//     reverse(num2.begin(),num2.end());
//     for (int i=0;i<size1;i++)
//     {
//         if (i<size2)
//         {
//             int temp=num1[i]-num2[i]-mid;
//             if (temp<0)temp+=10,mid=1;
//             else mid=0;
//             ans=char(temp+'0')+ans;
//         }
//         else
//         {
//             int temp=num1[i]-'0'-mid;
//             if (temp<0)temp+=10,mid=1;
//             else mid=0;
//             ans=char(temp+'0')+ans;
//         }
//     }
//     ans=del_zreo(ans);
//     return ans;
// }
//
// string mul_num(string num1, string num2)
// {
//     string ans = "0";
//     int size1=num1.size(),size2=num2.size();
//     if (size1<size2||(size1==size2&&num1<num2))swap(num1,num2);
//     size1=num1.size(),size2=num2.size();
//     reverse(num1.begin(),num1.end());
//     reverse(num2.begin(),num2.end());
//     for (int i=0;i<size1;i++)
//     {
//         string cur_ans="";
//         int mid=0;
//         for (int j=0;j<size2;j++)
//         {
//             mid=(num1[i]-'0')*(num2[j]-'0')+mid;
//             cur_ans=char(mid%10+'0')+cur_ans;
//             mid=mid/10;
//         }
//         if (mid)cur_ans=char(mid+'0')+cur_ans;
//         for (int j=0;j<i;j++)cur_ans=cur_ans+'0';
//         ans=add_num(ans,cur_ans);
//     }
//     ans=del_zreo(ans);
//     return ans;
// }
//
//
// int main()
// {
//     string a,b;
//     cin>>a>>b;
//     if (a[0]=='-')
//     {
//         string x(a.begin()+1,a.end());
//         a=x;
//     }
//     if (b[0]=='-')
//     {
//         string x(b.begin()+1,b.end());
//         b=x;
//     }
//     string ans= sub_num(mul_num(a,a),mul_num(b,b));
//     int size1=a.size(),size2=b.size();
//     if (size1<size2||(size1==size2&&a<b))ans='-'+ans;
//     cout<<ans<<endl;
//     return 0;
// }
//
//












