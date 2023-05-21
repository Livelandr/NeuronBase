# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("NeuronBase")

add_library(neuronbase "src/functions.cpp" "src/neuron.cpp" "include/functions.h" "include/neuron.h" )
target_include_directories(neuronbase PUBLIC "include")
