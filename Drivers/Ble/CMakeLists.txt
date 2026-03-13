add_library(UGV_bluetooth 
    STATIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/BleRx.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/BleTx.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Moter_Dispatch.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/PacketCodec.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Servo_Dispatch.cpp
)

target_include_directories(UGV_bluetooth
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_link_libraries(UGV_bluetooth 
    PUBLIC
        stm32cubemx
)

target_compile_options(UGV_bluetooth PRIVATE
    # Add user defined compile options

    $<$<COMPILE_LANGUAGE:CXX>: -fno-rtti -fno-exceptions>   
)

set_target_properties(UGV_bluetooth PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS YES
)