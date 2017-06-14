#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	std::vector<int> c{ 1,2,3,4,5,6,7 };
	int x = 5;
	c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());

	cout << "c: ";
	for (auto i : c) {
		cout << i << ' ';
	}
	cout << '\n';

	// the type of a closure cannot be named, but can be inferred with auto
	auto func1 = [](int i) { return i + 4; };
	cout << "func1: " << func1(6) << '\n';

	// like all callable objects, closures can be captured in std::function
	// (this may incur unnecessary overhead)
	std::function<int(int)> func2 = [](int i) { return i + 4; };
	cout << "func2: " << func2(6) << '\n';

	cin.get();
}

//#include <algorithm>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//// The number of elements in the vector.
//const int elementCount = 9;
//
//int main()
//{
//	// Create a vector object with each element set to 1.
//	vector<int> v(elementCount, 1);
//
//	// These variables hold the previous two elements of the vector.
//	int x = 1;
//	int y = 1;
//
//	// Assign each element in the vector to the sum of the 
//	// previous two elements.
//	generate_n(v.begin() + 2, elementCount - 2, [=]() mutable throw() -> int {
//
//		// Generate current value.
//		int n = x + y;
//
//		// Update previous two values.
//		x = y;
//		y = n;
//
//		return n;
//	});
//
//	// Print the contents of the vector.
//	for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
//	cout << endl;
//
//	// Print the local variables x and y.
//	// The values of x and y hold their initial values because 
//	// they are captured by value.
//	//cout << x << " " << y << endl;
//
//	cin.get();
//}

//#include <iostream>
//using namespace std;
//
//int main1()
//{
//	int a, b;
//	cout << "a = ";
//	cin >> a;
//	cout << "b = ";
//	cin >> b;
//	//(转换式)auto f = int<lambda>(int a, int b) {return a+b;}
//	//auto f = [] (int a, int b) {return a+b;};//省略的返回类型int
//	auto f = [](int a, int b) ->int { return a + b; };
//	cout << "a + b = " << f(a, b) << endl;
//
//	cin.get();
//	cin.get();
//	return 0;
//}
//
//int main()
//{
//	int a, val;
//	cout << "a = ";
//	cin >> a;
//	cout << "val = ";
//	cin >> val;
//
//	//(转换式)auto f = int<lambda>(int a) {va=2}
//	auto f = [val](int a) ->int { return a + val; };//接受一个参数，返回参数和捕获的值的和
//	cout << "a + val = " << f(a) << endl;
//
//	cin.get();
//	cin.get();
//	return 0;
//}
/*
<span style="white-space:pre">	</span>函数功能：将单词按从小到大的顺序排列，并删除重复的单词；
<span style="white-space:pre">			</span>  再按单词的长度由短到长排列。
<span style="white-space:pre">	</span>算法函数：stable_sort();sort();
*/
/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words);
bool isShorter(const string &s1, const string &s2);

void biggies(vector<string> &words,
	<span style = "white-space:pre">	< / span>vector<string>::size_type sz);//寻找第一个大于等于给定长度的元素，一旦找到就可以计算出有多少元素的长度大于等于给定值。
string make_plural(size_t ctr, const string &word, const string &ending);


int main()
{
	<span style = "white-space:pre">	< / span>
		<span style = "white-space:pre">	< / span>vector<string> words;
	<span style = "white-space:pre">	< / span>string val;
	<span style = "white-space:pre">	< / span>cout << "Input the words: ";


	<span style = "white-space:pre">	< / span>while (cin >> val)//用循环，输入字符串
		<span style = "white-space:pre">	< / span>{
		<span style = "white-space:pre">		< / span>words.push_back(val);
		<span style = "white-space:pre">	< / span>}
	<span style = "white-space:pre">	< / span>elimDups(words);//调用函数，排序，删除


	<span style = "white-space:pre">	< / span>stable_sort(words.begin(), words.end(), isShorter);
	<span style = "white-space:pre">	< / span>cout << "The output is: ";//输出排序删除之后的单词
	<span style = "white-space:pre">	< / span>for (auto beg = words.begin(), end = words.end(); beg != end; ++beg)
		<span style = "white-space:pre">		< / span>cout << *beg << " ";
	<span style = "white-space:pre">	< / span>cout << endl;


	<span style = "white-space:pre">	< / span>biggies(words, 4);
	<span style = "white-space:pre">	< / span>
		<span style = "white-space:pre">	< / span>while (1);
	<span style = "white-space:pre">	< / span>return 0;
}
void elimDups(vector<string> &words)
{
	<span style = "white-space:pre">	< / span>sort(words.begin(), words.end());//按字典序排序
	<span style = "white-space:pre">	< / span>//uinque重排输入范围，使得每个单词只出现一次
		<span style = "white-space:pre">	< / span>//排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
		<span style = "white-space:pre">	< / span>auto end_unique = unique(words.begin(), words.end());
	<span style = "white-space:pre">	< / span>//使用向量操作erase删除重复单词
		<span style = "white-space:pre">	< / span>words.erase(end_unique, words.end());
}


bool isShorter(const string &s1, const string &s2)
{
	<span style = "white-space:pre">	< / span>return s1.size() < s2.size();
}

void biggies(vector<string> &words,
	<span style = "white-space:pre">	< / span>vector<string>::size_type sz)
{
	<span style = "white-space:pre">	< / span>elimDups(words);//将words排序，删除重复的单词
	<span style = "white-space:pre">	< / span>//按长度排序，长度相同的单词维持字典序
		<span style = "white-space:pre">	< / span>stable_sort(words.begin(), words.end(),
			<span style = "white-space:pre">				< / span>[](const string &a, const string &b)
			<span style = "white-space:pre">					< / span>{ return a.size() < b.size(); });
	<span style = "white-space:pre">	< / span>//获取第一个迭代器，指向第一个满足size()>=sz的元素
		<span style = "white-space:pre">	< / span>auto wc = find_if(words.begin(), words.end(),
			<span style = "white-space:pre">				< / span>[sz](const string &a)
			<span style = "white-space:pre">					< / span>{ return a.size() >= sz; });
	<span style = "white-space:pre">	< / span>//计算满足size>=sz的元素数数目
		<span style = "white-space:pre">	< / span>auto count = words.end() - wc;//此时的words是按长度由小到大排列的。
	<span style = "white-space:pre">	< / span>cout << count << " " << make_plural(count, "word", "s")
		<span style = "white-space:pre">		< / span> << " of length " << sz << " or longer" << endl;
	<span style = "white-space:pre">	< / span>//打印长度大于等于给定值的单词，每个单词后面接一个空格
		<span style = "white-space:pre">	< / span>for_each(wc, words.end(),
			<span style = "white-space:pre">		< / span>[](const string &s) { cout << s << " "; });
	<span style = "white-space:pre">	< / span>cout << endl;
}

string make_plural(size_t ctr, const string &word,
	<span style = "white-space:pre">							< / span>   const string &ending)
{
	<span style = "white-space:pre">	< / span>return (ctr>1) ? word + ending : word;
}
*/