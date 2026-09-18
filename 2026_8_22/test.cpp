#include <iostream>
using namespace std;


int main() {
    string str;
    int num;
    cin>>str>>num;
    int times=0,ans=-1,ptrr=1;
    for(int i=1;i<str.size()-1;i++)
    {
        if(str[i]==',')
        {
            string temp(str.begin()+ptrr,str.begin()+i);
            // cout<<temp<<" ";
            if(stoi(temp)==num)
            {
                ans=times;
                break;
            }
            times++;
            ptrr=i+1;
        }
    }
    cout<<ans;
    return 0;
}
// 64 位输出请用 printf("%lld")