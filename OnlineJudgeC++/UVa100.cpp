// UVa OnlineJudge | Problem # 100 | The 3n + 1 problem | 19/08/2015 : OK
#include <iostream>
using namespace std;

int _main() {
	// declare all local variables
	int start = 1, end = 1, currentCycle = 1, maxCycle = 0;
	unsigned int n = 1;
	
	while (cin >> start >> end) { // loop for each value-pair
		maxCycle = 0; // reset max. number of cycles for new inputs
		if (start < 1 || end >= 1000000) {
			return 0; // exit if range not OK
		}
		int temp_start = start;
		int temp_end = end;
		if (start > end) swap(start, end);

		for (int i = start; i <= end; i++) {
			n = i;
			currentCycle = 1;			
			while (n != 1) {
				n = (n % 2 == 0) ? (n / 2) : (3 * n + 1); // if even else odd
				currentCycle++; // increment number of cycle
			}

			if (currentCycle > maxCycle) {
				maxCycle = currentCycle; // reset max. number of cycles
			}
		}
		// print out the result for each input pair
		cout << temp_start << ' ' << temp_end << ' ' << maxCycle << endl;
	}
	return 0;
}