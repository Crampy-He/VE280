# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\p4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\p4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/p4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p4.dir/flags.make

CMakeFiles/p4.dir/main.cpp.obj: CMakeFiles/p4.dir/flags.make
CMakeFiles/p4.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\p4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p4.dir/main.cpp.obj"
	D:\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p4.dir\main.cpp.obj -c G:\p4\main.cpp

CMakeFiles/p4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p4.dir/main.cpp.i"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\p4\main.cpp > CMakeFiles\p4.dir\main.cpp.i

CMakeFiles/p4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p4.dir/main.cpp.s"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\p4\main.cpp -o CMakeFiles\p4.dir\main.cpp.s

CMakeFiles/p4.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/p4.dir/main.cpp.obj.requires

CMakeFiles/p4.dir/main.cpp.obj.provides: CMakeFiles/p4.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\p4.dir\build.make CMakeFiles/p4.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/p4.dir/main.cpp.obj.provides

CMakeFiles/p4.dir/main.cpp.obj.provides.build: CMakeFiles/p4.dir/main.cpp.obj


CMakeFiles/p4.dir/exceptions.cpp.obj: CMakeFiles/p4.dir/flags.make
CMakeFiles/p4.dir/exceptions.cpp.obj: ../exceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\p4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/p4.dir/exceptions.cpp.obj"
	D:\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p4.dir\exceptions.cpp.obj -c G:\p4\exceptions.cpp

CMakeFiles/p4.dir/exceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p4.dir/exceptions.cpp.i"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\p4\exceptions.cpp > CMakeFiles\p4.dir\exceptions.cpp.i

CMakeFiles/p4.dir/exceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p4.dir/exceptions.cpp.s"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\p4\exceptions.cpp -o CMakeFiles\p4.dir\exceptions.cpp.s

CMakeFiles/p4.dir/exceptions.cpp.obj.requires:

.PHONY : CMakeFiles/p4.dir/exceptions.cpp.obj.requires

CMakeFiles/p4.dir/exceptions.cpp.obj.provides: CMakeFiles/p4.dir/exceptions.cpp.obj.requires
	$(MAKE) -f CMakeFiles\p4.dir\build.make CMakeFiles/p4.dir/exceptions.cpp.obj.provides.build
.PHONY : CMakeFiles/p4.dir/exceptions.cpp.obj.provides

CMakeFiles/p4.dir/exceptions.cpp.obj.provides.build: CMakeFiles/p4.dir/exceptions.cpp.obj


CMakeFiles/p4.dir/quarto.cpp.obj: CMakeFiles/p4.dir/flags.make
CMakeFiles/p4.dir/quarto.cpp.obj: ../quarto.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\p4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/p4.dir/quarto.cpp.obj"
	D:\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p4.dir\quarto.cpp.obj -c G:\p4\quarto.cpp

CMakeFiles/p4.dir/quarto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p4.dir/quarto.cpp.i"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\p4\quarto.cpp > CMakeFiles\p4.dir\quarto.cpp.i

CMakeFiles/p4.dir/quarto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p4.dir/quarto.cpp.s"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\p4\quarto.cpp -o CMakeFiles\p4.dir\quarto.cpp.s

CMakeFiles/p4.dir/quarto.cpp.obj.requires:

.PHONY : CMakeFiles/p4.dir/quarto.cpp.obj.requires

CMakeFiles/p4.dir/quarto.cpp.obj.provides: CMakeFiles/p4.dir/quarto.cpp.obj.requires
	$(MAKE) -f CMakeFiles\p4.dir\build.make CMakeFiles/p4.dir/quarto.cpp.obj.provides.build
.PHONY : CMakeFiles/p4.dir/quarto.cpp.obj.provides

CMakeFiles/p4.dir/quarto.cpp.obj.provides.build: CMakeFiles/p4.dir/quarto.cpp.obj


CMakeFiles/p4.dir/piece.cpp.obj: CMakeFiles/p4.dir/flags.make
CMakeFiles/p4.dir/piece.cpp.obj: ../piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\p4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/p4.dir/piece.cpp.obj"
	D:\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p4.dir\piece.cpp.obj -c G:\p4\piece.cpp

CMakeFiles/p4.dir/piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p4.dir/piece.cpp.i"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\p4\piece.cpp > CMakeFiles\p4.dir\piece.cpp.i

