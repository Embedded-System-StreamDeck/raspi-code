cmake_minimum_required(VERSION 3.10)
project(ClientSideRaspi)

set(CMAKE_CXX_STANDARD 14)

# Qt meta-object compiler otomasyonu
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ARM64 ve eski kütüphaneler için özel ayarlar
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
    message(STATUS "Targeting ARM64 (aarch64)")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv8-a")
endif()

# Qt ve diğer bağımlılıkların eski sürümlerini hedefle
find_package(Qt5 COMPONENTS Core Gui Widgets Network Qml Quick REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

# Sadece QML dosyalarını ekle
qt5_add_resources(QML_RESOURCES qml.qrc)

add_executable(ClientSideRaspi ${SOURCES} ${QML_RESOURCES})

target_link_libraries(ClientSideRaspi Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network Qt5::Qml Qt5::Quick)
