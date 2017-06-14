#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> INTVECTOR;

//分别使用不同的容器，，进行排序，然后打印所有元素
//Vector版本比Set至少快10%，只是一个权威说法，150000字符验证
//暂时不用
int main()
{
	vector<string> coll((istream_iterator<string>(cin)),(istream_iterator<string>()));
	sort(coll.begin(), coll.end());
	//从标准输入读取字符串
	unique_copy(coll.begin(), coll.end(), ostream_iterator<string>(cout, "\n"));
}
int main2()
{
	//初始化
	INTVECTOR vec1;//初始化为空
	INTVECTOR vec2(10, 6);//初始化10个值为6的元素
	INTVECTOR vec3(vec2.begin(), vec2.begin()+3);//初始化3个值为6的元素

	//输出信息
	INTVECTOR::iterator i;//声明双向迭代器
	cout << "vec1:";
	for (i=vec1.begin(); i!=vec1.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	cout << "vec2:";
	for (i=vec2.begin(); i!=vec2.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	cout << "vec3:";
	for (i=vec3.begin(); i!=vec3.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;

	//添加和插入
	vec1.push_back(2);
	vec1.push_back(4);
	vec1.insert(vec1.begin()+1, 5);
	vec1.insert(vec1.begin()+1, vec3.begin(), vec3.end());
	cout << "push and insert vec1:";
	for (i=vec1.begin(); i!=vec1.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;

	//赋值操作
	vec2.assign(8, 1);
	cout << "assign vec2:";
	for (i=vec2.begin(); i!=vec2.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;

	//引用类函数
	cout << "vec1.front:" << vec1.front() << endl;
	cout << "vec1.back:" << vec1.back() << endl;
	cout << "vec1.at(4):" << vec1.at(4) << endl;//可以对越界报错
	cout << "vec1[4]:" << vec1[4] << endl;

	//移出和删除
	vec1.pop_back();
	vec1.erase(vec1.begin(), vec1.end()-2);
	cout << "pop and erase vec1:";
	for (i=vec1.begin(); i!=vec1.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;

	//显示状态信息
	cout << "vec1.capacity:" << vec1.capacity() << endl;
	cout << "vec1.size:" << vec1.size() << endl;
	cout << "vec1.maxsize:" << vec1.max_size() << endl;
	cout << "vec1.empty:" << vec1.empty() << endl;

	//显示运算
	cout << "vec1==vec3:" << (vec1==vec3) << endl;
	cout << "vec1<=vec3:" << (vec1<=vec3) << endl;

	return 0;
}

int main1()
{
	vector<string> st1;
	st1.reserve(5);
	st1.push_back("Hello,");
	st1.push_back("how");
	st1.push_back("are");
	st1.push_back("you");
	st1.push_back("?");
	//st1.push_back("Y");

	copy(st1.begin(), st1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	cout << "Max_Size:" << st1.max_size() << endl;
	cout << "Size:" << st1.size() << endl;
	cout << "Capacity:" << st1.capacity() << endl;

	swap(st1[1], st1[3]);
	st1.insert(find(st1.begin(), st1.end(), "?"), "always");

	st1.back() = "!";
	copy(st1.begin(), st1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	cout << "New Max_Size:" << st1.max_size() << endl;
	cout << "New Size:" << st1.size() << endl;
	cout << "New Capacity:" << st1.capacity() << endl;

	return 0;
}