cmake_minimum_required(VERSION 3.14)

project(MessagingSystem LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)

add_library(MessagingSystem STATIC
  include/AbstractMessage.h
  include/GetHistoryMessage.h
  include/GetHistoryResponseMessage.h
  include/MessageType.h
  include/NotificationMessage.h
  include/NotificationType.h
  include/Result.h
  include/SendMessageMessage.h
  include/SendMessageResponseMessage.h
  include/SimpleMessage.h
  src/AbstractMessage.cpp
  src/GetHistoryMessage.cpp
  src/GetHistoryResponseMessage.cpp
  src/MessageType.cpp
  src/NotificationMessage.cpp
  src/NotificationType.cpp
  src/SendMessageMessage.cpp
  src/SendMessageResponseMessage.cpp
  src/SimpleMessage.cpp
  src/Result.cpp
  src/utils.h
)

target_include_directories(MessagingSystem PUBLIC include/)
target_link_libraries(MessagingSystem PRIVATE Qt${QT_VERSION_MAJOR}::Core PRIVATE Qt${QT_VERSION_MAJOR}::Network)

target_compile_definitions(MessagingSystem PRIVATE TCPDATATRANSMITTER_LIBRARY)
