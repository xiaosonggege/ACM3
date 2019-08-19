#ifndef OILDEPOSITS_H
#define OILDEPOSITS_H
#include "pch.h"
#include <vector>
#include <string>
using namespace std;
class Oildeposits {
private:
	string path;
	vector<vector<char>> graph;
	int count = 0;
public:
	Oildeposits() = default;
	Oildeposits(const string &);
	~Oildeposits();
	Oildeposits(const Oildeposits &);
	Oildeposits(Oildeposits &&);
	Oildeposits & operator=(const Oildeposits &);
	Oildeposits & operator=(Oildeposits &&);
};
#endif // !OILDEPOSITS_H

