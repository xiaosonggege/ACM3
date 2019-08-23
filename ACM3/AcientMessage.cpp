#include "pch.h"
#include "AcientMessage.h"
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
using namespace std;
AcientMessage::AcientMessage(const vector<string> &hexs) :
	hex(hexs) {
	for (auto iter = hex.cbegin(); iter != hex.cend(); ++iter) {
		string s_row;
		for (auto const &e : *iter) s_row += this->hex_binary[e];
		istringstream istr(s_row);
		istream_iterator<char> in_iter(istr), eof;
		vector<char> graph_row(in_iter, eof);
		graph_row.insert(graph_row.begin(), '0');
		graph_row.push_back('0');
		this->graph.push_back(graph_row);
	}
	vector<char> zero(graph[0].size(), '0');
	this->graph.insert(graph.begin(), zero);
	this->graph.push_back(zero);
}
AcientMessage::~AcientMessage() {}
AcientMessage::AcientMessage(const AcientMessage &a) {
	this->hex = a.hex;
	this->graph = a.graph;
	this->hex_binary = a.hex_binary;
	this->hole_num = a.hole_num;
}
AcientMessage::AcientMessage(AcientMessage &&a) {
	this->hex = a.hex;
	this->graph = a.graph;
	this->hex_binary = a.hex_binary;
	this->hole_num = a.hole_num;
	a.hex.clear();
	a.graph.clear();
	a.hex_binary.clear();
	a.hole_num.clear();
}
AcientMessage & AcientMessage::operator=(const AcientMessage &a) {
	this->hex = a.hex;
	this->graph = a.graph;
	this->hex_binary = a.hex_binary;
	this->hole_num = a.hole_num;
	return *this;
}
AcientMessage & AcientMessage::operator=(AcientMessage &&a) {
	this->hex = a.hex;
	this->graph = a.graph;
	this->hex_binary = a.hex_binary;
	this->hole_num = a.hole_num;
	a.hex.clear();
	a.graph.clear();
	a.hex_binary.clear();
	a.hole_num.clear();
	return *this;
}
