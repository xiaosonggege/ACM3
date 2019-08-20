#ifndef ACIENTMESSAGE_H
#define ACIENTMESSAGE_H
#include "pch.h"
#include <vector>
#include <map>
using namespace std;
class AcientMessage {
private:
	vector<string> hex; //16进制字符组
	vector<vector<char>> graph; //2进制字符矩阵
	map<char, string> hex_binary = {
		{'0', "0000"},
	{'1', "0001"},
	{'2', "0010"}, 
	{'3', "0011"}, 
	{'4', "0100"}, 
	{'5', "0101"}, 
	{'6', "0110"}, 
	{'7', "0111"}, 
	{'8', "1000"}, 
	{'9', "1001"}, 
	{'A', "1010"}, 
	{'B', "1011"}, 
	{'C', "1100"}, 
	{'D', "1101"}, 
	{'E', "1110"}, 
	{'F', "1111"}
	};
	map<int, char> hole_num = { {2, 'A'}, {4, 'J'}, {6, 'D'}, {5, 'S'}, {1, 'W'}, {3, 'K'} };
public:
	AcientMessage() = default;
	AcientMessage(const vector<string> &);
	~AcientMessage();
	AcientMessage(const AcientMessage &);
	AcientMessage(AcientMessage &&);
	AcientMessage & operator=(const AcientMessage &);
	AcientMessage & operator=(AcientMessage &&);
};
#endif // !ACIENTMESSAGE_H

