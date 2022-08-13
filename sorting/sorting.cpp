#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& A, int start1, int end1, int start2, int end2) {
    vector<int> B;
    int i = start1;
    int j = start2;
    int k = 0;
    while(i <= end1 && j <= end2) {
        if(A[i] <= A[j]) {
            B.push_back(A[i]);
            i++;
        } else {
            B.push_back(A[j]);
            j++;
        }
    }
    
    while(i <= end1) {
        B.push_back(A[i]);
        i++;
    }
    
    while(j <= end2) {
        B.push_back(A[j]);
        j++;
    }
    
    for(int i=0,j=start1;i<B.size() && j<=end2;i++,j++) {
        A[j] = B[i];
    }
    
    return;
}

void divide(vector<int>& A, int start, int end) {
    if(start == end)
        return;
    int mid = (start+end)/2;
    divide(A,start,mid);
    divide(A,mid+1,end);
    merge(A,start, mid, mid+1, end);
}

void mergeSort(vector<int>& A) {
    divide(A,0,A.size()-1);
}

int  partition(vector<int>&A, int start, int end) {
    if(start >= end)
        return start; 
    int count = 0;
    for(int i=start+1;i<=end;i++) {
        if(A[i] < A[start])
            count++;
    }
    int p = start+count;
    swap(A[start],A[p]);
    int i=start;
    int j = end;
    while(i < p &&  j > p) {
        while(A[i] <= A[p]) {
            i++;
        }
        while(A[j] > A[p])
            j--;
        if(A[i] > A[p] && A[j] < A[p]) {
            swap(A[i++],A[--j]);
        }
    }
    
    return p;
}

void quickSort(vector<int>& A, int start, int end) {
    if(start >= end)
        return;
    int p = partition(A,start,end);
    quickSort(A, start,p-1);
    quickSort(A,p+1,end);
}

int main() {
    vector<int> A = {5,4,3,2,1,73};
    quickSort(A,0,A.size()-1);
    
    for(auto i:A) {
        cout<<i<<" ";
    }
    return 0;
}
