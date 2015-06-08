#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
Inputs:
-Number of test cases
-Number of non-empty plates
-Space seperated customers with pancake amounts
Outputs:
Case #x: y
where x is the test case and y is the number of minutes to eat all the pancakes (including moving them time).
*/

using namespace std;

int main(int argc, char* argv[])
{
	unsigned int testCases = 0;
	cin >> testCases;

	vector<unsigned int> time;

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		unsigned int filledPlates = 0;
		cin >> filledPlates;

		vector<unsigned int> pancakes;

		for (unsigned int plates = 0; plates < filledPlates; plates += 1)
		{
			unsigned int pancake = 0;
			cin >> pancake;

			pancakes.push_back(pancake);
		}

		const unsigned int maxPancakes = *max_element(pancakes.begin(), pancakes.end());
		unsigned int totalTime = maxPancakes;

		for (unsigned int x = 1; x < maxPancakes; x += 1)
		{
			unsigned int totalMoves = 0;

			for (const int pancake : pancakes)
			{
				totalMoves += (pancake - 1) / x;
			}
			totalTime = min(totalTime, totalMoves + x);
		}

		time.push_back(totalTime);
	}
	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << time[tc] << endl;
	}
}

