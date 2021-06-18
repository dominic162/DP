class Basic{
    public:
        int * make_arr(int n){
            int * arr = new int [n];
            cout<<"Enter elements of array: ";
            for(int i = 0 ; i < n ; ++i){
                cin>>arr[i];
            }
            return arr;
        }

        void disp_arr(int * arr , int n ){

            cout<<"Array elements: ";
            for(int i = 0 ; i < n ; ++i){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            
        }

};