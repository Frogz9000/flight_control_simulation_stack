project(physics_simulator LANGUAGES CXX)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(physics_simulator ${SOURCES})

target_include_directories(physics_simulator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)