#include <bits/stdc++.h>
using namespace std;

/*

Contest : Loy Krathong Contest 2024
Organize : JuniorDev
Problem : F - Collect

Concecpt : Subset Sum (DP)

*/

int n;
vector<int> v;

int solve(){
	int total = accumulate(v.begin(), v.end(), 0);
	int target = total / 2;

	vector<bool> dp(target+1, false);
	dp[0] = true;

	for(auto num : v){
		for( int j = target ; j >= num ; j-- ){
			dp[j] = dp[j] || dp[j - num];
		}
	}

	int s1 = 0;
	for( int i = target ; i >= 0 ; i-- ){
		if(dp[i]){
			s1 = i;break;
		}
	}

	int s2 = total - s1;

	return abs(s1-s2);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> n;
	for(int i=0;i<n;i++){
		int x;cin >> x;
		v.push_back(x);
	}
	
	cout << solve() << "\n";
	
	return 0;
}