  cmake_minimum_required(VERSION 2.6)
  PROJECT(limitpointer)
 
  INCLUDE_DIRECTORIES(

)
  
  FILE(GLOB SRCS *.cpp)
  FILE(GLOB HDRS *.h)
 
  ADD_EXECUTABLE(limitpointer
 	${SRCS}
 	${HDRS}
  )
 
  TARGET_LINK_LIBRARIES(limitpointer
	X11
	Xtst
)