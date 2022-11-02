#include <bits/stdc++.h>

using namespace std;

int main() {
	int numberOfBuckets, numberOfCandies;
	cin >> numberOfBuckets >> numberOfCandies;

	int candyArray[numberOfCandies];
	for (int i = 0; i < numberOfCandies; i++) {
		cin >> candyArray[i];
	}

	int lowestPossible = 1;

	int highestPossible = 0;
	for (int x : candyArray) {
		highestPossible = (x > highestPossible) ? x : highestPossible;
	}

	// Binary search to awnser

	while (lowestPossible != highestPossible) {
		// Middle is max amount per bucket for this iteration
		int middle = (lowestPossible + highestPossible) / 2;

		int totalNumberOfBucketsTaken = 0;

		for (int candyAmt : candyArray) {
			totalNumberOfBucketsTaken += ceil(candyAmt * 1.0 / middle);
		}

		if (totalNumberOfBucketsTaken > numberOfBuckets) {
			lowestPossible = middle + 1;
		} else {
			highestPossible = middle;
		}	
	}

	cout << lowestPossible << endl;

	return 0;
}