// 1_new5
#include <iostream>
#include <vector>
using namespace std;


// STL�� vector�� ������ ���ô�.
int main()
{
	vector<int> v(10, 0); // 10���� 0���� �ʱ�ȭ

	v.resize(7); // �� ������ �˰����� �����غ��ô�.

	cout << v.size()     << endl; // 7
	cout << v.capacity() << endl; // 10

	v.push_back(0); // ���� �ϳ� �߰�

	cout << v.size() << endl;     // 8
	cout << v.capacity() << endl; // 10

	v.shrink_to_fit(); // �ʿ���� �޸� �����ش޶�

	cout << v.size() << endl;     // 8
	cout << v.capacity() << endl; // 8

	//-----------------------
	// DBConnect ��ü�� �����ڿ��� DB�� �����Ѵٰ� �����մϴ�.

	vector<DBConnect> v2(10); 

	v2.resize(7); // �پ�� 3���� ��ü�� �޸𸮿� ��� �ֽ��ϴ�.
				  // ������ �Ҹ��ڸ� ȣ���ؼ� DB�� �ݾƾ� �մϴ�.
				  // �Ҹ����� ����� ȣ���� �ʿ��ϰ� �˴ϴ�.

	v2.resize(8); // �þ �Ѱ��� ��ü�� ���� �޸� ������ �̹� �ֽ��ϴ�.
				  // ������ �����ڸ� ȣ���ؼ� DB�� �ٽ� �����ؾ� �մϴ�.
				  // �������� ����� ȣ���� �ʿ��մϴ�.
}




