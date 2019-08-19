#include "pch.h"
#include "Oildeposits.h"
#include <iostream>
#include <memory>
using namespace std;
int main() {
	string p = "C:\\Users\\xiaosong\\Desktop\\text.txt";
	shared_ptr<Oildeposits> o = make_shared<Oildeposits>(p);
	o->dfs();
	o->print(cout);
	return 0;
}
