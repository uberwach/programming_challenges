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

int main() {
  int n, m; cin >> n >> m;

  bool no_solution = true;
  vector<vector<int> > grid = vector< vector<int> >(n, vector<int>(m));

  long total_count = 0;
  vector<int> row_count = vector<int>(n, 0);
  vector<int> col_count = vector<int>(m, 0);

  for (int i = 0;i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch; cin >> ch;
      if (ch == '*') {
        grid[i][j] = 1;
        total_count++;
        row_count[i]++;
        col_count[j]++;
      }
      else {
        grid[i][j] = 0;
      }
    }
  }

  for (int i = 0; (i < n) && no_solution; i++)
    for (int j = 0; j < m; j++)
      if (row_count[i] + col_count[j] - grid[i][j] == total_count) {
        debug("row count", row_count[i], "col count", col_count[j],
              "grid", grid[i][j], "total", total_count);
        cout << "YES\n";
        cout << (i+1) << " " << (j+1) << "\n";
        no_solution = false;
        break;
      }



  if (no_solution)
    cout << "NO\n";

}

