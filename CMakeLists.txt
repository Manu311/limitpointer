  cmake_minimum_required(VERSION 2.6)
  PROJECT(mouseposition)
 
  INCLUDE_DIRECTORIES(

)
  
  FILE(GLOB SRCS *.cpp)
  FILE(GLOB HDRS *.h)
 
  ADD_EXECUTABLE(mouseposition
 	${SRCS}
 	${HDRS}
  )
 
  TARGET_LINK_LIBRARIES(mouseposition
	X11
	Xtst
)