#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>

/*
Inputs:
-Number of test cases
-The number of trees
-The coordinates of each tree

Outputs:
"Case #x:
y
y
y"
where x is the test case and y is the number of trees to cut down to become part of the outline.
*/

using namespace std;

int orientation(int x1, int x2, int x3, int y1, int y2, int y3)
{
	int val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);

	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

vector<unsigned int> solve(vector<unsigned long long> xs, vector<unsigned long long> ys)
{
	vector<unsigned int> trees;

	unsigned long long minx = 1000000, miny = 1000000, maxx = 0, maxy = 0;

	for (unsigned int i = 0; i < xs.size(); i += 1)
	{
		minx = min(minx, xs[i]);
		miny = min(miny, ys[i]);

		maxx = max(maxx, xs[i]);
		maxy = max(maxy, ys[i]);
	}

	return trees;
}

int main(int argc, char* argv[])
{
	unsigned int testCases = 0;
	cin >> testCases;

	vector<vector<unsigned int>> testCaseYs;

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		unsigned int trees;
		vector<unsigned long long> xs;
		vector<unsigned long long> ys;

		cin >> trees;

		for (unsigned int i = 0; i < trees; i += 1)
		{
			unsigned long long x, y;
			cin >> x;
			cin >> y;

			xs.push_back(x);
			ys.push_back(y);
		}

		vector<unsigned int> counts = solve(xs, ys);

		testCaseYs.push_back(counts);
	}

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << endl;
		for (unsigned int tree = 0; tree < testCaseYs[tc].size(); tree += 1)
		{
			cout << testCaseYs[tc][tree] << endl;
		}
	}
}
