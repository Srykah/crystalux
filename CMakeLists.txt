cmake_minimum_required(VERSION 3.13)
project(crystalux)

set(CMAKE_CXX_STANDARD 17)
set(SFML_PATH D:/prog/cpp/libs/SFML/SFML-2.5.1/release)
set(CMAKE_CXX_FLAGS -mwindows)

add_executable(${PROJECT_NAME}
        main.cpp
        Application.cpp Application.hpp
        GameMode.cpp GameMode.hpp
        Context.hpp
        MainMenu.cpp MainMenu.hpp
        Button.cpp Button.hpp
        StartScreen.cpp StartScreen.hpp
        Connexion.hpp Connexion.cpp
        Tile.cpp Tile.hpp
        PlayScreen.cpp PlayScreen.hpp
        ModeManager.cpp ModeManager.hpp
        Grid.cpp Grid.hpp
        pugixml.cpp pugixml.hpp pugiconfig.hpp
        fonctions.hpp fonctions.inl fonctions.cpp)

target_link_libraries(${PROJECT_NAME}
        optimized ${SFML_PATH}/lib/libfreetype.a
        optimized ${SFML_PATH}/lib/libsfml-graphics.a
        optimized ${SFML_PATH}/lib/libsfml-window.a
        optimized ${SFML_PATH}/lib/libsfml-system.a
        optimized ${SFML_PATH}/lib/libsfml-main.a)
target_include_directories(${PROJECT_NAME} PRIVATE "${SFML_PATH}/include")
