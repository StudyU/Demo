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
//	//(ת��ʽ)auto f = int<lambda>(int a, int b) {return a+b;}
//	//auto f = [] (int a, int b) {return a+b;};//ʡ�Եķ�������int
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
//	//(ת��ʽ)auto f = int<lambda>(int a) {va=2}
//	auto f = [val](int a) ->int { return a + val; };//����һ�����������ز����Ͳ����ֵ�ĺ�
//	cout << "a + val = " << f(a) << endl;
//
//	cin.get();
//	cin.get();
//	return 0;
//}
/*
<span style="white-space:pre">	</span>�������ܣ������ʰ���С�����˳�����У���ɾ���ظ��ĵ��ʣ�
<span style="white-space:pre">			</span>  �ٰ����ʵĳ����ɶ̵������С�
<span style="white-space:pre">	</span>�㷨������stable_sort();sort();
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
	<span style = "white-space:pre">	< / span>vector<string>::size_type sz);//Ѱ�ҵ�һ�����ڵ��ڸ������ȵ�Ԫ�أ�һ���ҵ��Ϳ��Լ�����ж���Ԫ�صĳ��ȴ��ڵ��ڸ���ֵ��
string make_plural(size_t ctr, const string &word, const string &ending);


int main()
{
	<span style = "white-space:pre">	< / span>
		<span style = "white-space:pre">	< / span>vector<string> words;
	<span style = "white-space:pre">	< / span>string val;
	<span style = "white-space:pre">	< / span>cout << "Input the words: ";


	<span style = "white-space:pre">	< / span>while (cin >> val)//��ѭ���������ַ���
		<span style = "white-space:pre">	< / span>{
		<span style = "white-space:pre">		< / span>words.push_back(val);
		<span style = "white-space:pre">	< / span>}
	<span style = "white-space:pre">	< / span>elimDups(words);//���ú���������ɾ��


	<span style = "white-space:pre">	< / span>stable_sort(words.begin(), words.end(), isShorter);
	<span style = "white-space:pre">	< / span>cout << "The output is: ";//�������ɾ��֮��ĵ���
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
	<span style = "white-space:pre">	< / span>sort(words.begin(), words.end());//���ֵ�������
	<span style = "white-space:pre">	< / span>//uinque�������뷶Χ��ʹ��ÿ������ֻ����һ��
		<span style = "white-space:pre">	< / span>//�����ڷ�Χ��ǰ��������ָ���ظ�����֮��һ��λ�õĵ�����
		<span style = "white-space:pre">	< / span>auto end_unique = unique(words.begin(), words.end());
	<span style = "white-space:pre">	< / span>//ʹ����������eraseɾ���ظ�����
		<span style = "white-space:pre">	< / span>words.erase(end_unique, words.end());
}


bool isShorter(const string &s1, const string &s2)
{
	<span style = "white-space:pre">	< / span>return s1.size() < s2.size();
}

void biggies(vector<string> &words,
	<span style = "white-space:pre">	< / span>vector<string>::size_type sz)
{
	<span style = "white-space:pre">	< / span>elimDups(words);//��words����ɾ���ظ��ĵ���
	<span style = "white-space:pre">	< / span>//���������򣬳�����ͬ�ĵ���ά���ֵ���
		<span style = "white-space:pre">	< / span>stable_sort(words.begin(), words.end(),
			<span style = "white-space:pre">				< / span>[](const string &a, const string &b)
			<span style = "white-space:pre">					< / span>{ return a.size() < b.size(); });
	<span style = "white-space:pre">	< / span>//��ȡ��һ����������ָ���һ������size()>=sz��Ԫ��
		<span style = "white-space:pre">	< / span>auto wc = find_if(words.begin(), words.end(),
			<span style = "white-space:pre">				< / span>[sz](const string &a)
			<span style = "white-space:pre">					< / span>{ return a.size() >= sz; });
	<span style = "white-space:pre">	< / span>//��������size>=sz��Ԫ������Ŀ
		<span style = "white-space:pre">	< / span>auto count = words.end() - wc;//��ʱ��words�ǰ�������С�������еġ�
	<span style = "white-space:pre">	< / span>cout << count << " " << make_plural(count, "word", "s")
		<span style = "white-space:pre">		< / span> << " of length " << sz << " or longer" << endl;
	<span style = "white-space:pre">	< / span>//��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�
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