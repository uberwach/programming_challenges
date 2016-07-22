// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

#define STATE_REST 0
#define STATE_CONTEST 1
#define STATE_GYM 2

int main() {
  int n; cin >> n;

  vector<vector<int> > dp(n+1, vector<int>(3, n+1));

  dp[0] = {0, 0, 0};

  for (int i = 1; i <= n; i++) {
    int a; cin >> a;

    if (a == 1) {
      dp[i][STATE_REST] = dp[i-1][STATE_CONTEST] + 1;
      dp[i][STATE_CONTEST] = min(dp[i-1][STATE_GYM], dp[i-1][STATE_REST]);
    }
    if (a == 0)
      dp[i][STATE_REST] = min(dp[i-1][STATE_CONTEST],
                              min(dp[i-1][STATE_GYM],
                                  dp[i-1][STATE_REST])) + 1;
    if (a == 2) {
      dp[i][STATE_REST] = dp[i-1][STATE_GYM] + 1;
      dp[i][STATE_GYM] = min(dp[i-1][STATE_CONTEST], dp[i-1][STATE_REST]);
    }

    if (a == 3) {
      dp[i][STATE_GYM] = min(dp[i-1][STATE_REST], dp[i-1][STATE_CONTEST]);
      dp[i][STATE_CONTEST] = min(dp[i-1][STATE_GYM], dp[i-1][STATE_REST]);
    }

  }

  cout << min(dp[n][STATE_REST], min(dp[n][STATE_CONTEST], dp[n][STATE_GYM])) << "\n";
}

