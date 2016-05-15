#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

vector<int> p(n);

int dsu_get(int v)
{
	return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
}

void dsu_unite(int a, int b)
{
	a = dsu_get(a);
	b = dsu_get(b);
	if (rand() & 1)
		swap(a, b);
	if (a != b)
		p[a] = b;
}

int main()
{
	ifstream fin("input.txt");
	int m = 0;
	vector < pair < int, pair<int, int> > > g;
	vector<pair<int, int>> vec;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		fin >> x >> y;
		for (int j = 0; j < (int)vec.size(); j++)
		{
			g.push_back(make_pair(abs(x - vec[j].first) + abs(y - vec[j].second), make_pair(j, vec.size())));
			m++;
		}

		vec.push_back(make_pair(x, y));
	}
	fin.close();
	
	int cost = 0;
	vector < pair<int, int> > res;

	sort(g.begin(), g.end());
	vector<int> tree_id(n);
	for (int i = 0; i<n; ++i)
		tree_id[i] = i;
	for (int i = 0; i<m; ++i)
	{
		int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
		if (tree_id[a] != tree_id[b])
		{
			cost += l;
			res.push_back(make_pair(a, b));
			int old_id = tree_id[b], new_id = tree_id[a];
			for (int j = 0; j<n; ++j)
				if (tree_id[j] == old_id)
					tree_id[j] = new_id;
		}
	}

	int answer = 0;
	ofstream fout("output.txt");
	for (int i = 0; i < res.size(); i++)
		answer += abs(vec[res[i].first].first - vec[res[i].second].first) + abs(vec[res[i].first].second - vec[res[i].second].second);
	fout << answer << endl;
	fout.close();
}