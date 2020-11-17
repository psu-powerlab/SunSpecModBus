# Create library
add_library(SunSpecModbus STATIC SunSpecModbus.cpp SunSpecModel.cpp)
target_link_libraries(SunSpecModbus PRIVATE Boost::boost modbus)
target_include_directories(SunSpecModbus PUBLIC ${Boost_INCLUDE_DIRS})

# add include directories
target_include_directories(SunSpecModbus
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:include>"
)

# install the target and create export-set
install(TARGETS SunSpecModbus
        EXPORT SunSpecModbusTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

# install header file
install(
    FILES 
    SunSpecModbus.h 
    SunSpecModel.h
    DESTINATION include)

# generate and install export file
install(EXPORT SunSpecModbusTargets
        FILE SunSpecModbusTargets.cmake
        NAMESPACE MathFunctions::
        DESTINATION lib/cmake
)
