CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(ICP3038--Lab8--EdgeIn2OpenCV)

# Make sure C++ 11 is used (in case someone used OpenCV 4.x)
SET (CMAKE_CXX_STANDARD 11)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)

# Add where OpenCV might be installed (look in D: first, then in C:)
IF (WIN32)
    SET (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "D:\\opencv\\build")
    SET (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:\\opencv\\build")
ENDIF (WIN32)


# Find OpenCV
FIND_PACKAGE(OpenCV REQUIRED)

# Add OpenCV's header path
INCLUDE_DIRECTORIES (${OpenCV_INCLUDE_DIRS})

# Add the libraries for OpenCV
SET (requiredLibs ${requiredLibs} ${OpenCV_LIBS})


# The executable programs
ADD_EXECUTABLE (edgeDetection1   src/edgeDetection1.cxx)
ADD_EXECUTABLE (edgeDetection2   src/edgeDetection2.cxx)
ADD_EXECUTABLE (edgeDetection3   src/edgeDetection3.cxx)


# Add OpenCV libraries to each executable programs
TARGET_LINK_LIBRARIES (edgeDetection1   ${requiredLibs})
TARGET_LINK_LIBRARIES (edgeDetection2   ${requiredLibs})
TARGET_LINK_LIBRARIES (edgeDetection3   ${requiredLibs})


# If windows is used, copy the dlls into the project directory
SET (CV_VERSION_STRING ${OpenCV_VERSION_MAJOR}${OpenCV_VERSION_MINOR}${OpenCV_VERSION_PATCH})
IF (WIN32)
	
    IF (EXISTS "${OpenCV_DIR}/x64/vc15/bin/opencv_ffmpeg${CV_VERSION_STRING}_64.dll")
        FILE (COPY        "${OpenCV_DIR}/x64/vc15/bin/opencv_ffmpeg${CV_VERSION_STRING}_64.dll"
              DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
    ELSE ()
	    MESSAGE (WARNING "opencv_ffmpeg${CV_VERSION_STRING}_64.dll is not in ${OpenCV_DIR}/x64/vc15/bin/, you have to make sure is it in the PATH or to copy it manually in your project binary directory")
    ENDIF ()

    IF (EXISTS "${OpenCV_DIR}/x64/vc15/bin/opencv_world${CV_VERSION_STRING}.dll")
        FILE (COPY        "${OpenCV_DIR}/x64/vc15/bin/opencv_world${CV_VERSION_STRING}.dll"
              DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
    ELSE ()
	    MESSAGE (WARNING "opencv_world${CV_VERSION_STRING}.dll is not in ${OpenCV_DIR}/x64/vc15/bin/, you have to make sure is it in the PATH or to copy it manually in your project binary directory")
    ENDIF ()

    IF (EXISTS "${OpenCV_DIR}/x64/vc15/bin/opencv_world${CV_VERSION_STRING}d.dll")
        FILE (COPY        "${OpenCV_DIR}/x64/vc15/bin/opencv_world${CV_VERSION_STRING}d.dll"
              DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
    ELSE ()
	    MESSAGE (WARNING "opencv_world${CV_VERSION_STRING}d.dll is not in ${OpenCV_DIR}/x64/vc15/bin/, you have to make sure is it in the PATH or to copy it manually in your project binary directory")
    ENDIF ()
	
ENDIF (WIN32)
