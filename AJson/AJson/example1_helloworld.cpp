#include <iostream>
#include <string>

#include "ajson.hpp"
//https://gitee.com/lordoffox/ajson
using namespace std;
using namespace ajson;

struct demo
{
	string hello;
	string world;
};

AJSON(demo, hello, world)

int main1(int argc, char * argv[])
{
	const char* buff = "{\"hello\" : \"Hello\", \"world\" : \"world.\"}";
	demo the_demo;
	load_from_buff(the_demo, buff);
	cout << the_demo.hello << " " << the_demo.world << std::endl;
	cin.get();
	return 0;
}
