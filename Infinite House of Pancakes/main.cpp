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

		sort(pancakes.begin(), pancakes.end());
		unsigned int longestTime = pancakes.back();

		unsigned int count = pancakes.size();
		unsigned int shortestTime = longestTime;

		for (unsigned int i = 0; i < count;i += 1)
		{
			unsigned int lower = longestTime / 2;
			unsigned int upper = longestTime - lower;

			unsigned int increaseAmount = 0;
			do
			{
				pancakes.pop_back();
				increaseAmount += 1;
			} while (pancakes.size() > 0 && pancakes.back() == longestTime);
			for (unsigned int i = 0; i < increaseAmount; i += 1)
			{
				pancakes.push_back(lower);
				pancakes.push_back(upper);
			}

			for (int i = 0; i < pancakes.size(); i += 1)
			{
				pancakes[i] += increaseAmount;
			}
			sort(pancakes.begin(), pancakes.end());

			if (longestTime < shortestTime)
			{
				shortestTime = longestTime;
			}
			if (pancakes.back() < shortestTime)
			{
				shortestTime = pancakes.back();
			}

			longestTime = pancakes.back();
		}
		time.push_back(shortestTime);
	}
	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << time[tc] << endl;
	}
}

