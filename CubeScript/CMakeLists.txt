set(LLVM_DIR "D:\\CPPLibs\\llvm-project-llvmorg-17.0.6\\build\\lib\\cmake\\llvm\\")
set(ANTLR4CPP_DIR "D:\\CPPLibs\\antlr4-4.13.1\\runtime\\Cpp\\")
set(CUBE_SCRIPT_PARSER "${CMAKE_SOURCE_DIR}/CubeScript/Generate")

LIST( APPEND CMAKE_MODULE_PATH ${ANTLR4CPP_DIR}\\cmake )

add_definitions(-DANTLR4CPP_STATIC)
set(ANTLR4_WITH_STATIC_CRT OFF)

include(ExternalAntlr4Cpp)
include_directories(${ANTLR4_INCLUDE_DIRS})

set(ANTLR_EXECUTABLE "${CUBE_SCRIPT_PARSER}\\antlr-4.13.1-complete.jar")

find_package(LLVM REQUIRED CONFIG)
find_package(ANTLR REQUIRED)

antlr_target(SampleGrammarLexer ${CUBE_SCRIPT_PARSER}/CSLexer.g4 LEXER
			 OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/CubeScript/Parser/
             PACKAGE antlrcpptest)
antlr_target(SampleGrammarParser ${CUBE_SCRIPT_PARSER}/CSParser.g4 PARSER
			 OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/CubeScript/Parser/
             PACKAGE antlrcpptest
             DEPENDS_ANTLR SampleGrammarLexer
             COMPILE_FLAGS -lib ${ANTLR_SampleGrammarLexer_OUTPUT_DIR})

include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

add_executable (
	CubeScript
	"CubeScript.cpp"
	"CubeScript.h"
	"Executor.cpp"
	"Executor.h"
	"Result.h"

	"Nodes/Expressions.h"
	"Nodes/Types.h"
	"Nodes/Variables.h" 
	"Nodes/Expressions.cpp"
	"Nodes/Variables.cpp"
	"Nodes/Scope.h"
	"Nodes/Scope.cpp"
	${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
    ${ANTLR_SampleGrammarParser_CXX_OUTPUTS}
 "TreeListener.h")

configure_file(script.cbscr script.cbscr)

llvm_map_components_to_libnames(llvm_libs
	support
	core
	irreader
	executionengine
	interpreter
	mc
	mcjit
	nativecodegen
)
target_link_libraries(CubeScript ${llvm_libs})
#target_link_libraries(CubeScript antlr4_shared)
target_link_libraries(CubeScript antlr4_static)
#add_custom_command(TARGET CubeScript
#				   POST_BUILD
#				   COMMAND ${CMAKE_COMMAND}
#						   -E copy ${ANTLR4_RUNTIME_LIBRARIES} .
#				   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CubeScript PROPERTY CXX_STANDARD 20)
endif()
