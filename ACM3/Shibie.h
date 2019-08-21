#ifndef SHIBIE_H
#define SHIBIE_H
#include "pch.h"
#include "AcientMessage.h"
#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;
class Shibie {
private:
	string path;
	vector<AcientMessage> v_a;
public:
	Shibie() = default;
	Shibie(const string &);
	~Shibie();
	Shibie(const Shibie &);
	Shibie(Shibie &&);
	Shibie & operator=(const Shibie &);
	Shibie & operator=(Shibie &&);
	ostream & dfs(ostream &);
	int dfs_sub(vector<vector<pair<char, int>>> &, const int &, const int &, int);
};
#endif // !SHIBIE_H

