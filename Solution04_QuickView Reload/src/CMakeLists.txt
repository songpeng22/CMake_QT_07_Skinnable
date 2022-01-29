cmake_minimum_required(VERSION 3.1.0)
project(Solution)

# set(<variable> <value>
#    [[CACHE <type> <docstring> [FORCE]] | PARENT_SCOPE])
set( project_name QmlStandard )
message( "Project name is: " ${project_name} )

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
#handle rcc automatically( handle qrc file )
set(CMAKE_AUTORCC ON)

# Definitions
IF(WIN32)

  IF(MSVC)
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DQT_QML_DEBUG ")
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DCMAKE_BUILD_TYPE=Debug ")
  ENDIF() 
  
ELSE()

ENDIF()

# Find the QtWidgets library
find_package( Qt5 REQUIRED 
# QuickWidgets means CMake would search for ".\lib\cmake\Qt5QuickWidgetsConfig.cmake"
    COMPONENTS Core Gui Widgets Qml Quick QuickWidgets QuickControls2
)

include_directories(
# Qt5::Core means there is ".\include\QtCore""
    Qt5::Core   
    Qt5::Gui
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    Qt5::QuickWidgets
    Qt5::QuickControls2
)

# Populate a CMake variable with the sources
FILE(GLOB project_sources
    main.cpp
    EngineReloader.cpp
    EngineReloaderWrapper.cpp
    QuickViewReloader.cpp
    QuickViewReloaderWrapper.cpp
)

FILE(GLOB project_headers
    *.h
)

SET( project_resources 
    main.qrc
    main.qml
    method2.qml
    qtquickcontrols2.conf
)

#Same type together
SOURCE_GROUP("Source Files" FILES ${project_sources})
SOURCE_GROUP("Header Files" FILES ${project_headers})
SOURCE_GROUP("Resource Files" FILES ${project_resources})

# Tell CMake to create the project executable
add_executable( ${project_name} WIN32 ${project_sources} ${project_headers} ${project_resources})

# Output Path
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
# MESSAGE(STATUS "EXECUTABLE_OUTPUT_PATH: " ${EXECUTABLE_OUTPUT_PATH} )
# set_target_properties(target1 target2 ...PROPERTIES prop1 value1 prop2 value2 ...)
# Output Path
set_target_properties( ${project_name}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin
)
# Output Name
SET_TARGET_PROPERTIES( ${project_name} PROPERTIES OUTPUT_NAME "posconfig")
# get_target_property
get_target_property(QtCore_location Qt5::Core LOCATION)
MESSAGE(STATUS "This is QtCore_location " ${QtCore_location})

# Must After add_executable
target_link_libraries( ${project_name}
	${Qt5Core_LIBRARIES}
	${Qt5Gui_LIBRARIES}
	${Qt5Widgets_LIBRARIES}
	${Qt5Qml_LIBRARIES}
	${Qt5Quick_LIBRARIES}
	${Qt5QuickWidgets_LIBRARIES}
        ${Qt5QuickControls2_LIBRARIES}
)

#Message Sln Path
MESSAGE(STATUS "Message:" )
MESSAGE(STATUS "This is BINARY dir " ${Solution_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${Solution_SOURCE_DIR})
#Message Qt Path
MESSAGE(STATUS "Message:" )
MESSAGE(STATUS "This is Qt5Widgets_INCLUDE_DIRS " ${Qt5Widgets_INCLUDE_DIRS})
MESSAGE(STATUS "This is Qt5Widgets_LIBRARIES " ${Qt5Widgets_LIBRARIES})
MESSAGE(STATUS "This is Qt5Qml_INCLUDE_DIRS " ${Qt5Qml_INCLUDE_DIRS})
