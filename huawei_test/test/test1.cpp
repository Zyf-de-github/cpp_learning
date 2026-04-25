#include <bits/stdc++.h>
using namespace std;


int main()
{
    for(int mk=0;mk<2;mk++)
    {
        string str;
        getline(cin,str);
        int n=stoi(str);
        vector<vector<pair<int,int>>> v(100,vector<pair<int,int>>(100,{0,0}));
        vector<vector<int>> recorder;
        set<pair<int,int>> s;
        for(int i=0;i<n;i++)
        {
            getline(cin,str);
            stringstream ss(str);
            string temp;
            int times=0,a,b,c;
            while(getline(ss,temp,','))
            {
                if(times==0){a=stoi(temp);times++;}
                else if(times==1){b=stoi(temp);times++;}
                else if(times==2){c=stoi(temp);times++;}
            }
            v[a][b]={1,c};
            s.insert({a,0});
            s.insert({b,0});
            recorder.push_back({a,b,c});
        }

        //判断有环？
        int flag_change=1;
        while(flag_change)
        {        
            flag_change=0;
            for(auto i=s.begin();i!=s.end();i++)
            {
                if(i->second)continue;
                int zero=0;
                for(auto j=s.begin();j!=s.end();j++)
                {
                    if(v[i->first][j->first].first!=0&&j->second==0){zero=1;break;};
                }
                if(zero==0)
                {
                    s.insert({i->first,1});
                    s.erase(i);
                    i=s.begin();
                    flag_change=1;
                }
            }
        }
        int xxx=0;
        for(auto i=s.begin();i!=s.end();i++)
        {
            if(i->second==0){xxx=1;break;}
        }
        if(xxx)
        {
            cout<<"flse"<<endl;
            continue;
        }

        for(int i=0;i<n;i++)
        {
            int a=recorder[i][0];
            int b=recorder[i][1];
            int c=recorder[i][2];
            int temp=c;
            for(int j=0;j<100;j++)
            {
                if(v[j][b].first)
                {
                    temp=max(temp,v[j][b].second);
                }
            }
            cout<<a<<","<<b<<","<<temp<<endl;
        }
    }
    return 0;
}


// 3
// 1,2,23
// 2,3,34
// 4,2,25
// 3
// 1,2,23
// 2,3,34
// 3,1,12