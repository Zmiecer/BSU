#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm> 

using namespace std;

bool cmp1(string s1, string s2)
{
	if (s1 >= s2) return 0; else return 1;
}



int main()
{
	vector<string> uniq(5);
	string str;
	int k=0;
	/*for (;k!=1;)
	{
		cin >> str;
		lake.push_back(str);
		cin >> k;
	}*/
	//vector<string>::iterator iter;

/*for (iter=lake.begin(); iter!=lake.end(); iter++)
	{
		cin >> k;
		switch(k)
		{
		case(1): {fisher1.push_back(*iter); break;}
		case(2): {fisher2.push_back(*iter); break;}
		case(3): {fisher3.push_back(*iter); break;}
		}
	}*/

	

	string fir1[10], fir2[10], fir3[10];
	fir1[0]="fish1";
	fir1[1]="fish2";
	fir1[2]="fish3";
	fir1[3]="fish5";
	fir2[0]="fish1";
	fir2[1]="fish3";

	//¬вод рыбок в сеты:
	set<string> fisher1, fisher2, fisher3, lake;
    fisher1.insert("fish1");
	fisher1.insert("fish2");
	fisher1.insert("fish3");
	fisher1.insert("fish5");
	fisher2.insert("fish1");
	fisher2.insert("fish3");
	fisher3.insert("fish5");
	lake.insert("fish1");
	lake.insert("fish2");
	lake.insert("fish3");
	lake.insert("fish4");
	lake.insert("fish5");
	
	// ѕункт 2
	vector<string>::iterator iter;
	vector<string>::iterator it;
	iter=set_union(fisher1.begin(), fisher1.end(), fisher2.begin(), fisher2.end(), uniq.begin());
	//cout << uniq.back();
	uniq.resize(iter-uniq.begin());
	cout << endl << uniq.size() << endl;

	//ѕункт 3
	//inplace_merge(fisher1.begin(), fisher1.end(), fisher2.begin(), fisher2.end());
	uniq.resize(5);
	iter=set_difference(lake.begin(), lake.end(), fisher1.begin(), fisher1.end(), uniq.begin());
	//cout << uniq.back();
	uniq.resize(iter-uniq.begin());
	cout << endl << uniq.size() << endl;
}