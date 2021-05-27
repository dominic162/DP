/*
    Max sub sum;
*/

#include<iostream>
using namespace std;

int get_ans(int * arr , int n){

    if( n == 0 ){
        return 0;
    }

    int * dp = new int [n];
    
    for(int i = 0 ; i < n ; ++i){

        dp[i] = arr[i];
        int csum = arr[i];

        for(int j = i+1 ; j < n ; ++j){

            csum += arr[j];

            dp[i] = max(csum , dp[i]);

        }

    }

    int ans = dp[0];

    for(int i = 1 ; i < n ; ++i){
        ans = max(ans , dp[i]);
    }

    delete [] dp;
    return ans;

}

int main(){

    int n;
    cin>>n;

    int * arr = new int [n];

    for(int i = 0 ; i < n ; ++i){
        cin>>arr[i];
    }

    cout<<"Max sub sum: "<<get_ans(arr , n);
    
    delete []arr;

    return 0;
}