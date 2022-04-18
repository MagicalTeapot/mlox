#pragma once
#include <cstddef>
#include <cstdint>
#include <format>
#include <iostream>

namespace lox {

template <typename... Args>
void print(std::string_view msg, Args&&... args)
{
    std::cout << std::format(msg, std::forward<Args>(args)...);
}

}