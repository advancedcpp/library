# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/DesktopApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/build-DesktopApp-Desktop-Debug

# Utility rule file for DesktopApp_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/DesktopApp_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DesktopApp_autogen.dir/progress.make

CMakeFiles/DesktopApp_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/build-DesktopApp-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target DesktopApp"
	/usr/local/bin/cmake -E cmake_autogen /home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/build-DesktopApp-Desktop-Debug/CMakeFiles/DesktopApp_autogen.dir/AutogenInfo.json Debug

DesktopApp_autogen: CMakeFiles/DesktopApp_autogen
DesktopApp_autogen: CMakeFiles/DesktopApp_autogen.dir/build.make
.PHONY : DesktopApp_autogen

# Rule to build all files generated by this target.
CMakeFiles/DesktopApp_autogen.dir/build: DesktopApp_autogen
.PHONY : CMakeFiles/DesktopApp_autogen.dir/build

CMakeFiles/DesktopApp_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DesktopApp_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DesktopApp_autogen.dir/clean

CMakeFiles/DesktopApp_autogen.dir/depend:
	cd /home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/build-DesktopApp-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/DesktopApp /home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/DesktopApp /home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/build-DesktopApp-Desktop-Debug /home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/build-DesktopApp-Desktop-Debug /home/a2zproviders/Desktop/cpp/core/projects/DesktopApp/build-DesktopApp-Desktop-Debug/CMakeFiles/DesktopApp_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DesktopApp_autogen.dir/depend

