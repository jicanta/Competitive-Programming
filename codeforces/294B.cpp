// https://codeforces.com/problemset/problem/294/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool can(int quanOne, int quanTwo, 
		const vector<int>& booksOne, const vector<int>& booksTwo, const int totSum) {
	if((int)booksOne.size() < quanOne || (int)booksTwo.size() < quanTwo)
		return false;
		
	int sumWidthOne = 0, sumWidthTwo = 0;
	for(int i = 0; i < quanOne; i++)
		sumWidthOne += booksOne[i];
	for(int i = 0; i < quanTwo; i++)
		sumWidthTwo += booksTwo[i];
		
	return 2 * quanTwo + quanOne >= totSum - sumWidthOne - sumWidthTwo;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> books(n);
	vector<int> booksOneWidth;
	vector<int> booksTwoWidth;
	int totSum = 0;
	for(int i = 0; i < n; i++) {
		cin >> books[i].first >> books[i].second;
		totSum += books[i].second;
		if(books[i].first == 1)
			booksOneWidth.push_back(books[i].second);
		else booksTwoWidth.push_back(books[i].second);
	}
	
	sort(rbegin(booksOneWidth), rend(booksOneWidth));
	sort(rbegin(booksTwoWidth), rend(booksTwoWidth));

	int ret = 1000000;
	for(int quanOne = 0; quanOne <= n; quanOne++) {
		for(int quanTwo = 0; quanOne + quanTwo <= n; quanTwo++) {
			if(can(quanOne, quanTwo, booksOneWidth, booksTwoWidth, totSum))
				ret = min(ret, 2 * quanTwo + quanOne);
		}
	}
	
	cout << ret << '\n';
	return 0;
}
