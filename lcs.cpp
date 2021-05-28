#include<iostream>
using namespace std;

int lcs_helper(char * s1 , char * s2 , int m , int n , char ** dp){

    if(s1[0] == '\0' || s2[0] == '\0'){
        return 0;
    }

    if(dp[m][n] > -1){
        return dp[m][n];
    }

    if(s1[0] == s2[0]){
        dp[m][n] =  1 + lcs_helper(s1+1 , s2+1 , m-1 , n-1 , dp);
    }
    else{

        dp[m][n] = max(lcs_helper( s1+1 ,s2 ,m-1 ,n ,dp ), lcs_helper( s1, s2+1, m, n-1, dp ));

    }

    return dp[m][n];
 
}

int lcs(char * s1 , char * s2 , int m , int n){

    char ** dp = new char * [m +1];

    for(int i = 0 ; i < m + 1 ; ++i){

        dp[i] = new char [n + 1];

        for(int j = 0 ; j < n + 1 ; ++j){
            dp[i][j] = -1;
        }

    }
    


    int ans = lcs_helper(s1, s2, m, n , dp);

    for(int i = 0 ; i < m+1 ; ++i){
        delete []dp[i];
    }
    delete []dp;
    
    return ans;
}

int lcs2(char * s1 , char * s2 , int m , int n){

    int ** dp = new int * [m+1];
    for(int i = 0 ; i < m +1 ; ++i){

        dp[i] = new int [n+1];

    }

    //BASE CASE 1
    for(int i = 0 ; i < m+1 ; ++i){
        dp[i][0] = 0;
    }

    //BASE CASE 2
    for(int i = 0 ; i < n+1 ; ++i){
        dp[0][i] = 0;
    }

    for(int i = 1 ; i < m+1 ; ++i){

        for(int j = 1; j < n+1 ; ++j){

            if(s1[m - i] == s2[n - j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{

                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);

            }

        }

    }

    int ans = dp[m][n];

    for(int i = 0 ; i < m+1 ; ++i){
        delete []dp[i];
    }

    delete []dp;

    return ans;


}

int main(){

    int n,m;
    cout<<"Enter length of 1st string: ";
    cin>>m;
    char * s1 = new char [m+1];
    cout<<"Enter 1st string: ";
    for(int i = 0 ; i < m ; ++i){
        cin>>s1[i];
    }
    s1[m] = '\0';

    cout<<"Enter length of 2nd string: ";
    cin>>n;
    char * s2 = new char [n+1];
    for(int i = 0 ; i < n ; ++i){
        cin>>s2[i];
    }
    s2[n] = '\0';

    cout<<"Length of maximum common subsequence: "<<lcs(s1 , s2 , m , n)<<" "<<lcs2(s1 , s2 , m , n);

    return 0;
}