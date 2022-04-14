
#include<bits/stdc++.h>
using namespace std;




class Solution
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int count=0,n=nums.size();
	    vector <pair <int , int > > v;
	    for (int i=0;i<n;i++)
	    {
	        v.push_back(make_pair(nums[i],i));
	    }
	    sort(v.begin(),v.end());
	    for(int i=0;i<n;)
	    {
	        if(i==v[i].second) i++;
	        else {
	            swap(v[i],v[v[i].second]);
	            count++;
	            if(i>0)
	                i--;
	        }

	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
