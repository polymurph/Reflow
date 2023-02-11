#Declareing header directory for the project
#To add a new directory 
# -> list(APPEND PROJECT_HEADERS_DIR ${PROJECT_DIR}/YOUR_DESIRED_DIRECTORY)	
# list()				= List declaration "DON'T CHANGE"
# PROJECT_HEADERS_DIR	= Variable containing the listed direcotries "DON'T CHANCE
# ${PROJECT_DIR}		= Direcotry of the main project this is per default the current direcotry it is defined in ked/CMakeLists.txt 

#Declaring sources directory for the project
#To add a new directory 
# -> list(APPEND PROJECT_SOURCES_DIR ${PROJECT_DIR}/YOUR_DESIRED_DIRECTORY)	
# list()				= List declaration "DON'T CHANGE"
# PROJECT_SOURCES_DIR	= Variable containing the listed direcotries "DON'T CHANCE
# ${PROJECT_DIR}		= Direcotry of the main project this is per default the current direcotry it is defined in ked/CMakeLists.txt 
list(APPEND PROJECT_SOURCES_DIR ${PROJECT_DIR}/bsl)

#Declaring sources to be compiled for the project. 
#CMake will look in each previsouly declarec sources directory until it finds this files. 
set(PROJECT_SOURCES_DIR_LIST reflow_oven_bsl)

