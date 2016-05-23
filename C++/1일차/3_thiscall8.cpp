#include <iostream>
#include "ioacademy.h"  // ī�信�� ���� ���� ���� ������ �����ؿ�����
using namespace std;
using namespace ioacademy;
#include <map>
class CWnd; // Ŭ���� ���� ����
map<int, CWnd*> this_map;
// ����. �Ʒ� Ŭ���� �ϼ��ϼ���
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
// �� Ŭ���� ����� �ڵ�
class MyWindow : public CWnd
{
public:
  virtual void OnLButtonDown() { cout << "LBUTTON" << endl; }
  virtual void OnKeyDown()     { cout << "KEYDOWN" << endl; }
};
int main()
{
	MyWindow w;
	w.Create(); // �̼��� �����찡 �����Ǿ�� �մϴ�.
				// ���콺 ��ư�� Ŭ���ϸ� "LBUTTON"�̶�� ��� �Ǿ�� �մϴ�
	IoProcessMessage();
}


