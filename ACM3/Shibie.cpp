#include "pch.h"
#include "Shibie.h"
#include "AcientMessage.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <utility>
#include <map>
using namespace std;
Shibie::Shibie(const string &paths) : path(paths) {
	ifstream ifstrm;
	ifstrm.open(this->path, ios::in);
	string s;
	while (getline(ifstrm, s)) {
		istringstream istr(s);
		istream_iterator<string> in_iter(istr), eof;
		vector<string> v_a_str(in_iter, eof);
		v_a.emplace_back(v_a_str);
	}
	ifstrm.close();
}
Shibie::~Shibie() {}
Shibie::Shibie(const Shibie &s) {
	this->path = s.path;
	this->v_a = s.v_a;
}
Shibie::Shibie(Shibie &&s) {
	this->path = s.path;
	this->v_a = s.v_a;
	s.path.clear();
	s.v_a.clear();
}
Shibie & Shibie::operator=(const Shibie &s) {
	this->path = s.path;
	this->v_a = s.v_a;
	return *this;
}
Shibie & Shibie::operator=(Shibie &&s) {
	this->path = s.path;
	this->v_a = s.v_a;
	s.path.clear();
	s.v_a.clear();
	return *this;
}
int Shibie::dfs_sub(vector<vector<pair<char, int>>> &graph, const int &x, const int &y, int flag) {
	if (graph[x][y].first == '0' && !graph[x][y].second) {
		graph[x][y].second = flag;
		int xl = (x - 1 > 0) ? x - 1 : 0;
		int yl = (y - 1 > 0) ? y - 1 : 0;
		int xr = (x + 2 < graph.size()) ? x + 2 : graph.size();
		int yr = (y + 2 < graph[0].size()) ? y + 2 : graph[0].size();
		for (int i = xl; i != xr; ++i)
			for (int j = yl; j != yr; ++j)
				this->dfs_sub(graph, i, j, flag);
	}
	return 0;
}
ostream & Shibie::dfs(ostream &os) {
	int count = 0;
	for (auto iter = v_a.begin(); iter != v_a.end(); ++iter) {
		vector<vector<pair<char, int>>> v_a_f;
		for (int i = 0; i != iter->graph.size(); ++i) {
			vector<pair<char, int>> v_a_f_row;
			for (int j = 0; j != iter->graph[0].size(); ++j) {
				v_a_f_row.push_back({ iter->graph[i][j], 0 });
			}
			v_a_f.push_back(v_a_f_row);
		}
		for (int i = 0; i != v_a_f.size(); ++i) {
			for (int j = 0; j != v_a_f[0].size(); ++j) {
				if (v_a_f[i][j].first == '0' && !v_a_f[i][j].second) {
					++count;
					this->dfs_sub(v_a_f, i, j, count);
				}
			}
		}
		cout << iter->hole_num[count] << endl;
		count = 0;
	}
	return os;
}