//ͷ�ļ�������Ԥ����ָ�������ֹͷ�ļ����ظ�����
#ifndef ANIMAL_H_
#define ANIMAL_H_
class Animal
{
public:
	//int weight;
	//int height;
	Animal(	int weight, int height);
	//ֻҪԭ������
	/*{
		this->weight = weight;
		this->height = height;
		//cout << this->weight << this->height <<"Animal Construct!" << endl;
	}

	//�����ɾ������
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

	//�麯�������óٰ������C++��̬��
	virtual void breath();// = 0;
	//	{
	//		cout << "Animal breath!" << endl;
	//	}


};

#endif