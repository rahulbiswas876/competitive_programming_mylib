#include<bits/stdc++.h>
#include "dsu.h"
using namespace std;

int main()
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	cout << "Enter Set size: ";
	int n; cin >> n;

	cout << "\nEnter set elements:\n";


	disjoint_set_union dsu(n);

	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		dsu.make_set(a);
	}

	cout << "initially each element is in separate set\n";
	cout << dsu << "\n";


	int a, b;

	while(1)
	{
		cout << "Enter two elements to combine or -1 -1 to exit\n";
		cin >> a >> b;
		if(a == -1 || b == -1)
			break;

		if(a > dsu.size() || b > dsu.size())
		{
			cout << "Error: elements not present\n";
			continue;
		}

		cout << "after combining set containing " << a << " and " << 2 << "\n";
		dsu.union_sets(a, b);
		cout << dsu << "\n";
	}

	// cout << "after combining set containing 1 and 2\n";
	// dsu.union_sets(1, 2);
	// cout << dsu << "\n";

	// cout << "after combining set containing 3 and 4\n";
	// dsu.union_sets(3, 4);
	// cout << dsu << "\n";

	// cout << "after combining set containing 2 and 4\n";
	// dsu.union_sets(2, 4);
	// cout << dsu;
}