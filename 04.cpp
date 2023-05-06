#include <iostream>
#include <unordered_map>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
int recc(int n) {
    if(n <= 1) return 0;
    if(n == 2) return 1;

    return (n-1)*(recc(n-1)+recc(n-2));
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int topDown(int n, unordered_map<int, int> dp = unordered_map<int, int>()) {
    if(n <= 1) {
        return dp[n] = 0;
    }
    if(n == 2) {
        return dp[2] = 1;
    }

    if(dp.find(n) != dp.end()) return dp[n];

    return dp[n] = (n-1)*(topDown(n-1, dp)+topDown(n-2, dp));
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int bottomUp(int n) {
    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3; i<=n; i++) {
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int memEffBottomUp(int n) {
    if(n == 2) {
        return 1;
    }
    int x = 0;
    int y = 1;
    int z = 0;
    for(int i=3; i<=n; i++) {
        z = (i-1)*(x+y);
        x = y;
        y = z;
    }
    return z;
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
    cout<<"***************\nProblem: Count Derangements\nGiven a number n, find the total number of Derangements a set of n elements.\nA Derangement is a permutation of n element\nsuch that no element appears in its original position.\nPass variable to make if you want to change the value of n.\neg. make 1 n=12\n***************"<<endl;
    cout<<"Solution with Reccursive Approach for n="<<n<<" is: "<<recc(n)<<endl;
    cout<<"Solution with Top Down Approach for n="<<n<<" is: "<<topDown(n)<<endl;
    cout<<"Solution with Bottom Up Approach for n="<<n<<" is: "<<bottomUp(n)<<endl;
    cout<<"Solution with Memory Efficient Bottom Up Approach for n="<<n<<" is: "<<memEffBottomUp(n)<<endl;
    return 0;
}