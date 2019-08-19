#ifndef OILDEPOSITS_H
#define OILDEPOSITS_H
#include "pch.h"
#include <vector>
#include <string>
#include <utility>
using namespace std;
class Oildeposits {
private:
	string path;
	vector<vector<pair<char, int>>> graph;
	int count = 0;
public:
	Oildeposits() = default;
	Oildeposits(const string &);
	~Oildeposits();
	Oildeposits(const Oildeposits &);
	Oildeposits(Oildeposits &&);
	Oildeposits & operator=(const Oildeposits &);
	Oildeposits & operator=(Oildeposits &&);
	int dfs_sub(const int &x, const int &y, int flag);
	int dfs();
	ostream & print(ostream &);
};
#endif // !OILDEPOSITS_H

