cmake_minimum_required( VERSION 3.15 )

# Set some basic project attributes
project (runtime
		VERSION 0.0.0.10
		DESCRIPTION "Runtime plugin")
		
set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_CXX_STANDARD 17 )

file( GLOB_RECURSE PROJECT_SOURCE_FILES src/*.cpp )

file( GLOB_RECURSE PROJECT_INCLUDE_FILES "include/*.h" )

find_package( copa CONFIG REQUIRED )
find_package( osal CONFIG REQUIRED )

add_library( ${PROJECT_NAME} ${PROJECT_INCLUDE_FILES} ${PROJECT_SOURCE_FILES} )

# Create a simple configuration header
configure_file( config.h.in config.h )

include_directories( ${PROJECT_BINARY_DIR} include ${copa_INCLUDE_DIR} ${osal_INCLUDE_DIR} )
# target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR} include ${copa_INCLUDE_DIR} ${osal_INCLUDE_DIR} )

install( TARGETS ${PROJECT_NAME} )
install( DIRECTORY include/ DESTINATION include/${PROJECT_NAME} )

message( "CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}") 

set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION}) 

IF( EXISTS "${WIND_CC_SYSROOT}/secureLoader/privatekey.pem" )
	IF( EXISTS "${WIND_CC_SYSROOT}/secureLoader/publiccert.pem" )
		add_custom_command(TARGET ${MY_TARGET} POST_BUILD
			COMMAND echo "start singtool command ..."
			COMMAND signtool --strip=all --key=${WIND_CC_SYSROOT}/secureLoader/privatekey.pem --cert=${WIND_CC_SYSROOT}/secureLoader/publiccert.pem --type=ELF ${MY_TARGET}
			COMMENT  "end singtool command ..."
		)
	ENDIF()
ENDIF()
