
// preprocessor definition : __has_include,  __has_cpp_attribute
#include "a.h"

#ifdef __has_include
#  if __has_include(<optional>)
#    include <optional>
#    define have_optional 1
#  elif __has_include(<experimental/optional>)
#    include <experimental/optional>
#    define have_optional 1
#    define experimental_optional
#  else
#    define have_optional 0
#  endif
#endif


#ifdef __has_cpp_attribute
#  if __has_cpp_attribute(deprecated)
#    define ATTR_DEPRECATED(msg) [[deprecated(msg)]]
#  else
#    define ATTR_DEPRECATED(msg)
#  endif
#endif