// module : logTime.h
// author : kang seogmin
// date   : 2015.09.06
// email  : smkang@ioacademy.co.kr 
// home   : ioacademy.co.kr
//			cafe.naver.com/cppmaster

// description : ���̿� �������Ϳ��� ���� �ð��� ����ϴ� ��� ���� �Դϴ�
//               ���� ���� : smkang @ ioacademy.co.kr


#ifndef LOG_TIME_H
#define LOG_TIME_H

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#if _MSC_VER < 1900
#error current VC++ version not fully supported C++11/14, please use more than VC++2015 
#endif
#endif


#ifdef __GNUC__
#if    __GNUC__ >= 5 || (__GNUC__ >= 4 && __GNUC_MINOR__ >= 9)
#else
#error current g++ version not fully supported C++11/14, please use more than g++-4.9.2 
#endif
#endif


#include <iostream>
#include <chrono>
#include <string>

class stop_watch
{
	std::string message;
	std::chrono::high_resolution_clock::time_point start;
public:
	inline stop_watch(std::string msg = "") : message(msg) { start = std::chrono::high_resolution_clock::now(); }

	inline ~stop_watch()
	{
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		std::cout << message << " " << time_span.count() << " seconds." << std::endl;;
	}
};

// no message
template<typename F, typename ... Types> inline
decltype(auto) logTime(F func, Types&& ... args)
{
	stop_watch sw;
	return func(std::forward<Types>(args)...);
}

// const char*
template<typename F, typename ... Types> inline
decltype(auto) logTime(const char* msg, F func, Types&& ... args)
{
	stop_watch sw(msg);
	return func(std::forward<Types>(args)...);
}

// string
template<typename F, typename ... Types> inline 
decltype(auto) logTime(std::string msg, F func, Types&& ... args)
{
	stop_watch sw(msg);
	return func(std::forward<Types>(args)...);
}

// �����̳� ����Լ�
template<typename T, typename ... Types> inline 
void show_imp(T& c, Types& ... args)
{
	for (auto& n : c) 
		cout << n << "  ";
	cout << endl;
	show_imp(args...);
}

void show_imp() { }

template<typename ... Types> inline 
void show(Types& ... args) 
{
	show_imp(args...); 
}

#endif // LOG_TIME_H