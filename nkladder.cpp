/*
    NK Ladder problem
*/

#include<iostream>
using namespace std;


class Solution{

    public:

        int find_ans( int n , int k){

            int * dp = new int[n+1];

            dp[0] = 1;
            int size = 1,cans = 1 ;

        // Optimization using sliding window technique
            for(int i = 1 ; i <= n ; ++i){

                if(size > k){   
                    cans -= dp[i - k - 1];
                    size--;
                }

                dp[i] = cans;

                size++;
                cans += dp[i];

            }

            int ans = dp[n];
            delete []dp;
            return ans;
        }

};

int main(){

    int n,k;
    cout<<"Enter no of elements and k ";
    cin>>n>>k;
    Solution sl;


    int ans = sl.find_ans( n , k);
    cout<<"No of ways: "<<ans;


    return 0;

}
