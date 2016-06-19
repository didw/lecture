// attribute 
// C++14 : [[noreturn]], [[carries_dependency]], [[deprecated]], [[deprecate("reason")]]
// C++17 : [[fallthrough]], [[nodiscard]], [[maybe_unused]]

struct [[nodiscard]] error_info{};

error_info& foo() {}

void f()
{
	foo(); // no warning
}
