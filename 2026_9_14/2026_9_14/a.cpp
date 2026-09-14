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

int main()
{
	Solution s;
	//vector<int> v=s.findFluctuations({ 120, 150, 110, 180, 130, 160, 140, 170 }, 3);
	cout<<s.canEqualDistribution({ 5, 4, 1, 3, 2, 3, 2 }, 4);
	return 0;
}