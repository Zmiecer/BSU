#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, xkey, ykey;
int s = 0;
vector<vector<char>> vec;

queue<pair<int, int>> q;
vector<vector<bool>> used;
vector<vector<int>> d;
vector<vector<pair<int, int>>> p;

vector<vector<bool>> old_used;
vector<vector<pair<int, int>>> new_p;


bool isValid(int x, int y)
{
	if (x >= 0 && y >= 0 && x < m && y < n)
		return true;
	else
		return false;
}

void mov(int i, int j, int k, int l)
{
	if (isValid(k, l))
	{
		if ((vec[k][l] == '.' || vec[k][l] == 'G') && !used[k][l])
		{
			used[k][l] = true;
			q.push(make_pair(k, l));
			d[k][l] = d[i][j] + 1;
			p[k][l] = make_pair(i, j);
		}
	}
}

void mov2(int i, int j, int k, int l)
{
	if (isValid(k, l))
	{
		if ((vec[k][l] == '.' || vec[k][l] == 'G') && !used[k][l] && (!old_used[i][j] || !old_used[k][l])) 
		{
			if (old_used[i][j] && p[i][j].first >= 0 && p[i][j].second >= 0 && !old_used[new_p[i][j].first][new_p[i][j].second] && !old_used[k][l]) // Если предыдущий !old_used, нынешний old_used, то следующий обязон old_used
			{ 

			}
			else
			{
				used[k][l] = true;
				q.push(make_pair(k, l));
				d[k][l] = d[i][j] + 1;
				new_p[k][l] = make_pair(i, j);
			}
		}
	}
}

void crock1(int i, int j)
{
	mov2(i, j, i - 1, j);
	mov2(i, j, i, j - 1);
	mov2(i, j, i + 1, j);
	mov2(i, j, i, j + 1);
}



void mov1(int i, int j, int k, int l)
{
	if (isValid(k, l))
	{
		if ((vec[k][l] == '.' || vec[k][l] == 'G') && !used[k][l])
		{
			bool go = false;
			if (old_used[i][j])
			{
				if (!old_used[k][l])
				{
					go = true;
				}
			}
			else
			{
				if (!old_used[i][j])
				{
					if (old_used[k][l])
					{
						used[k][l] = true;
						q.push(make_pair(k, l));
						d[k][l] = d[i][j] + 1;
					}
					else
						go = true;
				}
			}
			if (go)
			{
				used[k][l] = true;
				q.push(make_pair(k, l));
				d[k][l] = d[i][j] + 1;
			}
		}
	}
}

void crock(int i, int j)
{
	mov(i, j, i - 1, j);
	mov(i, j, i, j - 1);
	mov(i, j, i + 1, j);
	mov(i, j, i, j + 1);
}



void bfs(int x, int y)
{

	q.push(make_pair(x, y));
	for (int i = 0; i < m; i++)
	{
		vector<bool> btmp;
		vector<int> itmp;
		vector<pair<int, int>> ptmp;
		for (int j = 0; j < n; j++)
		{
			btmp.push_back(false);
			itmp.push_back(0);
			ptmp.push_back(make_pair(-2, -2));
		}
		used.push_back(btmp);
		old_used.push_back(btmp);
		d.push_back(itmp);
		p.push_back(ptmp);
		new_p.push_back(ptmp);
	}
	used[x][y] = true;
	p[x][y] = make_pair(-1, -1);
	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		crock(i, j);
	}


	if (!used[xkey][ykey])
		s = -1;
	else
	{
		for (int i = xkey, j = ykey; i != x || j != y;)
		{
			int t1, t2;
			t1 = p[i][j].first;
			t2 = p[i][j].second;
			i = t1;
			j = t2;
			old_used[i][j] = true;
		}
		s += d[xkey][ykey];
	}
	old_used[xkey][ykey] = true;
	old_used[x][y] = true;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			used[i][j] = false;
			d[i][j] = 0;
		}
	}

	// Дважды BFS вперёд, превый обычный, второй обычный с возвратом по рёбрам

	q.push(make_pair(x, y));
	used[x][y] = true;
	new_p[x][y] = make_pair(-1, -1);
	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if (old_used[i][j] && (i != x || j != y) && !used[p[i][j].first][p[i][j].second])
		{
			q.push(make_pair(p[i][j].first, p[i][j].second));
			d[p[i][j].first][p[i][j].second] = d[i][j] + 1;
			new_p[p[i][j].first][p[i][j].second] = make_pair(i, j);
			used[p[i][j].first][p[i][j].second] = true;
		}
		crock1(i, j);
	}
	
	old_used[x][y] = false;
	old_used[xkey][ykey] = false;
	if (!used[xkey][ykey] || s == -1)
		s = -1;
	else
	{
		for (int i = xkey, j = ykey; i != x || j != y;)
		{
			int t1, t2;
			t1 = new_p[i][j].first;
			t2 = new_p[i][j].second;
			if (old_used[i][j] && old_used[t1][t2])
				s -= 2;
			//cout << t1 << ' ' << t2 << endl;
			i = t1;
			j = t2;
		}
		s += d[xkey][ykey];
	}

	/*if (!used[xkey][ykey] || s == -1)
		s = -1;
	else
	{
		s += d[xkey][ykey];
	}*/



}


bool cmp(vector<pair<int, int>> x, vector<pair<int, int>> y)
{
	if (x.size() < y.size())
		return 1;
	else return 0;
}

int main()
{
	ifstream fin("walk.in");

	fin >> m >> n;

	int xstart, ystart;

	for (int i = 0; i < m; i++)
	{
		vector<char> tmp;
		for (int j = 0; j < n; j++)
		{
			tmp.push_back('0');
		}
		vec.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			char t;
			fin >> t;
			vec[i][j] = t;
			if (t == 'M')
			{
				xstart = i;
				ystart = j;
			}
			if (t == 'G')
			{
				xkey = i;
				ykey = j;
			}
		}
	fin.close();

	bfs(xstart, ystart);

	ofstream fout("walk.out");
	fout << s << endl;
	fout.close();
}