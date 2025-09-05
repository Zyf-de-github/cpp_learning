#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>

using namespace std;

class ParkingSystem {
private:
    int cb = 0;
    int cm = 0;
    int cs = 0;
public:
    ParkingSystem(int big, int medium, int small) {
        cb = big;
        cm = medium;
        cs = small;
    }

    bool addCar(int carType) {
        if (carType == 1)
        {
            if (cb == 0)return false;
            cb--;
            return true;
        }
        if (carType == 2)
        {
            if (cm == 0)return false;
            cm--;
            return true;
        }
        if (carType == 3)
        {
            if (cs == 0)return false;
            cs--;
            return true;
        }
        return false;
    }
};
class Twitter {
    vector<vector<int>> tweet;
    unordered_map<int, unordered_set<int>> follower;
public:
    Twitter() {
        tweet.clear();
        follower.clear();
    }

    void postTweet(int userId, int tweetId) {
        tweet.push_back({ userId,tweetId });
        follower[userId].insert(userId);
    }

    vector<int> getNewsFeed(int userId) {
        int i = 0;
        int ptr = tweet.size() - 1;
        vector<int> ans;
        while (i < 10 && ptr >= 0)
        {
            if (follower[userId].count(tweet[ptr][0]))
            {
                ans.push_back(tweet[ptr][1]);
                i++;
            }
            ptr--;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};
class OrderedStream {
private:
    map<int, string> x;
    int ptr;
public:
    OrderedStream(int n) {
        x.clear();
        ptr = 1;
    }

    vector<string> insert(int idKey, string value) {
        x[idKey] = value;
        vector<string> temp;
        while (x.count(ptr))
        {
            temp.push_back(x[ptr]);
            ptr++;
        }
        return temp;
    }
};
class MyLinkedList {
    deque<int> dq;
public:
    MyLinkedList() {

    }

    int get(int index) {
        if (index >= dq.size())return -1;
        return dq.at(index);
    }

    void addAtHead(int val) {
        dq.push_front(val);
    }

    void addAtTail(int val) {
        dq.push_back(val);
    }

    void addAtIndex(int index, int val) {
        if (index < dq.size()) dq.insert(dq.begin() + index, val);
        else if (index == dq.size()) addAtTail(val);
    }

    void deleteAtIndex(int index) {
        if (index < dq.size()) dq.erase(dq.begin() + index);
    }
};
class Allocator {
    vector<int> v;//{数字，是否使用}
    int total;
public:
    Allocator(int n)
    {
        v.assign(n, 0);
        total = n;
    }

    int allocate(int size, int mID)
    {
        int sum = 0;
        int first = -1;
        for (int i = 0; i < total; i++)
        {
            if (v[i] != 0)
            {
                sum = 0;
            }
            else if (v[i] == 0 && sum == 0)
            {
                first = i;
                sum++;
            }
            else sum++;

            if (sum == size)
            {
                for (int j = first; j < first + size; j++)
                {
                    v[j] = mID;
                }
                return first;
            }
        }
        return -1;
    }


    int freeMemory(int mID)
    {
        int sum = 0;
        for (int i = 0; i < total; i++)
        {
            if (v[i] == mID)
            {
                sum++;
                v[i] = 0;
            }
        }
        return sum;
    }
};
