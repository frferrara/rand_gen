cmake_minimum_required( VERSION 2.6 )
project( RandGen )

include_directories( ${PROJECT_SOURCE_DIR} )

include_directories( ${PROJECT_SOURCE_DIR}/rand_gen )
add_subdirectory( rand_gen )

add_executable( ${PROJECT_NAME} main.cpp )

target_link_libraries( ${PROJECT_NAME} rand_gen )