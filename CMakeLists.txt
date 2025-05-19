cmake_minimum_required(VERSION 3.10)
project(cpp_course)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(add_exercise EXERCISE_NUMBER)
    file(GLOB SOURCES "${EXERCISE_NUMBER}/*.cpp")
    foreach(SOURCE ${SOURCES})
        get_filename_component(EXERCISE_NAME ${SOURCE} NAME_WE)
        add_executable(exercise_${EXERCISE_NUMBER}_${EXERCISE_NAME} ${SOURCE})
    endforeach()
endfunction()

add_exercise(12)
add_exercise(13)
add_exercise(14)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/run.sh.in
    ${CMAKE_CURRENT_BINARY_DIR}/run.sh
    @ONLY
) 