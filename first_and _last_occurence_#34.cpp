#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

int firstocc(vector <int> &a,int x){
    int n=a.size();
    int low=0;
    int high=n-1;
    int first=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==x){
            first=mid;
            high=mid-1;

        }
        else if(a[mid]<x)
        {
            low=mid+1;
        }
        else 
            high=mid-1;

    }return first;
}
int lastocc(vector <int> &a,int x){
    int n=a.size();
    int low=0;
    int high=n-1;
    int last=-1;
    while(low<=high){
       int mid=(low+high)/2;
        if(a[mid]==x){
            last=mid;
            low=mid+1;

        }
        else if(a[mid]<x)
        {
            low=mid+1;
        }
        else 
            high=mid-1;

    }return last;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstocc(nums,target);
        if(first==-1) return {-1,-1};
        int last=lastocc(nums,target);
        return {first,last};
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<int> result = obj.searchRange(nums, target);

    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}