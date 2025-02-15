# CMakeList.txt : CMake project for DFS_Project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

cmake_policy(SET CMP0091 NEW) # Enable MSVC runtime selection
set(CMAKE_CSharp_COMPILER "C:/Program Files/dotnet/dotnet.exe")
# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

project ("DFS_Project")
enable_language(CXX)
enable_language(CSharp)

# Add subdirectories for each component
add_subdirectory(src/backend/function1)
add_subdirectory(src/backend/function2)

# Define C# frontend directory
set(FRONTEND_DIR ${CMAKE_SOURCE_DIR}/src/frontend)

# Create a CMake target to build the C# WPF project
add_custom_target(frontend
    COMMAND dotnet build ${FRONTEND_DIR} --configuration Debug
    WORKING_DIRECTORY ${FRONTEND_DIR}
    COMMENT "Building WPF frontend..."
)

# Ensure backend DLLs are copied to the frontend output directory
add_custom_command(TARGET frontend POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/bin/function1.dll
        ${FRONTEND_DIR}/bin/Debug/net8.0-windows/
    COMMENT "Copying function1.dll to frontend output..."
)

# Ensure backend DLLs are copied to the frontend output directory
add_custom_command(TARGET frontend POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/bin/function1.dll
        ${FRONTEND_DIR}/bin/Debug/net8.0-windows/
    COMMENT "Copying function1.dll to frontend output..."
)

# Ensure the frontend is built when running `cmake --build`
add_dependencies(frontend function1 function2)