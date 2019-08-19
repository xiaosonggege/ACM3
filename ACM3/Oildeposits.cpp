#include "pch.h"
#include "Oildeposits.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
using namespace std;
Oildeposits::Oildeposits(const string &ps) : path(ps) {
	ifstream ifstrm;
	ifstrm.open(this->path, ios::in);
	string s;
	while (getline(ifstrm, s)) {
		istringstream istr(s);
		istream_iterator<char> in_iter(istr), eof;
		vector<char> graph_row(in_iter, eof);
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