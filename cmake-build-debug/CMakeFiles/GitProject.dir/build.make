# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\GitProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\GitProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GitProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GitProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GitProject.dir/flags.make

CMakeFiles/GitProject.dir/main.c.obj: CMakeFiles/GitProject.dir/flags.make
CMakeFiles/GitProject.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GitProject.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GitProject.dir\main.c.obj   -c D:\GitProject\main.c

CMakeFiles/GitProject.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GitProject.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\GitProject\main.c > CMakeFiles\GitProject.dir\main.c.i

CMakeFiles/GitProject.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GitProject.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\GitProject\main.c -o CMakeFiles\GitProject.dir\main.c.s

CMakeFiles/GitProject.dir/cli/Cli.c.obj: CMakeFiles/GitProject.dir/flags.make
CMakeFiles/GitProject.dir/cli/Cli.c.obj: ../cli/Cli.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GitProject.dir/cli/Cli.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GitProject.dir\cli\Cli.c.obj   -c D:\GitProject\cli\Cli.c

CMakeFiles/GitProject.dir/cli/Cli.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GitProject.dir/cli/Cli.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\GitProject\cli\Cli.c > CMakeFiles\GitProject.dir\cli\Cli.c.i

CMakeFiles/GitProject.dir/cli/Cli.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GitProject.dir/cli/Cli.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\GitProject\cli\Cli.c -o CMakeFiles\GitProject.dir\cli\Cli.c.s

CMakeFiles/GitProject.dir/core/Core.c.obj: CMakeFiles/GitProject.dir/flags.make
CMakeFiles/GitProject.dir/core/Core.c.obj: ../core/Core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/GitProject.dir/core/Core.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GitProject.dir\core\Core.c.obj   -c D:\GitProject\core\Core.c

CMakeFiles/GitProject.dir/core/Core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GitProject.dir/core/Core.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\GitProject\core\Core.c > CMakeFiles\GitProject.dir\core\Core.c.i

CMakeFiles/GitProject.dir/core/Core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GitProject.dir/core/Core.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\GitProject\core\Core.c -o CMakeFiles\GitProject.dir\core\Core.c.s

CMakeFiles/GitProject.dir/core/FileHelper.c.obj: CMakeFiles/GitProject.dir/flags.make
CMakeFiles/GitProject.dir/core/FileHelper.c.obj: ../core/FileHelper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/GitProject.dir/core/FileHelper.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GitProject.dir\core\FileHelper.c.obj   -c D:\GitProject\core\FileHelper.c

CMakeFiles/GitProject.dir/core/FileHelper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GitProject.dir/core/FileHelper.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\GitProject\core\FileHelper.c > CMakeFiles\GitProject.dir\core\FileHelper.c.i

CMakeFiles/GitProject.dir/core/FileHelper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GitProject.dir/core/FileHelper.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\GitProject\core\FileHelper.c -o CMakeFiles\GitProject.dir\core\FileHelper.c.s

CMakeFiles/GitProject.dir/core/Log.c.obj: CMakeFiles/GitProject.dir/flags.make
CMakeFiles/GitProject.dir/core/Log.c.obj: ../core/Log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/GitProject.dir/core/Log.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GitProject.dir\core\Log.c.obj   -c D:\GitProject\core\Log.c

CMakeFiles/GitProject.dir/core/Log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GitProject.dir/core/Log.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\GitProject\core\Log.c > CMakeFiles\GitProject.dir\core\Log.c.i

CMakeFiles/GitProject.dir/core/Log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GitProject.dir/core/Log.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\GitProject\core\Log.c -o CMakeFiles\GitProject.dir\core\Log.c.s

CMakeFiles/GitProject.dir/core/Change.c.obj: CMakeFiles/GitProject.dir/flags.make
CMakeFiles/GitProject.dir/core/Change.c.obj: ../core/Change.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/GitProject.dir/core/Change.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GitProject.dir\core\Change.c.obj   -c D:\GitProject\core\Change.c

CMakeFiles/GitProject.dir/core/Change.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GitProject.dir/core/Change.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\GitProject\core\Change.c > CMakeFiles\GitProject.dir\core\Change.c.i

CMakeFiles/GitProject.dir/core/Change.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GitProject.dir/core/Change.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\GitProject\core\Change.c -o CMakeFiles\GitProject.dir\core\Change.c.s

# Object files for target GitProject
GitProject_OBJECTS = \
"CMakeFiles/GitProject.dir/main.c.obj" \
"CMakeFiles/GitProject.dir/cli/Cli.c.obj" \
"CMakeFiles/GitProject.dir/core/Core.c.obj" \
"CMakeFiles/GitProject.dir/core/FileHelper.c.obj" \
"CMakeFiles/GitProject.dir/core/Log.c.obj" \
"CMakeFiles/GitProject.dir/core/Change.c.obj"

# External object files for target GitProject
GitProject_EXTERNAL_OBJECTS =

GitProject.exe: CMakeFiles/GitProject.dir/main.c.obj
GitProject.exe: CMakeFiles/GitProject.dir/cli/Cli.c.obj
GitProject.exe: CMakeFiles/GitProject.dir/core/Core.c.obj
GitProject.exe: CMakeFiles/GitProject.dir/core/FileHelper.c.obj
GitProject.exe: CMakeFiles/GitProject.dir/core/Log.c.obj
GitProject.exe: CMakeFiles/GitProject.dir/core/Change.c.obj
GitProject.exe: CMakeFiles/GitProject.dir/build.make
GitProject.exe: CMakeFiles/GitProject.dir/linklibs.rsp
GitProject.exe: CMakeFiles/GitProject.dir/objects1.rsp
GitProject.exe: CMakeFiles/GitProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\GitProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable GitProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GitProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GitProject.dir/build: GitProject.exe

.PHONY : CMakeFiles/GitProject.dir/build

CMakeFiles/GitProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GitProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GitProject.dir/clean

CMakeFiles/GitProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\GitProject D:\GitProject D:\GitProject\cmake-build-debug D:\GitProject\cmake-build-debug D:\GitProject\cmake-build-debug\CMakeFiles\GitProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GitProject.dir/depend

