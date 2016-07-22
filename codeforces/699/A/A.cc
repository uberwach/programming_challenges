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
  int n; cin >> n;
  string str; cin >> str;

  long last_num; cin >> last_num;
  long earliest_collision = -1;

  for (int i = 1; i < n; i++) {
    long current_num; cin >> current_num;
    if ( (str[i-1] != str[i]) && str[i] == 'L') {
      if (earliest_collision == -1)
        earliest_collision = (current_num - last_num) / 2;
      else
        earliest_collision = min(earliest_collision, (current_num - last_num) / 2);
    }

    last_num = current_num;
  }

  cout << earliest_collision << "\n";
}

