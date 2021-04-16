//dp application for finding longest increasing subsequence 
#include<iostream>
using namespace std;

int findans(int *copyarr,int n){
    int *dp=new int [n];
    dp[0]=1;
    for(int i=1 ; i < n ; i++){
        dp[i]=1;
        for(int j=i-1 ; j >= 0 ; j--){
            if(copyarr[i]>=copyarr[j]){
                if(dp[j]>=dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    
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