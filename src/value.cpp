#include "value.hpp"

namespace lox {

void writeValue(ValueArray* array, Value value)
{
    array->values.push_back(value);
}

}