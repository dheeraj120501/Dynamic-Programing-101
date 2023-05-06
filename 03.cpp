#include <iostream>
#include <unordered_map>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
int recc(int n) {
    if(n <= 1) return 1;
    int c = 0;
    for(int i=0; i<n ;i++) {
        c += recc(i) * recc(n-i-1);
    }

    return c;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int topDown(int n, unordered_map<int, int> dp = unordered_map<int, int>()) {
    if(n <= 1) {
        return dp[n] = 1;
    }

    if(dp.find(n) != dp.end()) return dp[n];

    int c = 0;
    for(int i=0; i<n ;i++) {
        c += topDown(i, dp) * topDown(n-i-1, dp);
    }

    return dp[n] = c;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int bottomUp(int n) {
    int* dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = 0;
        for(int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}


int main(int argc, char** argv) {
    int n = 5;
    if(argc >= 2) {
        try{
            n = stoi(argv[1]);
        } catch(...) {
            n = 5;
        }
    }
    cout<<"***************\nProblem: Nth Catalan Number\nCatalan numbers are defined as a mathematical sequence that consists of positive integers,\nwhich can be used to find the number of possibilities of various combinations.\nThe nth term in the sequence denoted Cn, is found in the following formula: (2n)!/((n+1)!*n!)\nPass variable to make if you want to change the value of n.\neg. make 1 n=12\n***************"<<endl;
    cout<<"Solution with Reccursive Approach for n="<<n<<" is: "<<recc(n)<<endl;
    cout<<"Solution with Top Down Approach for n="<<n<<" is: "<<topDown(n)<<endl;
    cout<<"Solution with Bottom Up Approach for n="<<n<<" is: "<<bottomUp(n)<<endl;
    return 0;
}