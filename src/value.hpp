#pragma once
#include "common.hpp"

#include <vector>

namespace lox {

using Value = double;

struct ValueArray
{
    std::vector<Value> values;
};

void writeValue(ValueArray* array, Value value);

}