project(ROCKET_SIM LANGUAGES CXX)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(ROCKET_SIM ${SOURCES})

target_include_directories(ROCKET_SIM PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)