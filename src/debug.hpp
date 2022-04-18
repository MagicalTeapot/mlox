#pragma once
#include "chunk.hpp"

namespace lox {

void disassembleChunk(Chunk* chunk, const char* name);
std::size_t disassembleInstruction(Chunk* chunk, std::size_t offset);

}