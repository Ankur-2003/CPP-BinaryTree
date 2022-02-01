// Number of Possible BST from Given n nodes.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of nodes:";
    cin>>n;

    // Dynamic Memotry allocation for DP.
    int *dp = new int(n+1);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        int sum = 0;
        for(int j=0;j<i;j++){
            sum += dp[j]*dp[i-j-1];
        }
        dp[i] = sum;
    }

    cout<<dp[n];
    return 0;
}