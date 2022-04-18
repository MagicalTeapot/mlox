#include "common.hpp"
#include "chunk.hpp"
#include "debug.hpp"

int main(const int argc, const char* argv[])
{
    using namespace lox;
    Chunk chunk;

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk");
    return 0;
}