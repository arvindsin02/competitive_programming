#include<iostream>
using namespace std;

void TOH(string source, string dest, string aux, int n) {
    if(n == 0) {
        return;
    }
    TOH(source, aux, dest, n-1);
    cout<<source<<"-->"<<dest<<endl;
    TOH(aux,dest, source, n-1);
}

int main() {
    string source = "source";
    string dest = "dest";
    string aux = "aux";
    cout<<"Enter the number of disks:"<<endl;
    int n;
    cin>>n;
    TOH(source, dest, aux, n);
    return 0;
}
