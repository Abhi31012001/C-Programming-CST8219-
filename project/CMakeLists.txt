# CMakeList.txt : CMake project for project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("project")

# Add source to this project's executable.
add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
add_definitions(-DNANA_ENABLE_AUDIO)
add_executable (project "project.cpp" "project.h")

target_include_directories( project PUBLIC "C:\\Users\\abhip\\source\\repos\\nana\\include"	)
target_link_directories(project PUBLIC "C:\\Users\\abhip\\source\\repos\\nana\\build\\bin")
target_link_libraries(project "nana_v142_Debug_x64")


# TODO: Add tests and install targets if needed.
