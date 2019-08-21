#include "pch.h"
//#include "Oildeposits.h"
#include "AcientMessage.h"
#include "Shibie.h"
#include <iostream>
#include <memory>
#include <sstream>
#include <iterator>
using namespace std;
int main() {
	string p = "C:\\Users\\xiaosong\\Desktop\\text.txt";
	shared_ptr<Shibie> s = make_shared<Shibie>(p);
	s->dfs(cout);
	return 0;
}
