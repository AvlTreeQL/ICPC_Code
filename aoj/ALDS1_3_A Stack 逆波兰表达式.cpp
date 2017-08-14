/*
逆波兰表达式是一种吧运算符后置的算术表达式，
例如普通的表达式 2 + 3 的逆波兰表示为 2 3 +
逆波兰表达式的优点是运算符之间不必有优先级的关系，也不必有括号改变运算次序，
例如（2+3）*4的逆波兰表示法为 2 3 + 4 * .本题求解的逆波兰表达式的值。



输入数据：

输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。

输出要求：

输出为一行，即表达式的值。

输入样例：

1 2 + 5 4 + *

输出样例：

27
*/
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
template <class T>
class stack {
public:
	int p_top;
	T data[1010];
	stack() {
		p_top = 0;
	}
	void push(T x) {
		p_top++;
		data[p_top] = x;
	}
	int size() {
		return p_top;
	}
	bool empty() {
		return p_top == 0;
	}
	T pop() {
		if (!empty()) {
			T temp = data[p_top];
			data[p_top] = 0;
			p_top--;
			return temp;
		}
	}
	T top() {
		return data[p_top];
	}

};
int main() {
//	freopen("input.txt", "r", stdin);
	stack<int> sk;
	char str[100];
	while (~scanf("%s", str)) {
		if (str[0] == '+') {
			int b = sk.pop();
			int a = sk.pop();
			sk.push(a + b);
		}
		else if (str[0] == '-') {
			int b = sk.pop();
			int a = sk.pop();
			sk.push(a - b);
		}
		else if (str[0] == '*') {
			int b = sk.pop();
			int a = sk.pop();
			sk.push(a * b);
		}
		else {
			sk.push(atoi(str));
		}
	}
	printf("%d\n", sk.top());
	return 0;
}