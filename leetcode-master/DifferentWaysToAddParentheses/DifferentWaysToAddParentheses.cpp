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
vector<int> diffWaysToCompute(string input) {
	vector<int> res;
	if (input.empty()) {
		return res;
	}
	bool isNum = true;
	for (auto &x : input) {
		if (!isdigit(x)) {
			isNum = false;
		} else {

		}
	}
	if (isNum) {
		res.push_back(atoi(input.c_str()));
		return res;
	}
	int n = input.size();
	for (int i = 0; i < n; i++) {
		if (input[i] == '+') {
			vector<int> left = diffWaysToCompute(input.substr(0, i));
			vector<int> right = diffWaysToCompute(
					input.substr(i + 1, n - i - 1));
			for (auto &x : left) {
				for (auto &y : right) {
					res.push_back(x + y);
				}
			}
		} else if (input[i] == '-') {
			vector<int> left = diffWaysToCompute(input.substr(0, i));
			vector<int> right = diffWaysToCompute(
					input.substr(i + 1, n - i - 1));
			for (auto &x : left) {
				for (auto &y : right) {
					res.push_back(x - y);
				}
			}
		} else if (input[i] == '*') {
			vector<int> left = diffWaysToCompute(input.substr(0, i));
			vector<int> right = diffWaysToCompute(
					input.substr(i + 1, n - i - 1));
			for (auto &x : left) {
				for (auto &y : right) {
					res.push_back(x * y);
				}
			}

		}
	}
	sort(res.begin(), res.end());
//	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}
int main() {
	string s = "2*3-4*5";
	vector<int> res=diffWaysToCompute(s);
	for(auto &x:res){
		cout<<x<<' ';
	}
	return 0;
}


