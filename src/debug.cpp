#include "debug.hpp"

namespace lox {
namespace {

std::size_t simpleInstruction(const char* name, std::size_t offset) {
    print("{}\n", name);
    return offset + 1;
}

std::size_t constantInstruction(const char* name, Chunk* chunk, std::size_t offset)
{
    std::uint8_t constant = chunk->code[offset + 1];
    print("{:16} {:4} '{}'\n", name, constant, chunk->constants.values[constant]);
    return offset + 2;
}

}

void disassembleChunk(Chunk* chunk, const char* name)
{
    print("== {} ==\n", name);
    std::size_t offset = 0;
    while (offset < chunk->code.size()) {
        offset = disassembleInstruction(chunk, offset);
    }
}

std::size_t disassembleInstruction(Chunk* chunk, std::size_t offset)
{
    print("{:04} ", offset);
    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
        print("   | ");
    } else {
        print("{:4} ", chunk->lines[offset]);
    }
    std::uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        break; case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        break; case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        break; default:
            print("Unknown op code {}\n", instruction);
            return offset + 1;
    }
}

}