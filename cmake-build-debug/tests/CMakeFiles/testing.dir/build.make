# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/sirze/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sirze/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug"

# Include any dependencies generated for this target.
include tests/CMakeFiles/testing.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/testing.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/testing.dir/flags.make

tests/CMakeFiles/testing.dir/date_test.cpp.o: tests/CMakeFiles/testing.dir/flags.make
tests/CMakeFiles/testing.dir/date_test.cpp.o: ../tests/date_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/testing.dir/date_test.cpp.o"
	cd "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug/tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testing.dir/date_test.cpp.o -c "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/tests/date_test.cpp"

tests/CMakeFiles/testing.dir/date_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing.dir/date_test.cpp.i"
	cd "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/tests/date_test.cpp" > CMakeFiles/testing.dir/date_test.cpp.i

tests/CMakeFiles/testing.dir/date_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing.dir/date_test.cpp.s"
	cd "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/tests/date_test.cpp" -o CMakeFiles/testing.dir/date_test.cpp.s

# Object files for target testing
testing_OBJECTS = \
"CMakeFiles/testing.dir/date_test.cpp.o"

# External object files for target testing
testing_EXTERNAL_OBJECTS =

tests/testing: tests/CMakeFiles/testing.dir/date_test.cpp.o
tests/testing: tests/CMakeFiles/testing.dir/build.make
tests/testing: lib/libgtest_maind.a
tests/testing: src/libProjeto_AEDA_1_HouseMasterlib.a
tests/testing: lib/libgtestd.a
tests/testing: tests/CMakeFiles/testing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testing"
	cd "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/testing.dir/build: tests/testing

.PHONY : tests/CMakeFiles/testing.dir/build

tests/CMakeFiles/testing.dir/clean:
	cd "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug/tests" && $(CMAKE_COMMAND) -P CMakeFiles/testing.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/testing.dir/clean

tests/CMakeFiles/testing.dir/depend:
	cd "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster" "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/tests" "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug" "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug/tests" "/home/sirze/Área de Trabalho/Universidade/1º Semestre/AEDA/Projeto_AEDA_1_HouseMaster/cmake-build-debug/tests/CMakeFiles/testing.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/testing.dir/depend
