#include "pch.h"
//#include "Oildeposits.h"
#include "AcientMessage.h"
#include <iostream>
#include <memory>
using namespace std;
int main() {
	string p = "C:\\Users\\xiaosong\\Desktop\\text.txt";
	vector<string> s = { "FFF", "F0F", "FFF", "F0F", "FFF" };
	shared_ptr<AcientMessage> a = make_shared<AcientMessage>(s);
	return 0;
}
