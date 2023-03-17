#pragma once
#ifndef STUDENTLIB_H
#define STUDENTLIB_H

#include <iostream>
#include <cstdlib> 
#include <time.h> 
#include <cctype> 
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdio> 
#include <stdexcept>
#include <cstring>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

using std::cout;
using std::cerr;
using std::cin;
using std::all_of;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::isalpha;
using std::copy;
using std::sort;
using std::fixed;
using std::to_string; 
using std::setfill; 
using std::remove;
using std::isdigit;
using std::swap; 
using std::string;
using std::vector;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::streamsize;
using std::numeric_limits;
using std::ifstream;
using std::ofstream;  
using std::runtime_error;
using std::bad_alloc;
using std::bad_cast;
using std::bad_typeid;
using std::bad_exception;
using std::runtime_error;
using std::domain_error;
using std::invalid_argument;
using std::length_error;
using std::out_of_range;
using std::overflow_error;
using std::range_error;
using std::underflow_error;
using std::exception;
using std::stringstream;

#ifndef S_ISREG
#define S_ISREG(mode) (((mode) & S_IFMT) == S_IFREG)
#endif

#ifdef _WIN32
#include <io.h> 
#define access    _access_s
#else
#include <unistd.h>
#endif

#endif
