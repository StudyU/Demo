#include <iostream>
#include <vector>
#include <algorithm>
//main1
#include <string>

//main2
#include <functional>
#include <iterator>

using namespace std;

// 最后输入非数字非空字符以结束
int main()
{
	istream_iterator<int> input(cin);
	istream_iterator<int> end_of_stream;

	vector<int> vec;
	copy(input, end_of_stream, inserter(vec, vec.begin()));

	// 降序
	sort(vec.begin(), vec.end(), greater<int>());

	ostream_iterator<int> output(cout, " ");
	unique_copy(vec.begin(), vec.end(), output);

	return 0;
}

int main1()
{
	vector<string> sentence;
	sentence.reserve(5);

	sentence.push_back("Hello,");
	sentence.push_back("how");
	sentence.push_back("are");
	sentence.push_back("you");
	sentence.push_back("?");
	
	//往cout里输出从begin到end，每个元素后加一个“ ”
	copy (sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));
	cout <<endl;
	cout << " max_size() : " << sentence.max_size() << endl;
	cout << " size() : " << sentence.size() << endl;
	cout << " capacity() : " << sentence.capacity() << endl;

	swap (sentence[1], sentence[3]);
	sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");
	sentence.back() = "!";

	copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	cout << " max_size() : " << sentence.max_size() << endl;
	cout << " size() : " << sentence.size() << endl;
	cout << " capacity() : " << sentence.capacity() << endl;

	vector<char> v(10);
	strcpy(&v[0], "HELLO");

	printf("%s\n", &v[0]);
	printf("%s\n", v.begin()); //ERROR(might work,but not portable)

	return 0;
}
