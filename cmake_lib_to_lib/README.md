# cmake lib to lib
See: https://stackoverflow.com/questions/58004057/undefined-reference-to-in-cmake-lib-to-lib?noredirect=1#comment102417211_58004057

In main CMakeLists.txt:

target_link_libraries(${PROJECT_NAME} Qt5::Widgets lib2 lib1)

Or in lib2 CMakeList.txt:
target_link_libraries(${PROJECT_NAME} lib1)

Or in main.cpp:
cmake auto-linked lib1 and lib2
auto m1 = new MyClass1;
