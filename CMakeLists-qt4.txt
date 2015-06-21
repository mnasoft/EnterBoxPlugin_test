cmake_minimum_required(VERSION 2.6)

project(EnterBoxPlugin_test)
# set(CMAKE_INSTALL_PREFIX /home/namatv)
execute_process(COMMAND uname -m OUTPUT_VARIABLE arch)

# add_subdirectory(ns_MNAS_lib)
# add_subdirectory(EnterBoxPlugin)

# find_library(mnas NAMES ns_MNAS_lib  PATHS /home/namatv/lib)
# find_library(box NAMES EnterBoxPlugin PATHS /home/namatv/lib)

find_package(Qt4 COMPONENTS QtCore QtGui QtXml QtDesigner REQUIRED )
include(${QT_USE_FILE})

include_directories(
  ${QT_INCLUDES} 
  ${CMAKE_CURRENT_BINARY_DIR} 
#   
  /usr/local/include/EnterBoxPlugin
  /usr/local/include/MNAS_lib
#   ../EnterBoxPlugin/src/
#   ../ns_MNAS_lib/ns_MNAS_CodePage
#   ../ns_MNAS_lib/ns_MNAS_Error
#   ../ns_MNAS_lib/ns_MNAS_Gases
#   ../ns_MNAS_lib/ns_MNAS_HalfDiv
#   ../ns_MNAS_lib/ns_MNAS_Matrix
#   ../ns_MNAS_lib/ns_MNAS_MendeleevTbl
#   ../ns_MNAS_lib/ns_MNAS_ValDimension
)

set(EnterBoxPlugin_test_SRCS
  ./src/main.cpp
)

set(EnterBoxPlugin_test_UIS ../EnterBoxPlugin/forms/EnterBox.ui)

QT4_WRAP_UI(EnterBoxPlugin_test_UIS_H ${EnterBoxPlugin_test_UIS})

qt4_automoc(${EnterBoxPlugin_test_SRCS})

add_executable (EnterBoxPlugin_test 
  ${EnterBoxPlugin_test_SRCS} 
  ${EnterBoxPlugin_test_UIS_H}
)

link_directories (${EnterBoxPlugin_test_BINARY_DIR})

find_library(MLIB ns_MNAS_lib /usr/local/lib64 )
find_library(EnterBoxPlugin EnterBoxPlugin /usr/local/lib64 )

target_link_libraries(EnterBoxPlugin_test 
  ${QT_QTCORE_LIBRARY} 
  ${QT_QTGUI_LIBRARY} 
  ${QT_QTDESIGNER_LIBRARY} 
  ${MLIB}
  ${EnterBoxPlugin}
)

if (${arch} MATCHES "x86_64")
  message ("EnterBoxPlugin_test ${arch}")
  install(
    TARGETS EnterBoxPlugin_test
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib64
    ARCHIVE DESTINATION lib64/static
  )
else(True)
  message ("EnterBoxPlugin_test ${arch}")
  install(
    TARGETS EnterBoxPlugin_test
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static
  )
endif (${arch} MATCHES "x86_64")