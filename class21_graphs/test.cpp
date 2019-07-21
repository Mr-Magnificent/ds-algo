#include<iostream>
#include<queue>
using namespace std;

class test{
	public:
	int first;
	int second;

	test(int first, int second){
		this->first = first;
		this->second = second;
	}

	bool operator<(const test& other) const{
		return this->first > other.first;
	}


};

int main(int argc, char** argv){
	priority_queue<test> pq;

	pq.push(test(10, 20));
	pq.push(test(30, 40));

	while(pq.size() > 0)
	{
		test t = pq.top();
		pq.pop();
		cout << t.first << " " << t.second << endl;
	}
}
