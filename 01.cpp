#include <iostream>
#include <unordered_map>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
int recc(int n) {
    if(n <= 1) return n;

    int x = recc(n-1);
    int y = recc(n-2);

    return x+y;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int topDown(int n, unordered_map<int, int> dp = unordered_map<int, int>()) {
    if(n <= 1) {
        return dp[n] = n;
    }

    if(dp.find(n) != dp.end()) return dp[n];

    int x = topDown(n-1, dp);
    int y = topDown(n-2, dp);

    return dp[n] = x+y;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int bottomUp(int n) {
    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int memEffBottomUp(int n) {
    int x = 0;
    int y = 1;
    int z = x+y;
    for(int i=2; i<=n; i++) {
        z = x+y;
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
    cout<<"***************\nProblem: Fibonaci Number\nPass variable to make if you want to change the value of n.\neg. make 1 n=12\n***************"<<endl;
    cout<<"Solution with Reccursive Approach for n="<<n<<" is: "<<recc(n)<<endl;
    cout<<"Solution with Top Down Approach for n="<<n<<" is: "<<topDown(n)<<endl;
    cout<<"Solution with Bottom Up Approach for n="<<n<<" is: "<<bottomUp(n)<<endl;
    cout<<"Solution with Memory Efficient Bottom Up Approach for n="<<n<<" is: "<<memEffBottomUp(n)<<endl;
    return 0;
}