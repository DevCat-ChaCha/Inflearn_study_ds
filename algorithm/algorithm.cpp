
#include <iostream>
#include <vector>
#include <list>

using namespace std;


// Vector 구현
//template<typename T>
//class VECTOR
//{
//public:
//	VECTOR()
//	{
//
//	}
//
//	~VECTOR()
//	{
//		if (_data)
//		{
//			delete[] _data;
//		}
//	}
//
//	void push_back(const T& value)
//	{
//		if (_size == _capacity)
//		{
//			// 공간 증설
//			int newCapacity = static_cast<int>(_capacity * 1.5);
//			if (newCapacity <= _capacity)
//			{
//				newCapacity++;
//			}
//
//			reserve(newCapacity);
//		}
//
//		// 데이터 저장
//		_data[_size] = value;
//
//		// 데이터 개수 증가
//		_size++;
//	}
//
	//void reserve(int capacity)
	//{
	//	if (_capacity >= capacity)
	//	{
	//		// 증설 필요없음
	//		return;
	//	}

	//	_capacity = capacity;

	//	T* newTempData = new T[_capacity];

	//	// 늘려줬으니 데이터 복사
	//	for (int i = 0; i < _size; i++)
	//	{
	//		newTempData[i] = _data[i];
	//	}

	//	// 삭제
	//	if (_data)
	//	{
	//		delete[] _data;
	//	}

	//	// 교체
	//	_data = newTempData;
	//}


	//T& operatior[](const int pos) { return _data[pos]; }

	//int getSize() { return _size; }
	//int getCapacity() { return _capacity; }

	//void clear()
	//{
	//	if (_data)
	//	{
	//		delete[] _data;
	//		_data = new T[_capacity];
	//	}

	//	_size = 0;
	//}
//
//private:
//	T* _data = nullptr;
//	int _size = 0;
//	int _capacity = 0;
//
//};
//

//int main()
//{
//	vector<int> v;
//
//	for (int i = 0; i < 100; i++)
//	{
//		v.push_back(i);
//		//capacity 는 50%정도의 저장공간을 더 잡아준다
//		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
//	}
//
//	v.clear();
//
//	cout << v.size() << " " << v.capacity() << endl;
//	// capacity 는 그대로 남는다
//}

template<typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}

	Node(const T&(value)) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}

private:
	void*	_prev;
	void*	_next;

	T		_data;

};


template<typename T>
class LIST
{
public:
	LIST() : _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();

		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~LIST()
	{
		while (_size > 0)
		{
			pop_back();
		}

		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{
		addNode(_tail, value);
	}

	void pop_back()
	{
		removeNode(_tail->_prev);
	}

private:
	Node<T>* addNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = before;

		newNode->next = before->_next;
		before->_prev = newNode;

		_size++;

		return newNode;
	}

	Node<T>* removeNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;


	}

	int getSize() { return _size; }

public:

private:
	Node<T>* _head;
	Node<T>* _tail;

	int _size;

};

int main()
{
	std::list<int> list;

	// iterator 구현
	std::list<int>::iterator eraseiter;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseiter = list.insert(list.end(), i);
		}
		else
		{
			list.push_back(i);
		}
	}

	list.pop_back();

	list.erase(eraseiter);


	for (std::list<int>::iterator iter = list.begin(); iter != list.end(); iter++)
	{
		cout << (*iter) << endl;
	}

}