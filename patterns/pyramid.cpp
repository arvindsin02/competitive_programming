#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of rows:"<<endl;
    cin>>n;
    int m = 2*n-1;
    
    for(int i=1;i<=n;i++) {
        int l = (m-(2*i-1))/2;
        for(int j=1;j<=m;j++) {
            if(j <= l) {
                cout<<"-";
            } else if(j > l+(2*i-1)) {
                cout<<"-";
            } else {
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}




