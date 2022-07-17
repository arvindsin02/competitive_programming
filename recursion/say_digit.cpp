#include<iostream>

using namespace std;

void sayDigit(int number, string arr[]) {
    if(number == 0)
     return;
      
    int digit = number%10;
    number = number/10;
    sayDigit(number, arr);
    cout<<arr[digit]<<" ";
    
}

int main() {
    cout<<"Enter the number"<<endl;
    int number;
    cin>>number;
    
    string a[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    
    sayDigit(number, a);
    return 0;
}
