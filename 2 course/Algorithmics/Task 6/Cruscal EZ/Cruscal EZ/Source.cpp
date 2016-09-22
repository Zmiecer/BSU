#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	int n;
	fin >> n;

	vector<pair<int, pair<int, int>>> g;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		fin >> x >> y;
		for (int j = 0; j < (int)vec.size(); j++)
		{
			g.push_back(make_pair(abs(x - vec[j].first) + abs(y - vec[j].second), make_pair(j, vec.size())));
		}

		vec.push_back(make_pair(x, y));
	}
	fin.close();
	
	
	sort(g.begin(), g.end());

	vector<int> tree_id(n);
	for (int i = 0; i < n; i++)
		tree_id[i] = i;

	vector<pair<int, int>> res;
	int cost = 0;
	int m = n * (n - 1) / 2;
	for (int i = 0; i < m; i++)
	{
		int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
		if (tree_id[a] != tree_id[b])
		{
			cost += l;
			res.push_back(make_pair(a, b));
			int old_id = tree_id[b], new_id = tree_id[a];
			for (int j = 0; j < n; j++)
				if (tree_id[j] == old_id)
					tree_id[j] = new_id;
		}
	}

	ofstream fout("output.txt");
	fout << cost << endl;
	fout.close();
}