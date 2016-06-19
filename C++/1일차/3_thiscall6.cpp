#include <iostream>
#include "ioacademy.h"  // 카페에서 받은 파일 현재 폴더에 복사해오세요
using namespace std;
using namespace ioacademy;
#include <string>
// 타이머 개념을 클래스화 해 봅시다.
#include <map>
class Clock; // 클래스 전방 선언
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
	// 1. 아래 함수는 static 이어야 하는 이유를 알아야 합니다.
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
	c2.Start(1000); // 1초에 한번씩 이름을 출력해야 합니다.

	IoProcessMessage();
}
