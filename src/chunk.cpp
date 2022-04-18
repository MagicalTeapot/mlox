#include "chunk.hpp"

namespace lox {

void writeChunk(Chunk* chunk, std::uint8_t byte, std::size_t line)
{
    chunk->code.push_back(byte);
    chunk->lines.push_back(line);
}

int addConstant(Chunk* chunk, Value value)
{
    writeValue(&chunk->constants, value);
    return std::ssize(chunk->constants.values) - 1;
}

}