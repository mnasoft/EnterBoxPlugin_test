cmake_minimum_required(VERSION 2.8.12)
project(EnterBoxPlugin_test)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Xml)
find_package(Qt5Widgets)
find_package(Qt5Designer)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  message ("CMAKE_SYSTEM_NAME = Windows")
#  set(CMAKE_INSTALL_PREFIX d:/home/_namatv/usr)
  set(CMAKE_INSTALL_PREFIX e:/home/namatv/usr)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  message ("CMAKE_SYSTEM_NAME = Linux")
  set(CMAKE_INSTALL_PREFIX /home/namatv/usr)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

include_directories(
  ${Qt5Designer_INCLUDE_DIRS}
  src
#
  ${CMAKE_INSTALL_PREFIX}/include/EnterBoxPlugin
#
  ${CMAKE_INSTALL_PREFIX}/include/mnas
  ${CMAKE_INSTALL_PREFIX}/include/mnas/ns_MNAS_Error
  ${CMAKE_INSTALL_PREFIX}/include/mnas/ns_MNAS_CodePage  
  ${CMAKE_INSTALL_PREFIX}/include/mnas/ns_MNAS_Error
  ${CMAKE_INSTALL_PREFIX}/include/mnas/ns_MNAS_Gases 
  ${CMAKE_INSTALL_PREFIX}/include/mnas/ns_MNAS_HalfDiv
  ${CMAKE_INSTALL_PREFIX}/include/mnas/ns_MNAS_Matrix
  ${CMAKE_INSTALL_PREFIX}/include/mnas/ns_MNAS_MendeleevTbl
  ${CMAKE_INSTALL_PREFIX}/include/mnas/ns_MNAS_ValDimension
)

set(EnterBoxPlugin_test_SRCS src/main.cpp)

add_executable (${CMAKE_PROJECT_NAME} ${EnterBoxPlugin_test_SRCS} ${EnterBoxPlugin_test_UIS_H})

# find_library(ns_MNAS_lib ns_MNAS_lib  ${CMAKE_INSTALL_PREFIX}/lib)
find_library(ns_MNAS_lib mnas  ${CMAKE_INSTALL_PREFIX}/lib)
find_library(EnterBoxPlugin EnterBoxPlugin ${CMAKE_INSTALL_PREFIX}/lib)

target_link_libraries(${CMAKE_PROJECT_NAME} 
  Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Designer
  ${ns_MNAS_lib}
  ${EnterBoxPlugin}
)

install(
  TARGETS ${CMAKE_PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib/static)
