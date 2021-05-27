#include<bits/stdc++.h>
using namespace std;

int get_ans(vector < vector < int > > &vr ,int i , int j , int n , int m , int ** dp){

    if( i >= n || j >=m ){
        return INT_MAX;
    }

    if(i == n-1 && j == m-1){
        return vr[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    dp[i][j] =  vr[i][j] + min(get_ans(vr , i+1, j ,n ,m , dp) ,min( get_ans(vr, i , j+1, n , m , dp) , get_ans(vr , i+1 , j+1 , n , m , dp)));
    return dp[i][j];
}

int get_ans2(vector < vector < int > > &vr , int n , int m ){

    int ** dp = new int *[n];
    for(int i = 0 ; i < n ; ++i){
        dp[i] = new int [m];
    }

    // BASE case 1
    dp[n-1][m-1] = vr[n-1][m-1];
    
    // BASE case 2 last column elements has one option only
    for(int i = n-2 ; i >= 0 ; --i){
        dp[i][m-1] = dp[i+1][m-1] + vr[i][m-1];
    }

    // BASE case 3 last row elements has one option only
    for(int i = m-2 ; i >= 0 ; --i){
        dp[n-1][i] = dp[n-1][i+1] + vr[n-1][i];
    }

    for(int i = n-2 ; i >= 0 ; --i){

        for(int j = m-2 ; j >= 0 ; --j){

            dp[i][j] = vr[i][j] + min( dp[i][j+1] , min( dp[i+1][j] , dp[i+1][j+1] ) );

        }

    }

    int ans = dp[0][0];

    for(int i = 0 ; i < n ; ++i){
        delete [] dp[i];
    }

    delete []dp;

    return ans;


}

int main(){

    int n,m;
    cin>>n>>m;

    vector< vector < int > > vr;
    for(int i = 0 ; i < n ; ++i){

        vector< int > v1(m);

        for(int j = 0 ; j < m ; ++j){
            cin>>v1[j];
        }

        vr.push_back(v1);

    }
    int ** dp = new int *[n];
    for(int i = 0 ; i < n ; ++i){
        dp[i] = new int [m];
        for(int j = 0 ; j < m ; ++j){
            dp[i][j] = -1;
        }
    }
    cout<<get_ans(vr , 0 , 0 , n , m , dp)<<" "<<get_ans2(vr , n , m);


    return 0;
}