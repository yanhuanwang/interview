/*
 * Basic Calculator.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: ecaiyan
 */

#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <cassert>
#include <iostream>
#include <sstream>
#include <utility>
#include <bitset>
using namespace std;
int calculate(string s) {
	int res = 0;
	stack<int> sk;
	int n = s.size();
	for (int i = n - 1; i >= 0;) {
		if (s[i] == ')' || s[i] == '+' || s[i] == '-') {
			sk.push(s[i]);
//			cout<<char(sk.top())<<' ';
			i--;
		} else if (s[i] == '(') {
			//do the math
			while ((!sk.empty()) && sk.top() != ')') {
				int b = sk.top();
				sk.pop();
				if (sk.top() == ')') {
					sk.pop();
					sk.push(b);
					break;
				}
				char op = '+';
				if (!sk.empty()) {
					op = sk.top();
					sk.pop();
				}
				int a = 0;
				if (!sk.empty()) {
					a = sk.top();
					sk.pop();
				}
				int c;
				if (op == '+') {
					c = a + b;
				} else if (op == '-') {
					c = b - a;
				}
				sk.push(c);
//				cout<<sk.top()<<' ';
			}
			i--;
		} else if (s[i] == ' ') {
			i--;
		} else {
			int len = 0;
			while (isdigit(s[i])) {
				i--;
				len++;
			}
			int val = atoi(s.substr(i + 1, len).c_str());
//			cout << val << endl;
			sk.push(val);
//			cout<<sk.top()<<' ';
		}
//		cout<<sk.top()<<' ';
	}
//	while(!sk.empty()){
//		cout<<sk.top()<<' ';
//		sk.pop();
//	}
	while (!sk.empty()) {
		int b = sk.top();
		sk.pop();
		if (sk.empty()) {
			res = b;
			break;
		}
		int op = sk.top();
		sk.pop();
		int a = sk.top();
		sk.pop();
		int c;
		if (op == '+') {
			c = a + b;
		} else if (op == '-') {
			c = b - a;
		}
		sk.push(c);
	}
	return res;
}
int main() {
	string s =
			"(9568+(9040-(380+(2042-(7115)+(6294)-(4395-(5183+9744+(7746-(1099+2718))-(9370-(8561+(9302)-(7632+(8451-(1759+(7760))-(3377+5363+9093+(8332-(4492-(1151+(1165-8833+(775+(3749)+9399))+9112+(6273+(7285-(6112-(668-(7756-4316-(582+1835-(6644+690+1204-(7197+(7897))+(7009-(7262))-7782-(7858+(7644+(9461+(2224)-(7531-1095-(891+1022)+2197-(9855)))+(6663-(7417-(6158-(3610))+(1481))-(4182+(4761)))+(5017))+(9990)+(6218)))-(2904)+(5631)-(8888)+3401+(3569))+(1135))-(3695-(7713+(3479)-(9813+(8171+(8616-8026+(4634-(6973))-(9761-(623-4782)+(2514)+(6233)))))+(6140))-(6641)-8611+(8389)+8074-(4412))-(3703)+(9688+(9513))))-(4987)))+(9647)))))))))-(2299))-(4785))))))";
	cout << calculate(s) << endl;
//	cout<<eval(s)<<endl;
	return 0;
}


