#include <iostream>
#include "ioacademy.h"  // ī�信�� ���� ���� ���� ������ �����ؿ�����
using namespace std;
using namespace ioacademy;
#include <string>
// Ÿ�̸� ������ Ŭ����ȭ �� ���ô�.
#include <map>
class Clock; // Ŭ���� ���� ����
map<int, Clock*> this_map;

class Clock
{
	string name;
public:
	Clock(string s) : name(s) {}

	void Start(int ms) 
	{
		int id = IoSetTimer(ms, timerRoutine);

		this_map[id] = this;
	}
	// 1. �Ʒ� �Լ��� static �̾�� �ϴ� ������ �˾ƾ� �մϴ�.
	// 2.
	static void timerRoutine(int id)
	{
		//	cout << name << endl;  // ?
		Clock* pThis = this_map[id];
		cout << pThis->name << endl;
	}
};

int main()
{
	Clock c1("A");
	Clock c2("B");
	c1.Start(500);
	c2.Start(1000); // 1�ʿ� �ѹ��� �̸��� ����ؾ� �մϴ�.

	IoProcessMessage();
}
