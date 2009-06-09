include_directories(../libprojekt/src/rational)
link_directories(../libprojekt)
add_executable(appl main.cpp)
target_link_libraries(appl rational)
