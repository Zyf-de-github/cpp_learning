#include "test.h"
using namespace std;



class Solution20 {
public:
	int staffGroup(vector<int>& staff) {
		int num0 = 0, num1 = 0, ans = 0;
		for (auto it : staff)
		{
			if (it == 0)num0++;
			if (it == 1)num1++;
		}
		if (num0 <= num1)return num1;
		int temp = num0 - num1;
		return num1 + (temp % 3 ? temp / 3 + 1 : temp / 3);
	}
};
class Solution19 {
public:
	vector<int> findFluctuations(vector<int> memoryUsage, int k) {
		set<int>s;
		vector<int>ans;
		for (int i = 0; i < memoryUsage.size(); i++)
		{
			s.insert(memoryUsage[i]);
			if (i < k - 1)continue;
			ans.push_back(*s.rbegin() - *s.begin());
			s.erase(memoryUsage[i - k + 1]);
		}
		return ans;
	}
};
class Solution18 {
public:
	bool canEqualDistribution(vector<int> v, int k) {
		priority_queue<int> pq;
		int total = 0,num_max=0;
		sort(v.begin(), v.end(), [&](int a, int b) {return a > b; });
		for (auto it : v)total += it;
		if (total % k)return false;
		total /= k;
		for (int i = 0; i < k; i++)pq.push(0);
		for (auto it : v)
		{
			int temp = pq.top();
			pq.pop();
			temp -= it;
			if (-temp > total)return false;
			pq.push(temp);
		}
		while (!pq.empty())
		{
			int temp = pq.top();
			pq.pop();
			if (-temp != total)return false;
		}
		return true;
	}
};
class Solution17 {
public:
	int minimizeXor(int num1, int num2) {
		int num1_t = num1; int num2_t = num2;
		int cnt1 = 0, cnt2 = 0, ans = 0;
		while (num2_t)
		{
			if (num2_t & 1)cnt2++;
			num2_t >>= 1;
		}
		string num1_s;
		while (num1_t)
		{
			if (num1_t & 1)
			{
				num1_s = num1_s + '1';
				cnt1++;
			}
			else num1_s = num1_s + '0';
			num1_t >>= 1;
		}
		if (cnt1 == cnt2)return num1;

		int size = num1_s.size(), flag = 0;
		if (cnt1 > cnt2)flag = 1;
		int times = abs(cnt1 - cnt2),ptr = 0;
		while (times)
		{
			if	(ptr >= size ||
				(ptr < size && num1_s[ptr] == '1'&&flag==1)||
				(ptr < size && num1_s[ptr] == '0'&&flag==0))
			{
				ans += pow(2, ptr);
				times--;
			}
			ptr++;
		}
		int a = ans ^ num1;
		return a;
	}
};
class Solution {
public:
	int countTriplets(vector<int> arr) {
		if (arr.size() <= 1)return 0;
		vector<int> v;
		vector <tuple<int, int, int>>debug;
		v.emplace_back(0);
		int total = 0,ans=0;
		for (auto it : arr)
		{
			total = it ^ total;
			v.emplace_back(total);
		}
		//0 sum1 sum2
		for (int j = 1; j < v.size()-1; j++)
		{
			for (int i = 0; i < j; i++)
			{
				for (int k = j + 1; k < v.size(); k++)
				{
					if ((v[i] ^ v[j]) == (v[j] ^ v[k]))
					{
						ans++;
						debug.emplace_back(make_tuple(i,j,k ));
					}
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution s;
	//vector<int> v=s.findFluctuations({ 120, 150, 110, 180, 130, 160, 140, 170 }, 3);
	cout<<s.countTriplets({ 2,3,1,6,7 });
	return 0;
}