CMakeFiles/p4.dir/piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p4.dir/piece.cpp.s"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\p4\piece.cpp -o CMakeFiles\p4.dir\piece.cpp.s

CMakeFiles/p4.dir/piece.cpp.obj.requires:

.PHONY : CMakeFiles/p4.dir/piece.cpp.obj.requires

CMakeFiles/p4.dir/piece.cpp.obj.provides: CMakeFiles/p4.dir/piece.cpp.obj.requires
	$(MAKE) -f CMakeFiles\p4.dir\build.make CMakeFiles/p4.dir/piece.cpp.obj.provides.build
.PHONY : CMakeFiles/p4.dir/piece.cpp.obj.provides

CMakeFiles/p4.dir/piece.cpp.obj.provides.build: CMakeFiles/p4.dir/piece.cpp.obj


CMakeFiles/p4.dir/pool.cpp.obj: CMakeFiles/p4.dir/flags.make
CMakeFiles/p4.dir/pool.cpp.obj: ../pool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\p4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/p4.dir/pool.cpp.obj"
	D:\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p4.dir\pool.cpp.obj -c G:\p4\pool.cpp

CMakeFiles/p4.dir/pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p4.dir/pool.cpp.i"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\p4\pool.cpp > CMakeFiles\p4.dir\pool.cpp.i

CMakeFiles/p4.dir/pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p4.dir/pool.cpp.s"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\p4\pool.cpp -o CMakeFiles\p4.dir\pool.cpp.s

CMakeFiles/p4.dir/pool.cpp.obj.requires:

.PHONY : CMakeFiles/p4.dir/pool.cpp.obj.requires

CMakeFiles/p4.dir/pool.cpp.obj.provides: CMakeFiles/p4.dir/pool.cpp.obj.requires
	$(MAKE) -f CMakeFiles\p4.dir\build.make CMakeFiles/p4.dir/pool.cpp.obj.provides.build
.PHONY : CMakeFiles/p4.dir/pool.cpp.obj.provides

CMakeFiles/p4.dir/pool.cpp.obj.provides.build: CMakeFiles/p4.dir/pool.cpp.obj


CMakeFiles/p4.dir/square.cpp.obj: CMakeFiles/p4.dir/flags.make
CMakeFiles/p4.dir/square.cpp.obj: ../square.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\p4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/p4.dir/square.cpp.obj"
	D:\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p4.dir\square.cpp.obj -c G:\p4\square.cpp

CMakeFiles/p4.dir/square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p4.dir/square.cpp.i"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\p4\square.cpp > CMakeFiles\p4.dir\square.cpp.i

CMakeFiles/p4.dir/square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p4.dir/square.cpp.s"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\p4\square.cpp -o CMakeFiles\p4.dir\square.cpp.s

CMakeFiles/p4.dir/square.cpp.obj.requires:

.PHONY : CMakeFiles/p4.dir/square.cpp.obj.requires

CMakeFiles/p4.dir/square.cpp.obj.provides: CMakeFiles/p4.dir/square.cpp.obj.requires
	$(MAKE) -f CMakeFiles\p4.dir\build.make CMakeFiles/p4.dir/square.cpp.obj.provides.build
.PHONY : CMakeFiles/p4.dir/square.cpp.obj.provides

CMakeFiles/p4.dir/square.cpp.obj.provides.build: CMakeFiles/p4.dir/square.cpp.obj


CMakeFiles/p4.dir/board.cpp.obj: CMakeFiles/p4.dir/flags.make
CMakeFiles/p4.dir/board.cpp.obj: ../board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\p4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/p4.dir/board.cpp.obj"
	D:\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p4.dir\board.cpp.obj -c G:\p4\board.cpp

CMakeFiles/p4.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p4.dir/board.cpp.i"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\p4\board.cpp > CMakeFiles\p4.dir\board.cpp.i

CMakeFiles/p4.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p4.dir/board.cpp.s"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\p4\board.cpp -o CMakeFiles\p4.dir\board.cpp.s

CMakeFiles/p4.dir/board.cpp.obj.requires:

.PHONY : CMakeFiles/p4.dir/board.cpp.obj.requires

CMakeFiles/p4.dir/board.cpp.obj.provides: CMakeFiles/p4.dir/board.cpp.obj.requires
	$(MAKE) -f CMakeFiles\p4.dir\build.make CMakeFiles/p4.dir/board.cpp.obj.provides.build
