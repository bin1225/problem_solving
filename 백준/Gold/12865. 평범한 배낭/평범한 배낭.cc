#include<iostream>
#include<vector>

using namespace std;


int main(){

 	int n, k, w, v;
	cin>>n>>k;
	int dp[n+1][k+1];


	for(int j=0; j<k+1; j++){
		dp[0][j] = 0;
	}
	
	for(int i=1; i<=n; i++){
		cin>>w>>v;
		
		for(int j=0; j<k+1; j++){
			if(w>j){
				 dp[i][j] = dp[i-1][j];
				 continue;
			}
			
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
			
		}
	}
	int answer = 0;
	for(int i=0; i<=k; i++){
		if(answer<dp[n][i]){
			answer = dp[n][i];
		}
	}
	cout<<answer;
    return 0;
}
	