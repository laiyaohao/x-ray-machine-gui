# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui

# Include any dependencies generated for this target.
include CMakeFiles/x-ray-machine-gui.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/x-ray-machine-gui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/x-ray-machine-gui.dir/flags.make

x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp: resources/resources.qrc
x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp: CMakeFiles/x-ray-machine-gui_autogen.dir/AutoRcc_resources_3YJK5W5UP7_Info.json
x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp: resources/images/open.png
x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp: /usr/lib/qt5/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for resources/resources.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/CMakeFiles/x-ray-machine-gui_autogen.dir/AutoRcc_resources_3YJK5W5UP7_Info.json 

CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.o: CMakeFiles/x-ray-machine-gui.dir/flags.make
CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.o: x-ray-machine-gui_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.o -c /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/x-ray-machine-gui_autogen/mocs_compilation.cpp

CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/x-ray-machine-gui_autogen/mocs_compilation.cpp > CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.i

CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/x-ray-machine-gui_autogen/mocs_compilation.cpp -o CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.s

CMakeFiles/x-ray-machine-gui.dir/main.cpp.o: CMakeFiles/x-ray-machine-gui.dir/flags.make
CMakeFiles/x-ray-machine-gui.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/x-ray-machine-gui.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/x-ray-machine-gui.dir/main.cpp.o -c /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/main.cpp

CMakeFiles/x-ray-machine-gui.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x-ray-machine-gui.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/main.cpp > CMakeFiles/x-ray-machine-gui.dir/main.cpp.i

CMakeFiles/x-ray-machine-gui.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x-ray-machine-gui.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/main.cpp -o CMakeFiles/x-ray-machine-gui.dir/main.cpp.s

CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.o: CMakeFiles/x-ray-machine-gui.dir/flags.make
CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.o: mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.o -c /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/mainwindow.cpp

CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/mainwindow.cpp > CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.i

CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/mainwindow.cpp -o CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.s

CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.o: CMakeFiles/x-ray-machine-gui.dir/flags.make
CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.o: x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.o -c /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp

CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp > CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.i

CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp -o CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.s

# Object files for target x-ray-machine-gui
x__ray__machine__gui_OBJECTS = \
"CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/x-ray-machine-gui.dir/main.cpp.o" \
"CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.o" \
"CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.o"

# External object files for target x-ray-machine-gui
x__ray__machine__gui_EXTERNAL_OBJECTS =

x-ray-machine-gui: CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/mocs_compilation.cpp.o
x-ray-machine-gui: CMakeFiles/x-ray-machine-gui.dir/main.cpp.o
x-ray-machine-gui: CMakeFiles/x-ray-machine-gui.dir/mainwindow.cpp.o
x-ray-machine-gui: CMakeFiles/x-ray-machine-gui.dir/x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp.o
x-ray-machine-gui: CMakeFiles/x-ray-machine-gui.dir/build.make
x-ray-machine-gui: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
x-ray-machine-gui: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
x-ray-machine-gui: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
x-ray-machine-gui: CMakeFiles/x-ray-machine-gui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable x-ray-machine-gui"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/x-ray-machine-gui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/x-ray-machine-gui.dir/build: x-ray-machine-gui

.PHONY : CMakeFiles/x-ray-machine-gui.dir/build

CMakeFiles/x-ray-machine-gui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/x-ray-machine-gui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/x-ray-machine-gui.dir/clean

CMakeFiles/x-ray-machine-gui.dir/depend: x-ray-machine-gui_autogen/3YJK5W5UP7/qrc_resources.cpp
	cd /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui /home/laiyaohao/ME4101A/x-ray-machine-gui/x-ray-machine-gui/CMakeFiles/x-ray-machine-gui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/x-ray-machine-gui.dir/depend
