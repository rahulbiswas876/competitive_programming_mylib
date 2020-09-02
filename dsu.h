class disjoint_set_union
{
	private:
		int MX_SIZE = 100;
		std::vector<int> parent;


	public:
		disjoint_set_union(int mxsize);

		// make a set consisting of only element v
		void make_set(int v);

		// union set containing a and set containing b.
		void union_sets(int a, int b);

		// returns the representative(leader) of set containing a.
		int find_set(int a) const;

		int size() const;

		friend std::ostream &operator<<( std::ostream &output, const disjoint_set_union &dsu );


};

disjoint_set_union::disjoint_set_union(int mxsize)
{
	MX_SIZE = mxsize;
	parent = std::vector<int>(MX_SIZE + 1, -1);
}

void disjoint_set_union::make_set(int v)
{
	parent[v] = v;
}

void disjoint_set_union::union_sets(int a, int b)
{
	int rep_a = find_set(a);
	int rep_b = find_set(b);

	if(rep_a == rep_b)
		return;

	parent[rep_b] = rep_a;

}

int disjoint_set_union::find_set(int a) const
{
	if(parent[a] == a)
		return a;

	return find_set(parent[a]);
}

int disjoint_set_union::size() const
{
	return MX_SIZE;
}

std::ostream &operator<<( std::ostream &output, const disjoint_set_union &dsu ) 
{ 
    std::map<int, std::vector<int>> mp;
    
    for(int i=1; i<= dsu.size(); i++)
    {
    	if(dsu.parent[i] != -1)
    	{
    		int rep_i = dsu.find_set(i);
    		mp[rep_i].push_back(i);
    	}
    }

    for(auto e: mp)
    {
    	output << "{";
    	for(auto mem: e.second)
    	{
    		output << mem << " ";
    	}

    	output << "}";
    }

	return output;            
}
