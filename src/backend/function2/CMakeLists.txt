# src/function2/CMakeLists.txt
add_library(function2 SHARED function2.cpp)

# Include directories if needed
target_include_directories(function2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
