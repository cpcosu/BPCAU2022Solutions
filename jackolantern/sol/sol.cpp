#include <bits/stdc++.h>

using namespace std;

int main() {
	int heightEyes, numTeeth;

	cin >> heightEyes >> numTeeth;

	int strWidth = 4 * (heightEyes - 1) + 6;

	const int arrlen = heightEyes + 3;
  
	string arr[arrlen];

	for (int i = 0; i < arrlen; i++) {
		arr[i].append(strWidth, ' ');
	}

	const int eyeSep = 2 * (heightEyes - 1) + 4;

	int x = 0;
	for (int i = heightEyes - 1; i > -1; i--) {
		arr[i][x] = '/';
		arr[i][x + eyeSep] = '/';
		x++;
  	}

	for(int i = 0; i < heightEyes; i++) {
		arr[i][x] = '\\';
		arr[i][x + eyeSep] = '\\';
		x++;
	}

	const int eyeBottom = 2 * (heightEyes - 1);
	
	if (eyeBottom) {
		for (int i = 0; i < eyeBottom; i++) {
			arr[heightEyes - 1][1 + i] = '_';
			arr[heightEyes - 1][1 + i + eyeSep] = '_';
		}
	}

	const int teethStart = (strWidth - (2 * numTeeth)) / 2;

	x = teethStart;
	for (int i = 0; i < numTeeth; i++) {
		arr[heightEyes + 1][x] = '\\';
		arr[heightEyes + 1][x + 1] = '/';
		arr[heightEyes + 2][x] = '/';
		arr[heightEyes + 2][x + 1] = '\\';
		x += 2;
	}
	

  	for (string x : arr) {
		cout << x << endl;
  	}

	return 0;
}