
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool comp(const vector<int> &a , const vector<int> &b){
    return a[1] > b[1];
}

int maxTowerHeight(vector<vector<int>> &arr, int n)
{
    //  Write your code here.
    if(n == 0){
        return 0;
    }
    sort(arr.begin() , arr.end(), &comp);
    for(int i = 0 ; i < n ; ++i){
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    }


    int * height = new int [n];
    int * coins = new int [n];



    height[0] = arr[0][0];
    coins[0] = 1;

    for(int i = 1 ; i < n ; ++i){


        height[i] = arr[i][0];
        coins[i] = 1;

        for(int j = i -1 ; j >= 0 ; --j){

            if(arr[j][0] >= arr[i][0] && arr[j][1] >= arr[i][1]){
                int ch = height[j] + arr[i][0];
                if(height[i] < ch){

                    height[i] = ch;
                    coins[i] = coins[j] + 1;

                }

                else{

                    if(height[i] == ch && coins[i] > (1 + coins[j])){
                        coins[i] = 1 + coins[j];
                    }


                }

            }

        }

    }

    int ansh = 0,ansc = 0;
    cout<<endl;
    for(int i = 0 ; i < n ; ++i){
        cout<<height[i]<<" "<<coins[i]<<endl;

        if(height[i] > ansh){
            ansh = height[i];
            ansc = coins[i];
        }
        else{
            if(height[i] == ansh && coins[i] < ansc){
                ansc = coins[i];
            }
        }

    }

    cout<<endl;


    delete []height;
    delete []coins;
    return ansc;
    
}

int main(){

    int t;
    cin>>t;

    for( ; t >= 0 ; --t){

        int n;
        cin>>n;
        vector< vector< int > > vr;

        for(int i = 0 ; i < n ; ++i){
            vector<int> v1(2);
            cin>>v1[0]>>v1[1];
            vr.push_back(v1);
        }
        cout<<endl;
        cout<<(maxTowerHeight(vr , n))<<endl;

    }

    return 0;
}