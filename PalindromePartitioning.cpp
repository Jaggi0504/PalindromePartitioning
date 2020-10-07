#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j) {
	while(i < j) {
		if(s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int numberOfPartitions_Mem(string s, int i, int j) {
	
	int dp[100][100];
	memset(dp, -1, sizeof(dp));
	
	if(i >= j) {
		return 0;
	}
	if(isPalindrome(s, i, j) == true) {
		return 0;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	int min = INT_MAX;
	for(int k=i;k<j;k++) {
		int temp = numberOfPartitions_Mem(s, i, k) + numberOfPartitions_Mem(s, k+1, j) + 1;
		if(temp < min) {
			min = temp;
			dp[i][j] = min;
		}
	}
	return min;
}

int numberOfPartitions(string s, int i, int j) {
	if(i >= j) {
		return 0;
	} 
	if(isPalindrome(s, i, j) == true) {
		return 0;
	}
	int  min = INT_MAX;
	for(int k=i;k<j;k++) {
		int temp = numberOfPartitions(s, i, k) + numberOfPartitions(s, k+1, j) + 1;
		if(temp < min) {
			min = temp;
		}
	}
	return min;
}

int main() {
	string s;
	cout<<"Enter the string: ";
	cin>>s;
	int ans = numberOfPartitions_Mem(s, 0, s.length() - 1);
	cout<<"Minimum number of partitions required to make the given string a Palindrome using Memoization is: "<<ans<<endl;
	int ans1 = numberOfPartitions(s, 0, s.length() - 1);
	cout<<"Minimum number of partitions required to make the given string a Palindrome using Recursion is: "<<ans1<<endl;
	return 0;
}
