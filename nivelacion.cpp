#include <iostream>
#include <string>

using namespace std;

string input, rev;
const int MAXN = 4000;
int dp[MAXN][MAXN];


int edit_distance(int i, int j) {
    if (i < 0) {
        return j+1;
    } 
    if (j < 0) {
        return i+1;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (input[i] == rev[j]) {
        return dp[i][j] = edit_distance(i-1, j-1);
    }

    return dp[i][j] = min(edit_distance(i-1, j)+1, edit_distance(i, j-1)+1);
}

int nivelacion(string A) {
    
    input = A;

    rev = string{input.rbegin(), input.rend()};

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input.size(); j++) {
            dp[i][j] = -1;
        }
    }

    int ans = edit_distance(input.size()-1, input.size()-1);

    return ans/2;
}