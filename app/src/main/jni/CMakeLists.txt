cmake_minimum_required(VERSION 3.6.0-rc2)
add_library( ccalljava  SHARED CCallJava.c ) 

find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

#生成链接动态库
target_link_libraries( ccalljava ${log-lib} )

