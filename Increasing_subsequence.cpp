//dp application for finding longest increasing subsequence 
#include<iostream>
using namespace std;

int findans(int * arr,int n){
    
    if(n == 0){
        return 0;
    }

    int * dp = new int [n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2 ; i <= n ; ++i){

        dp[i] = 1;

        for(int j = i-2 ; j >= 0 ; --j){

            if(arr[j] < arr[i-1]){
                dp[i] = max( 1 + dp[j+1] , dp[i]);
            }

        }

    }

    int ans = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        ans = max(ans,dp[i]);
    }
    cout<<endl;
    for(int i = 0 ; i <= n ; ++i){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    delete []dp;
    return ans;

}

int main(){
    int n;
    cout<<"Enter number of elements in array:-  ";
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i < n; i++){
        cin>>arr[i];
    }
    int ans=findans(arr,n);
    cout<<ans;
    delete [] arr;
    return 0;
}