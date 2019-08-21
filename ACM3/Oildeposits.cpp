#include "pch.h"
#include "Oildeposits.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <utility>
using namespace std;
Oildeposits::Oildeposits(const string &ps) : path(ps) {
	ifstream ifstrm;
	ifstrm.open(this->path, ios::in);
	string s;
	while (getline(ifstrm, s)) {
		istringstream istr(s);
		vector<pair<char, int>> graph_row;
		for (string::const_iterator iter = s.cbegin(); iter != s.cend(); ++iter)
			graph_row.push_back({ *iter, 0 });
		this->graph.push_back(graph_row);
	}
	ifstrm.close();
}
Oildeposits::~Oildeposits() {}
Oildeposits::Oildeposits(const Oildeposits &o) {
	this->path = o.path;
	this->graph = o.graph;
	this->count = o.count;
}
Oildeposits::Oildeposits(Oildeposits &&o) {
	this->path = o.path;
	this->graph = o.graph;
	this->count = o.count;
	o.path.clear();
	o.graph.clear();
	o.count = 0;
}
Oildeposits & Oildeposits::operator=(const Oildeposits &o) {
	this->path = o.path;
	this->graph = o.graph;
	this->count = o.count;
	return *this;
}
Oildeposits & Oildeposits::operator=(Oildeposits &&o) {
	this->path = o.path;
	this->graph = o.graph;
	this->count = o.count;
	o.path.clear();
	o.graph.clear();
	o.count = 0;
	return *this;
}
int Oildeposits::dfs_sub(const int &x, const int &y, int flag) {
	if (this->graph[x][y].first == '@' && !this->graph[x][y].second) {
		this->graph[x][y].second = flag;
		int xl = (x - 1 > 0) ? x - 1 : 0;
		int yl = (y - 1 > 0) ? y - 1 : 0;
		int xr = (x + 2 < this->graph.size())? x + 2 : this->graph.size();
		int yr = (y + 2 < this->graph[0].size()) ? y + 2 : this->graph[0].size();
		for (int i = xl; i != xr; ++i)
			for (int j = yl; j != yr; ++j)
				this->dfs_sub(i, j, flag);
	}
	return 0;
}
int Oildeposits::dfs() {
	for (int i = 0; i != this->graph.size(); ++i) {
		for (int j = 0; j != this->graph[0].size(); ++j) {
			if (this->graph[i][j].first == '@' && !this->graph[i][j].second) {
				++this->count;
				this->dfs_sub(i, j, count);
			}
		}
	}
	return 0;
}
ostream & Oildeposits::print(ostream &os) {
	os << "连通集个数为:" << this->count << endl;
	return os;
}