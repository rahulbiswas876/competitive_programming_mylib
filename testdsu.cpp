#include<bits/stdc++.h>
#include "dsu.h"
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;

	disjoint_set_union dsu(n);

	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		dsu.make_set(a);
	}

	cout << dsu << "\n";
	dsu.union_sets(1, 2);
	cout << dsu << "\n";

	dsu.union_sets(3, 4);
	cout << dsu << "\n";

	dsu.union_sets(2, 4);
	cout << dsu;
}