#include <iostream>
#include "ioacademy.h"  // 카페에서 받은 파일 현재 폴더에 복사해오세요
using namespace std;
using namespace ioacademy;
#include <map>
class CWnd; // 클래스 전방 선언
map<int, CWnd*> this_map;
// 숙제. 아래 클래스 완성하세요
class CWnd
{
public:
	void Create() {
    int id = IoMakeWindow(foo);
    this_map[id] = this;
  }

  static int foo(int h, int msg, int a, int b)
  {
    CWnd* pThis = this_map[h];
    switch (msg)
    {
    case WM_LBUTTONDOWN: pThis->OnLButtonDown(); break;
    case WM_KEYDOWN:     pThis->OnKeyDown(); break;
    }
    return 0;
  }
	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}
};
// 위 클래스 사용자 코드
class MyWindow : public CWnd
{
public:
  virtual void OnLButtonDown() { cout << "LBUTTON" << endl; }
  virtual void OnKeyDown()     { cout << "KEYDOWN" << endl; }
};
int main()
{
	MyWindow w;
	w.Create(); // 이순간 윈도우가 생성되어야 합니다.
				// 마우스 버튼을 클릭하면 "LBUTTON"이라고 출력 되어야 합니다
	IoProcessMessage();
}


