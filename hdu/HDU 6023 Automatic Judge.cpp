/*
Problem Description
Welcome to HDU to take part in the second CCPC girls¡¯ competition!
A new automatic judge system is used for this competition. During the five-hour contest time, you can submit your code to the system, then the judge will reply you. Here is a list of the judge's replies and their meaning:

1. Accepted(AC): Yes, your program is correct. You did a good job!

2. PresentationError(PE) : Your program's output format is not exactly the same as required by the problem, although the output is correct. This usually means the existence of omitted or extra blank characters (white spaces, tab characters and/or new line characters) between any two non-blank characters, and/or blank lines (a line consisting of only blank characters) between any two non-blank lines. Trailing blank characters at the end of each line and trailing blank lines at the of output are not considered format errors. Check the output for spaces, blank lines, etc. against the problem's output specification.

3. WrongAnswer(WA) : Correct solution not reached for the inputs. The inputs and outputs that we use to test the programs are not public (it is recomendable to get accustomed to a true contest dynamic :-)

4. RuntimeError(RE) : Your program failed during the execution and you will receive the hints for the reasons.

5. TimeLimitExceeded(TLE) : Your program tried to run during too much time.

6. MemoryLimitExceeded(MLE): Your program tried to use more memory than the judge default settings.

7. OutputLimitExceeded(OLE): Your program tried to write too much information. This usually occurs if it goes into a infinite loop.

8. CompilationError(CE): The compiler fails to compile your program. Warning messages are not considered errors. Click on the judge's reply to see the warning and error messages produced by the compiler.

For each submission, if it is the first time that the judge returns ``AC'' on this problem, then it means you have passed this problem, and the current time will be added to the penalty of your team. In addition, every time you pass a problem, each unsuccessful try for that problem before is counted as 20 minutes penalty, it should also be added to the penalty of your team.
Now given the number of problems in the contest and the submission records of a team. Please write a program to calculate the number of problems the team passed and their penalty.


Input
The first line of the input contains an integer T(1¡ÜT¡Ü20), denoting the number of test cases.
In each test case, there are two integers n(1¡Ün¡Ü13) and m(1¡Üm¡Ü100) in the first line, denoting the number of problems and the number of submissions of a team. Problems are labeled by 1001, 1002, ..., 1000+n.
In the following m lines, each line contains an integer x(1001¡Üx¡Ü1000+n) and two strings t(00:00¡Üt¡Ü05:00) and s, denoting the team submits problem x at time t, and the result is s. t is in the format of HH:MM, while s is in the set \{AC, PE, WA, RE, TLE, MLE, OLE\}. The team is so cautious that they never submit a CE code. It is guaranteed that all the t in the input is in ascending order and every t is unique.


Output
For each test case, print a single line containing two integers A and B, denoting the number of problems the team passed and the penalty.


Sample Input
1
3 5
1002 00:02 AC
1003 00:05 WA
1003 00:06 WA
1003 00:07 AC
1002 04:59 AC


Sample Output
2 49

*/
#include <iostream>
#include <cstdio>
#include <map>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int main() {
//	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		map<int,int> ac,wa,sumtt;
		char str[5];
		int n, num;
		int index, h, m;
		int sum = 0;
		long sumt = 0;
		scanf("%d%d", &n, &num);
		for (int i = 0; i < num; i++) {
			scanf("%d %d:%d %s", &index,&h,&m,str );
			if (str[0] == 'A'){
				if(!ac[index]){
					ac[index]++;
					sum++;
					sumt += h * 60 + m + sumtt[index];
				}
			}
			else {
				sumtt[index] += 20;
			}
		}
		printf("%d %ld\n", sum, sumt);
	}
	return 0;
}