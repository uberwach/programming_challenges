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
class UF    {
    int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
		
		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{ 
		id[i] = j; 
		sz[j] += sz[i]; 
	} else	{ 
		id[j] = i; 
		sz[i] += sz[j]; 
	}
        cnt--;
    }
	// Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};

int main() {
  int n; cin >> n;

  vector<int> a(n);
  UF uf(n);

  int designated_root = -1;
  int changes = 0;

  for (int i = 1; i <= n; i++) {
    cin >> a[i-1];

    if (a[i-1] == i) {
      debug("root detected at ", i);

      if (designated_root == -1) {
        designated_root = i;
        debug("designated root = ", i);
      }
      else {
        debug("set ", i, "to", designated_root);
        a[i-1] = designated_root;
        changes++;
      }
    }

  }
  // remove cycles
  for (int i = 1; i <= n; i++) {
    if ((i != a[i-1]) && uf.connected(i-1, a[i-1]-1)) {
      debug("Cyclic edge found", i, "->", a[i-1]);
      if (designated_root == -1) {
        debug("Set begin of cyclic edge to designated root", i);
        designated_root = i;
        a[i-1] = designated_root;
      } else {
        debug("Redirect subtree at", i, "to", designated_root);
        a[i-1] = designated_root;
      }
      changes++;
    }

    uf.merge(i-1, a[i-1]-1);
  }

  cout << changes << "\n";
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
}

