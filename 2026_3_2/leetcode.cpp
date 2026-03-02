#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if (nums[mid]>nums.back())left=mid+1;
            else right=mid;
        }
        if (target<nums[right])return -1;
        else
        {
            if (target>=nums[right]&&target<=nums.back())
            {
                return dev_search(nums,target,right,nums.size()-1);
            }
            else
            {
                return dev_search(nums,target,0,(right-1)<0?0:right-1);
            }
        }
    }
    int dev_search(vector<int>& nums, int target,int left,int right)
    {
        while (left<right)
        {
            int mid=(left+right)/2;
            if (nums[mid]<target)left=mid+1;
            else if (nums[mid]>target)right=mid;
            else if (nums[mid]==target)return mid;
        }
        if (nums[left]==target)return left;
        return -1;
    }



    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return a>b;
        });
        return nums[k-1];
    }


};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::srand(std::time(nullptr));
        fastSort(nums,0,nums.size()-1);
        return nums;
    }

    void fastSort(vector<int>& nums,int left,int right)
    {
        if(right-left<=0)return;
        int randomIndex = left + std::rand() % (right - left + 1);
        int pivot = nums[randomIndex];
        swap(nums[left],nums[randomIndex]);
        int lptr=left,rptr=right,key=1;
        while(lptr!=rptr)
        {
            if(key)
            {
                if(nums[rptr]<pivot)
                {
                    swap(nums[lptr],nums[rptr]);
                    lptr++;
                    key=0;
                }
                else rptr--;
            }
            else
            {
                if(nums[lptr]>pivot)
                {
                    swap(nums[lptr],nums[rptr]);
                    rptr--;
                    key=1;
                }
                else lptr++;
            }
        }
        fastSort(nums,left,lptr-1);
        fastSort(nums,lptr+1,right);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,2,2,2,2,2,2,2,2};
    s.sortArray(nums);

    return 0;
}