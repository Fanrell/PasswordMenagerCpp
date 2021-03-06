# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fanrell/Project/PasswordMenagerCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fanrell/Project/PasswordMenagerCpp

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/fanrell/Project/PasswordMenagerCpp/CMakeFiles /home/fanrell/Project/PasswordMenagerCpp/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/fanrell/Project/PasswordMenagerCpp/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named PasswordMenager

# Build rule for target.
PasswordMenager: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 PasswordMenager
.PHONY : PasswordMenager

# fast build rule for target.
PasswordMenager/fast:
	$(MAKE) -f CMakeFiles/PasswordMenager.dir/build.make CMakeFiles/PasswordMenager.dir/build
.PHONY : PasswordMenager/fast

#=============================================================================
# Target rules for targets named lib

# Build rule for target.
lib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 lib
.PHONY : lib

# fast build rule for target.
lib/fast:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/build
.PHONY : lib/fast

src/Account.o: src/Account.cc.o

.PHONY : src/Account.o

# target to build an object file
src/Account.cc.o:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/Account.cc.o
.PHONY : src/Account.cc.o

src/Account.i: src/Account.cc.i

.PHONY : src/Account.i

# target to preprocess a source file
src/Account.cc.i:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/Account.cc.i
.PHONY : src/Account.cc.i

src/Account.s: src/Account.cc.s

.PHONY : src/Account.s

# target to generate assembly for a file
src/Account.cc.s:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/Account.cc.s
.PHONY : src/Account.cc.s

src/FileLister.o: src/FileLister.cc.o

.PHONY : src/FileLister.o

# target to build an object file
src/FileLister.cc.o:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/FileLister.cc.o
.PHONY : src/FileLister.cc.o

src/FileLister.i: src/FileLister.cc.i

.PHONY : src/FileLister.i

# target to preprocess a source file
src/FileLister.cc.i:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/FileLister.cc.i
.PHONY : src/FileLister.cc.i

src/FileLister.s: src/FileLister.cc.s

.PHONY : src/FileLister.s

# target to generate assembly for a file
src/FileLister.cc.s:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/FileLister.cc.s
.PHONY : src/FileLister.cc.s

src/Menu.o: src/Menu.cc.o

.PHONY : src/Menu.o

# target to build an object file
src/Menu.cc.o:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/Menu.cc.o
.PHONY : src/Menu.cc.o

src/Menu.i: src/Menu.cc.i

.PHONY : src/Menu.i

# target to preprocess a source file
src/Menu.cc.i:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/Menu.cc.i
.PHONY : src/Menu.cc.i

src/Menu.s: src/Menu.cc.s

.PHONY : src/Menu.s

# target to generate assembly for a file
src/Menu.cc.s:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/Menu.cc.s
.PHONY : src/Menu.cc.s

src/PassList.o: src/PassList.cc.o

.PHONY : src/PassList.o

# target to build an object file
src/PassList.cc.o:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/PassList.cc.o
.PHONY : src/PassList.cc.o

src/PassList.i: src/PassList.cc.i

.PHONY : src/PassList.i

# target to preprocess a source file
src/PassList.cc.i:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/PassList.cc.i
.PHONY : src/PassList.cc.i

src/PassList.s: src/PassList.cc.s

.PHONY : src/PassList.s

# target to generate assembly for a file
src/PassList.cc.s:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/PassList.cc.s
.PHONY : src/PassList.cc.s

src/RSA.o: src/RSA.cc.o

.PHONY : src/RSA.o

# target to build an object file
src/RSA.cc.o:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/RSA.cc.o
.PHONY : src/RSA.cc.o

src/RSA.i: src/RSA.cc.i

.PHONY : src/RSA.i

# target to preprocess a source file
src/RSA.cc.i:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/RSA.cc.i
.PHONY : src/RSA.cc.i

src/RSA.s: src/RSA.cc.s

.PHONY : src/RSA.s

# target to generate assembly for a file
src/RSA.cc.s:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/RSA.cc.s
.PHONY : src/RSA.cc.s

src/main.o: src/main.cc.o

.PHONY : src/main.o

# target to build an object file
src/main.cc.o:
	$(MAKE) -f CMakeFiles/PasswordMenager.dir/build.make CMakeFiles/PasswordMenager.dir/src/main.cc.o
.PHONY : src/main.cc.o

src/main.i: src/main.cc.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cc.i:
	$(MAKE) -f CMakeFiles/PasswordMenager.dir/build.make CMakeFiles/PasswordMenager.dir/src/main.cc.i
.PHONY : src/main.cc.i

src/main.s: src/main.cc.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cc.s:
	$(MAKE) -f CMakeFiles/PasswordMenager.dir/build.make CMakeFiles/PasswordMenager.dir/src/main.cc.s
.PHONY : src/main.cc.s

src/mainWindow.o: src/mainWindow.cc.o

.PHONY : src/mainWindow.o

# target to build an object file
src/mainWindow.cc.o:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/mainWindow.cc.o
.PHONY : src/mainWindow.cc.o

src/mainWindow.i: src/mainWindow.cc.i

.PHONY : src/mainWindow.i

# target to preprocess a source file
src/mainWindow.cc.i:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/mainWindow.cc.i
.PHONY : src/mainWindow.cc.i

src/mainWindow.s: src/mainWindow.cc.s

.PHONY : src/mainWindow.s

# target to generate assembly for a file
src/mainWindow.cc.s:
	$(MAKE) -f CMakeFiles/lib.dir/build.make CMakeFiles/lib.dir/src/mainWindow.cc.s
.PHONY : src/mainWindow.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... PasswordMenager"
	@echo "... lib"
	@echo "... src/Account.o"
	@echo "... src/Account.i"
	@echo "... src/Account.s"
	@echo "... src/FileLister.o"
	@echo "... src/FileLister.i"
	@echo "... src/FileLister.s"
	@echo "... src/Menu.o"
	@echo "... src/Menu.i"
	@echo "... src/Menu.s"
	@echo "... src/PassList.o"
	@echo "... src/PassList.i"
	@echo "... src/PassList.s"
	@echo "... src/RSA.o"
	@echo "... src/RSA.i"
	@echo "... src/RSA.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/mainWindow.o"
	@echo "... src/mainWindow.i"
	@echo "... src/mainWindow.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

