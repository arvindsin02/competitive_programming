#include<iostream>
using namespace std;

int palindromeLength(string& s, int i, int j) {
    int l = i-1;
    int r = j+1;
    int count = 1;
    if(i != j)
        count = 2;
    while(l >=0 && r < s.size() && s[l] == s[r]) {
        l--;r++;
        count += 2;
    }
    return count;
}

int longestPalindrome(string s) {
    int N = s.size();
    if(N == 0)
        return 0;
    int ans = 1;
    for(int i=0;i<N-1;i++) {
        ans = max(ans,palindromeLength(s, i,i));
        if(s[i] == s[i+1])
        ans = max(ans,palindromeLength(s, i,i+1));
    }
    return ans;
}

int main() {
    string s = "abba";
    cout<<longestPalindrome(s);
    return 0;
}
