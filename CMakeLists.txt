cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

set(PROJECT_NAME cryptographyLab4)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/main.cpp
	src/core/Application/Application.cpp
	src/core/Application/Application.hpp
	src/core/Generator/Generator.cpp
	src/core/Generator/Generator.hpp
	src/core/LinearCongruentialGenerator/LinearCongruentialGenerator.hpp
	src/core/LinearCongruentialGenerator/LinearCongruentialGenerator.cpp
	src/core/LinearFeedbackShiftRegister/LinearFeedbackShiftRegister.hpp
	src/core/LinearFeedbackShiftRegister/LinearFeedbackShiftRegister.cpp
	src/core/Utils/Utils.hpp
	src/core/Utils/Utils.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})