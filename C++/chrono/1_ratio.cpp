#include <iostream>
#include <ratio>
using namespace std;

template<typename T> void p()
{
	cout << T::num << ", " << T::den << endl;
}

void p(true_type)  { cout << "true" << endl; }
void p(false_type) { cout << "false" << endl; }

int main()
{
	ratio<1, 10> r1; // 1/10
	ratio<2, 10> r2; // 2/10 => 1/5

	p<ratio<2, 10>>();
	
	// ration 연산
	p<ratio_add<     ratio<1, 10>, ratio<3, 10>>>();
	p<ratio_subtract<ratio<1, 10>, ratio<3, 10>>>();
	p<ratio_multiply<ratio<1, 10>, ratio<3, 10>>>();

	// ratio 비교
	p(ratio_equal<ratio<2, 10>, ratio<1, 5>>());
	p(ratio_less <ratio<3, 10>, ratio<1, 5>>());

	// convenience typedefs
	p<nano>();
	p<milli>();
	p<centi>();
	p<kilo>();
	p<mega>();
}

namespace std {

	//class template ratio
	template <intmax_t N, intmax_t D = 1>
	class ratio {
	public:
		typedef ratio<num, den> type;
		static constexpr intmax_t num;
		static constexpr intmax_t den;
	};


	// ratio arithmetic            
	template <class R1, class   R2> using   ratio_add = /*ratio*/;
	template <class R1, class   R2> using   ratio_subtract = /*ratio*/;
	template <class R1, class   R2> using   ratio_multiply = /*ratio*/;
	template <class R1, class   R2> using   ratio_divide = /*ratio*/;

	// ratio comparison            
	template <class R1, class R2> struct ratio_equal;
	template <class R1, class R2> struct ratio_not_equal;
	template <class R1, class R2> struct ratio_less;
	template <class R1, class R2> struct ratio_less_equal;
	template <class R1, class R2> struct ratio_greater;
	template <class R1, class R2> struct ratio_greater_equal;

	// convenience SI typedefs         
	typedef ratio<1, 1000000000000000000000000> yocto;
	typedef ratio<1, 1000000000000000000000> zepto;
	typedef ratio<1, 1000000000000000000> atto;
	typedef ratio<1, 1000000000000000> femto;
	typedef ratio<1, 1000000000000> pico;
	typedef ratio<1, 1000000000> nano;
	typedef ratio<1, 1000000> micro;
	typedef ratio<1, 1000> milli;
	typedef ratio<1, 100> centi;
	typedef ratio<1, 10> deci;
	typedef ratio<10, 1> deca;
	typedef ratio<100, 1> hecto;
	typedef ratio<1000, 1> kilo;
	typedef ratio<1000000, 1> mega;
	typedef ratio<1000000000, 1> giga;
	typedef ratio<1000000000000, 1> tera;
	typedef ratio<1000000000000000, 1> peta;
	typedef ratio<1000000000000000000, 1> exa;
	typedef ratio<1000000000000000000000, 1> zetta;
	typedef ratio<1000000000000000000000000, 1> yotta;

}
