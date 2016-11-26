cmake_minimum_required(VERSION 3.4)
set (CMAKE_CXX_STANDARD 11)
project(wow_game)
set(SOURCE_EXE controller.cpp finite_automata.cpp joker.cpp matrix_generator.cpp matrix_processor.cpp model.cpp view.cpp WoWgame.cpp)
set(TESTS_EXE controller.cpp finite_automata.cpp joker.cpp matrix_generator.cpp matrix_processor.cpp model.cpp view.cpp tests.cpp)

add_executable(wow ${SOURCE_EXE})
add_executable(tests ${TESTS_EXE})

enable_testing()
add_test(Game_components tests)