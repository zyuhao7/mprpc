# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/myh/mprpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/myh/mprpc/build

# Include any dependencies generated for this target.
include example/callee/CMakeFiles/provider.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include example/callee/CMakeFiles/provider.dir/compiler_depend.make

# Include the progress variables for this target.
include example/callee/CMakeFiles/provider.dir/progress.make

# Include the compile flags for this target's objects.
include example/callee/CMakeFiles/provider.dir/flags.make

example/callee/CMakeFiles/provider.dir/userservice.cc.o: example/callee/CMakeFiles/provider.dir/flags.make
example/callee/CMakeFiles/provider.dir/userservice.cc.o: /home/myh/mprpc/example/callee/userservice.cc
example/callee/CMakeFiles/provider.dir/userservice.cc.o: example/callee/CMakeFiles/provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/myh/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/callee/CMakeFiles/provider.dir/userservice.cc.o"
	cd /home/myh/mprpc/build/example/callee && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/callee/CMakeFiles/provider.dir/userservice.cc.o -MF CMakeFiles/provider.dir/userservice.cc.o.d -o CMakeFiles/provider.dir/userservice.cc.o -c /home/myh/mprpc/example/callee/userservice.cc

example/callee/CMakeFiles/provider.dir/userservice.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/provider.dir/userservice.cc.i"
	cd /home/myh/mprpc/build/example/callee && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myh/mprpc/example/callee/userservice.cc > CMakeFiles/provider.dir/userservice.cc.i

example/callee/CMakeFiles/provider.dir/userservice.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/provider.dir/userservice.cc.s"
	cd /home/myh/mprpc/build/example/callee && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myh/mprpc/example/callee/userservice.cc -o CMakeFiles/provider.dir/userservice.cc.s

example/callee/CMakeFiles/provider.dir/__/user.pb.cc.o: example/callee/CMakeFiles/provider.dir/flags.make
example/callee/CMakeFiles/provider.dir/__/user.pb.cc.o: /home/myh/mprpc/example/user.pb.cc
example/callee/CMakeFiles/provider.dir/__/user.pb.cc.o: example/callee/CMakeFiles/provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/myh/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object example/callee/CMakeFiles/provider.dir/__/user.pb.cc.o"
	cd /home/myh/mprpc/build/example/callee && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/callee/CMakeFiles/provider.dir/__/user.pb.cc.o -MF CMakeFiles/provider.dir/__/user.pb.cc.o.d -o CMakeFiles/provider.dir/__/user.pb.cc.o -c /home/myh/mprpc/example/user.pb.cc

example/callee/CMakeFiles/provider.dir/__/user.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/provider.dir/__/user.pb.cc.i"
	cd /home/myh/mprpc/build/example/callee && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myh/mprpc/example/user.pb.cc > CMakeFiles/provider.dir/__/user.pb.cc.i

example/callee/CMakeFiles/provider.dir/__/user.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/provider.dir/__/user.pb.cc.s"
	cd /home/myh/mprpc/build/example/callee && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myh/mprpc/example/user.pb.cc -o CMakeFiles/provider.dir/__/user.pb.cc.s

# Object files for target provider
provider_OBJECTS = \
"CMakeFiles/provider.dir/userservice.cc.o" \
"CMakeFiles/provider.dir/__/user.pb.cc.o"

# External object files for target provider
provider_EXTERNAL_OBJECTS =

/home/myh/mprpc/bin/provider: example/callee/CMakeFiles/provider.dir/userservice.cc.o
/home/myh/mprpc/bin/provider: example/callee/CMakeFiles/provider.dir/__/user.pb.cc.o
/home/myh/mprpc/bin/provider: example/callee/CMakeFiles/provider.dir/build.make
/home/myh/mprpc/bin/provider: /home/myh/mprpc/lib/libmprpc.so
/home/myh/mprpc/bin/provider: example/callee/CMakeFiles/provider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/myh/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/myh/mprpc/bin/provider"
	cd /home/myh/mprpc/build/example/callee && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/provider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/callee/CMakeFiles/provider.dir/build: /home/myh/mprpc/bin/provider
.PHONY : example/callee/CMakeFiles/provider.dir/build

example/callee/CMakeFiles/provider.dir/clean:
	cd /home/myh/mprpc/build/example/callee && $(CMAKE_COMMAND) -P CMakeFiles/provider.dir/cmake_clean.cmake
.PHONY : example/callee/CMakeFiles/provider.dir/clean

example/callee/CMakeFiles/provider.dir/depend:
	cd /home/myh/mprpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/myh/mprpc /home/myh/mprpc/example/callee /home/myh/mprpc/build /home/myh/mprpc/build/example/callee /home/myh/mprpc/build/example/callee/CMakeFiles/provider.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : example/callee/CMakeFiles/provider.dir/depend
