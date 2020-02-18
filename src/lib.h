#ifndef LIB_H_
#define LIB_H_

#include <limits.h>
#include <string>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

using lib::ENV_SIZE;
using lib::get_exe_path;
using lib::SEP;

namespace lib
{
#ifdef _WIN32 // includes both x32 and x64
const std::string SEP = "\\";
const int ENV_SIZE = 62;
std::string get_exe_path()
{
    char result[MAX_PATH];
    // need to use ansi version (post-pend 'A') otherwise char* incompatible...
    return std::string(result, GetModuleFileNameA(NULL, result, MAX_PATH));
}
#endif

#ifdef __linux__
#include <unistd.h>
const std::string SEP = "/";
// todo test this number
const int ENV_SIZE = 62;
std::string get_exe_path()
{
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    return std::string(result, (count > 0) ? count : 0);
}
#endif

#ifdef __APPLE__
const std::string SEP = "/";
// todo test this number
const int ENV_SIZE = 62;
std::string get_exe_path()
{
    std::cerr << "I have not implemented this method on OSX";
    return "";
}
#endif
} // namespace lib

#endif // LIB_H_