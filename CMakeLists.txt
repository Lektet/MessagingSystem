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
    include/AddMessageMessage.h
    include/AddUserMessage.h
    include/ChangeUserPasswordMessage.h
    include/ChatMessageData.h
    include/Constants.h
    include/ErrorCode.h
    include/ErrorInfo.h
    include/GetHistoryMessage.h
    include/GetHistoryResponseMessage.h
    include/JsonSerializable.h
    include/MessageType.h
    include/MessageUtils.h
    include/NewChatMessageData.h
    include/NewSessionConfirmMessage.h
    include/NewSessionEstablishmentMessage.h
    include/NewSessionRequestMessage.h
    include/NewSessionResponseMessage.h
    include/NotificationMessage.h
    include/NotificationType.h
    include/ResponseMessage.h
    include/Result.h
    include/SessionInitiationMessage.h
    include/SessionMessage.h
    include/SimpleMessage.h
    include/UserRole.h
    include/utils.h
    src/AddMessageMessage.cpp
    src/AddUserMessage.cpp
    src/ErrorCode.cpp
    src/ErrorInfo.cpp
    src/ChangeUserPasswordMessage.cpp
    src/ChatMessageData.cpp
    src/GetHistoryMessage.cpp
    src/GetHistoryResponseMessage.cpp
    src/JsonSerializable.cpp
    src/MessageType.cpp
    src/MessageUtils.cpp
    src/NewChatMessageData.cpp
    src/NewSessionConfirmMessage.cpp
    src/NewSessionEstablishmentMessage.cpp
    src/NewSessionRequestMessage.cpp
    src/NewSessionResponseMessage.cpp
    src/NotificationMessage.cpp
    src/NotificationType.cpp
    src/SessionInitiationMessage.cpp
    src/SessionMessage.cpp
    src/SimpleMessage.cpp
    src/ResponseMessage.cpp
    src/Result.cpp
    src/UserRole.cpp
)

target_include_directories(MessagingSystem PUBLIC include/)
target_link_libraries(MessagingSystem PRIVATE Qt${QT_VERSION_MAJOR}::Core PRIVATE Qt${QT_VERSION_MAJOR}::Network)
