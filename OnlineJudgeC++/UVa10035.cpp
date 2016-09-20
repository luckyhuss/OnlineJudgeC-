// UVa OnlineJudge | Problem # 10035 | Primary Arithmetic | 19/08/2015 : KO
#include <iostream>
#include <string>
using namespace std;

int main() {
	// declare all local variables
	unsigned int first = 0, second = 0, sum = 0;
	int x = 0, carry = 0;
	unsigned int inputs[500][2];
	bool isCarry = false;

	while (cin >> first >> second) { // loop for each value-pair

		inputs[x][0] = first;
		inputs[x][1] = second;

		if (first == 0 && second == 0) { // exit input
			break;
		}
		x++;
	}

	for (int i = 0; i < x; i++) {
		string firstText = to_string(inputs[i][0]);
		string secondText = to_string(inputs[i][1]);
		carry = 0;
		for (int j = firstText.length() - 1; j >= 0; j--) {
			
			int sum = (int)firstText[j] + (int)secondText[j];
			if (sum > 9) carry++;
			cout << ((int)firstText[j] - '0') * 2 << ' ';
		}
	}

	//cout << inputs[i][0] << ' ' << inputs[i][1] << endl;
	cin >> x;
	return 0;
}