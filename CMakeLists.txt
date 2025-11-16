cmake_minimum_required(VERSION 3.15)
project(FTXUIDemo CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Encontra o FTXUI instalado pelo Conan
find_package(ftxui REQUIRED CONFIG)

# Cria o executável
add_executable(ftxui_demo main.cpp)

# Linka as bibliotecas do FTXUI
target_link_libraries(ftxui_demo PRIVATE ftxui::screen ftxui::dom
                                         ftxui::component)
