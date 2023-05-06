#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
using namespace std;

// Time Complexity: O(3^n)
// Space Complexity: O(3^n)
int recc(int l, int p, int q, int r) {

    if(l == 0) {
        return 0;
    }
    if(l < 0) {
        return INT_MIN;
    }

    int x1 = recc(l-p, p, q, r);
    int x2 = recc(l-q, p, q, r);
    int x3 = recc(l-r, p, q, r);

    return max(max(x1, x2), x3) + 1;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int topDown(int l, int p, int q, int r, unordered_map<int, int> dp = unordered_map<int, int>()) {
    if(l == 0) {
        return dp[0] = 0;
    }
    if(l < 0) {
        return INT_MIN;
    }
    if(dp.find(l) != dp.end()) {
        return dp[l];
    }

    int x1 = recc(l-p, p, q, r);
    int x2 = recc(l-q, p, q, r);
    int x3 = recc(l-r, p, q, r);

    return dp[l] = max(max(x1, x2), x3) + 1;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int bottomUp(int l, int p, int q, int r) {
    int* dp = new int[l+1];
    dp[0] = 0;

    for(int i=1; i<=l; i++) {
        int x1 = i-p < 0 ? INT_MIN : dp[i-p];
        int x2 = i-q < 0 ? INT_MIN : dp[i-q];
        int x3 = i-r < 0 ? INT_MIN : dp[i-r];
        dp[i] = max(max(x1, x2), x3) + 1;
    }

    return dp[l];
}


int main(int argc, char** argv) {
    int l = 11, p = 2, q = 3, r = 5;
    if(argc >= 2) {
        try{
            l = stoi(argv[1]);
            p = stoi(argv[2]);
            q = stoi(argv[3]);
            r = stoi(argv[4]);
        } catch(...) {
            l = 11;
            p = 2;
            q = 3;
            r = 5;
        }
    }
    cout<<"***************\nProblem: Maximize the number of segments of length p, q and r\nGiven a rod of length L, the task is to cut the rod into p, q, r length segments in such a way that\nthe total number of segments is maximized. The segments can only be of length p, q, and r.\nPass variables to make if you want to change the value of l, p, q, r.\neg. make 2 l=7 p=2 q=5 r=5\n***************"<<endl;
    cout<<"Solution with Reccursive Approach for l="<<l<<" p="<<p<<" q="<<q<<" r="<<r<<" is: "<<max(recc(l, p, q, r), 0)<<endl;
    cout<<"Solution with Top Down Approach for l="<<l<<" p="<<p<<" q="<<q<<" r="<<r<<" is: "<<max(topDown(l, p, q, r), 0)<<endl;
    cout<<"Solution with Bottom Up Approach for l="<<l<<" p="<<p<<" q="<<q<<" r="<<r<<" is: "<<max(bottomUp(l, p, q, r), 0)<<endl;
    return 0;
}