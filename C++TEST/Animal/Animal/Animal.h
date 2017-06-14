//头文件中增加预编译指令符，防止头文件被重复包含
#ifndef ANIMAL_H_
#define ANIMAL_H_
class Animal
{
public:
	//int weight;
	//int height;
	Animal(	int weight, int height);
	//只要原型声明
	/*{
		this->weight = weight;
		this->height = height;
		//cout << this->weight << this->height <<"Animal Construct!" << endl;
	}

	//简单起见删除析构
	~Animal()
	{
		//cout << "Animal end!" << endl;
	}
*/
	void eat();
	//{
	//	cout << "Animal eat!" << endl;
	//}

	void sleep();
	//{
	//	cout << "Animal sleep!" << endl;
	//}

	//虚函数，采用迟邦定技术。C++多态性
	virtual void breath();// = 0;
	//	{
	//		cout << "Animal breath!" << endl;
	//	}


};

#endif