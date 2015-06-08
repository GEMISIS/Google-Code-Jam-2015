#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>

/*
Inputs:
-Number of test cases
-K - The number of letters on the keyboard
-L - The number of letters in the target string
-S - The typed string's length
-The monkey's keyboard containing K character.
-The target word with L characters.

Outputs:
"Case #x: y"
where x is the test case and y "NOT POSSIBLE" if not a valid combination, or the 
*/

#define ul unsigned long long
#define ui unsigned int
#define sl signed long long
#define si signed int

using namespace std;

string solve(ul k, ul l, ul s, string a, string b)
{
	double chance = 0.0;

	bool exists = true;

	for (char c : b)
	{
		if (a.find(c) == string::npos)
		{
			exists = false;
			break;
		}
	}

	if (exists)
	{
		vector<char> cs;
		vector<double> chances;
		for (char c : b)
		{
			if (find(cs.begin(), cs.end(), c) == cs.end())
			{
				double n = count(a.begin(), a.end(), c);
				n /= a.length();
				n = pow(n, count(b.begin(), b.end(), c));
				cs.push_back(c);
				chances.push_back(n);
			}
		}

		chance = 1;
		for (double d : chances)
		{
			chance *= d;
		}
		chance *= (s / l);

		chance = (s / l) - chance;
	}

	return to_string(chance);
}

int main(int argc, char* argv[])
{
	unsigned int testCases = 0;
	cin >> testCases;

	vector<string> testCaseYs;

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		ul k, l, s;
		string a, b;
		cin >> k >> l >> s;
		cin >> a >> b;
		testCaseYs.push_back(solve(k, l, s, a, b));
	}

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << testCaseYs[tc] << endl;
	}
}
