cmake_minimum_required(VERSION 3.10)

project(CurrencyConverter)


add_executable(CurrencyConverter ./main.cpp)

find_package(ZLIB REQUIRED)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)
set_property(TARGET CurrencyConverter PROPERTY CXX_STANDARD 17)
set_property(TARGET CurrencyConverter PROPERTY CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:Console /std c++17") 
find_package(argh CONFIG REQUIRED)
target_link_libraries(CurrencyConverter PRIVATE argh)

find_package(cpr CONFIG REQUIRED)
target_link_libraries(CurrencyConverter PRIVATE cpr::cpr)
find_package(tabulate CONFIG REQUIRED)
target_link_libraries(CurrencyConverter PRIVATE tabulate::tabulate)