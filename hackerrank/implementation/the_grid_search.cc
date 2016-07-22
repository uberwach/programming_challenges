// https://www.hackerrank.com/challenges/the-grid-search
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool match(int x, int y, vector<string>& grid, vector<string>& P) {
    for (int i = 0; i < P.size(); i++)
        for (int j = 0; j < P[0].size(); j++)
            if (grid[x+i][y+j] != P[i][j])
                return false;

    return true;
}
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }

        bool result = false;
        for (int i = 0; i <= R-r && !result; i++)
            for (int j = 0; j <= C-c; j++)
                result = result || match(i, j, G, P);

        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
