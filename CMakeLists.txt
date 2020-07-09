cmake_minimum_required(VERSION 3.16)
project(GitProject C)

set(CMAKE_C_STANDARD 99)

add_executable(GitProject main.c cli/Cli.c cli/Cli.h core/Core.c core/Core.h core/FileHelper.c core/FileHelper.h core/Macros.h core/Log.c core/Log.h)