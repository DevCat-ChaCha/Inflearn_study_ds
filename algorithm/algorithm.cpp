
#include <iostream>
#include <vector>
#include <list>

#include <stack>
#include <queue>

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
//
//template<typename T>
//class Node
//{
//public:
//	Node() : _prev(nullptr), _next(nullptr), _data(T())
//	{
//
//	}
//
//	Node(const T&(value)) : _prev(nullptr), _next(nullptr), _data(value)
//	{
//
//	}
//
//private:
//	void*	_prev;
//	void*	_next;
//
//	T		_data;
//
//};
//
//
//template<typename T>
//class LIST
//{
//public:
//	LIST() : _size(0)
//	{
//		_head = new Node<T>();
//		_tail = new Node<T>();
//
//		_head->_next = _tail;
//		_tail->_prev = _head;
//	}
//
//	~LIST()
//	{
//		while (_size > 0)
//		{
//			pop_back();
//		}
//
//		delete _head;
//		delete _tail;
//	}
//
//	void push_back(const T& value)
//	{
//		addNode(_tail, value);
//	}
//
//	void pop_back()
//	{
//		removeNode(_tail->_prev);
//	}
//
//private:
//	Node<T>* addNode(Node<T>* before, const T& value)
//	{
//		Node<T>* newNode = new Node<T>(value);
//		Node<T>* prevNode = before->_prev;
//
//		prevNode->_next = newNode;
//		newNode->_prev = before;
//
//		newNode->next = before->_next;
//		before->_prev = newNode;
//
//		_size++;
//
//		return newNode;
//	}
//
//	Node<T>* removeNode(Node<T>* node)
//	{
//		Node<T>* prevNode = node->_prev;
//		Node<T>* nextNode = node->_next;
//
//		prevNode->_next = nextNode;
//		nextNode->_prev = prevNode;
//
//		delete node;
//
//		_size--;
//
//		return nextNode;
//
//
//	}
//
//	int getSize() { return _size; }
//
//public:
//
//private:
//	Node<T>* _head;
//	Node<T>* _tail;
//
//	int _size;
//
//};

//int main()
//{
//	std::list<int> list;
//
//	// iterator 구현
//	std::list<int>::iterator eraseiter;
//
//	for (int i = 0; i < 10; i++)
//	{
//		if (i == 5)
//		{
//			eraseiter = list.insert(list.end(), i);
//		}
//		else
//		{
//			list.push_back(i);
//		}
//	}
//
//	list.pop_back();
//
//	list.erase(eraseiter);
//
//
//	for (std::list<int>::iterator iter = list.begin(); iter != list.end(); iter++)
//	{
//		cout << (*iter) << endl;
//	}
//
//}

/////////////////////// Graph /////////////////////////

void createGraph_1()
{
	struct vertex
	{
		vector<vertex*> edgeList;
	};

	vector<vertex> v;
	v.resize(6);

	v[0].edgeList.push_back(&v[1]);
	v[0].edgeList.push_back(&v[4]);
	v[1].edgeList.push_back(&v[0]);
	v[1].edgeList.push_back(&v[2]);
	v[1].edgeList.push_back(&v[3]);
	v[3].edgeList.push_back(&v[4]);
	v[5].edgeList.push_back(&v[4]);


	// 1번 정점이 3번 정점을 가리키고 있는가?
	bool isConnected = false;
	for (auto edge : v[1].edgeList)
	{
		if (edge == &v[3])
		{
			isConnected = true;
			break;
		}
	}
}

void createGraph_2()
{
	struct vertex
	{
		vector<vertex*> edgeList;
	};

	vector<vertex> v;
	v.resize(6);

	// 이중벡터..
	vector<vector<int>> adjacent(6);

	//1번과 3번이 이어져있음
	adjacent[0] = { 1,4 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };


	// 1번 정점이 3번 정점을 가리키고 있는가?
	bool isConnected = false;
	for (auto vertex : adjacent[1])
	{
		if (vertex == 3)
		{
			isConnected = true;
			break;
		}
	}

}

void createGraph_3()
{
	struct vertex
	{
		
	};

	vector<vertex> v;
	v.resize(6);

	// 행렬의 느낌으로

	// 메모리 소모가 심하지만, 빠른 접근이 가능
	// 간선이 많을 때 유용
	// adjacent[from][to]

	// 초기화 땐 모든 연결 false로 시작
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));

	adjacent[0][1] = true;
	adjacent[0][4] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	bool isConnected = adjacent[1][3];

	// 간선별 가중치가 있을 때
	// -1 은 연결 x
	vector<vector<int>> adjacent2 =
	{
		vector<int> {-1, 15, -1, -1, 20, -1},
		vector<int> {5, -1, 5, 5, -1, -1},
		vector<int> {-1, -1, -1, -1, -1, -1},
		vector<int> {-1, -1, -1, -1, 10, -1},
		vector<int> {-1, -1, -1, -1, -1, -1},
		vector<int> {-1, -1, -1, -1, 10, -1},
	};

	bool isConnected2 = adjacent2[1][3] > 0;
	int connectedValue = adjacent2[1][3];
}


int main()
{
	createGraph_1();
	createGraph_2();
	createGraph_3();
}