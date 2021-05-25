/*
    Alpha code;
*/


#include<iostream>
#include<string>

using namespace std;

int get_ans(string s){
	

	if(s.size() == 1){
		return 1;
	}

	int * dp = new int [ s.size() + 1 ];
	dp[0] = 1;
	dp[1] = 1;

	for(int i = 2 ; i <= s.size() ; ++i){
		dp[i] = 0;
		if(s[i-1] > '0'){
			dp[i] = dp[i-1];
		}
		
		if( s[i-2] == '1' ||( s[i-2] == '2' && s[i-1] <'7' && s[i-1] > '0'  ) ){
			dp[i] += dp[i-2];
		}

	} 
	int res = dp[s.size()];
	delete []dp;
	return res;

}

int main(){


	for( ; ; ){

		string s;
		cin>>s;

		if(s == "0"){
			break;
		}
		cout<<get_ans(s)<<endl;

	}


	return 0;
}