.PHONY : CMakeFiles/p4.dir/board.cpp.obj.provides

CMakeFiles/p4.dir/board.cpp.obj.provides.build: CMakeFiles/p4.dir/board.cpp.obj


CMakeFiles/p4.dir/player.cpp.obj: CMakeFiles/p4.dir/flags.make
CMakeFiles/p4.dir/player.cpp.obj: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\p4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/p4.dir/player.cpp.obj"
	D:\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p4.dir\player.cpp.obj -c G:\p4\player.cpp

CMakeFiles/p4.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p4.dir/player.cpp.i"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\p4\player.cpp > CMakeFiles\p4.dir\player.cpp.i

CMakeFiles/p4.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p4.dir/player.cpp.s"
	D:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\p4\player.cpp -o CMakeFiles\p4.dir\player.cpp.s

CMakeFiles/p4.dir/player.cpp.obj.requires:

.PHONY : CMakeFiles/p4.dir/player.cpp.obj.requires

CMakeFiles/p4.dir/player.cpp.obj.provides: CMakeFiles/p4.dir/player.cpp.obj.requires
	$(MAKE) -f CMakeFiles\p4.dir\build.make CMakeFiles/p4.dir/player.cpp.obj.provides.build
.PHONY : CMakeFiles/p4.dir/player.cpp.obj.provides

CMakeFiles/p4.dir/player.cpp.obj.provides.build: CMakeFiles/p4.dir/player.cpp.obj


# Object files for target p4
p4_OBJECTS = \
"CMakeFiles/p4.dir/main.cpp.obj" \
"CMakeFiles/p4.dir/exceptions.cpp.obj" \
"CMakeFiles/p4.dir/quarto.cpp.obj" \
"CMakeFiles/p4.dir/piece.cpp.obj" \
"CMakeFiles/p4.dir/pool.cpp.obj" \
"CMakeFiles/p4.dir/square.cpp.obj" \
"CMakeFiles/p4.dir/board.cpp.obj" \
"CMakeFiles/p4.dir/player.cpp.obj"

# External object files for target p4
p4_EXTERNAL_OBJECTS =

p4.exe: CMakeFiles/p4.dir/main.cpp.obj
p4.exe: CMakeFiles/p4.dir/exceptions.cpp.obj
p4.exe: CMakeFiles/p4.dir/quarto.cpp.obj
p4.exe: CMakeFiles/p4.dir/piece.cpp.obj
p4.exe: CMakeFiles/p4.dir/pool.cpp.obj
p4.exe: CMakeFiles/p4.dir/square.cpp.obj
p4.exe: CMakeFiles/p4.dir/board.cpp.obj
p4.exe: CMakeFiles/p4.dir/player.cpp.obj
p4.exe: CMakeFiles/p4.dir/build.make
p4.exe: CMakeFiles/p4.dir/linklibs.rsp
p4.exe: CMakeFiles/p4.dir/objects1.rsp
p4.exe: CMakeFiles/p4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\p4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable p4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\p4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p4.dir/build: p4.exe

.PHONY : CMakeFiles/p4.dir/build

CMakeFiles/p4.dir/requires: CMakeFiles/p4.dir/main.cpp.obj.requires
CMakeFiles/p4.dir/requires: CMakeFiles/p4.dir/exceptions.cpp.obj.requires
CMakeFiles/p4.dir/requires: CMakeFiles/p4.dir/quarto.cpp.obj.requires
CMakeFiles/p4.dir/requires: CMakeFiles/p4.dir/piece.cpp.obj.requires
CMakeFiles/p4.dir/requires: CMakeFiles/p4.dir/pool.cpp.obj.requires
CMakeFiles/p4.dir/requires: CMakeFiles/p4.dir/square.cpp.obj.requires
CMakeFiles/p4.dir/requires: CMakeFiles/p4.dir/board.cpp.obj.requires
CMakeFiles/p4.dir/requires: CMakeFiles/p4.dir/player.cpp.obj.requires

.PHONY : CMakeFiles/p4.dir/requires

CMakeFiles/p4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\p4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/p4.dir/clean

CMakeFiles/p4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\p4 G:\p4 G:\p4\cmake-build-debug G:\p4\cmake-build-debug G:\p4\cmake-build-debug\CMakeFiles\p4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p4.dir/depend

