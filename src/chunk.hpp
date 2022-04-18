#pragma once
#include "common.hpp"
#include "value.hpp"

#include <vector>

namespace lox {

enum OpCode
{
    OP_CONSTANT,
    OP_RETURN,
};

struct Chunk
{
    std::vector<std::uint8_t> code;
    std::vector<std::size_t>  lines;
    ValueArray                constants;
};

void writeChunk(Chunk* chunk, std::uint8_t byte, std::size_t line);
int addConstant(Chunk* chunk, Value value);

}