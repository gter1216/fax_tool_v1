
ADD_DEFINITIONS("-g -Wall -W")

#INCLUDE_DIRECTORIES("/usr/include/pcap/")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/spandsp/spandsp-0.0.6/src/")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/spandsp/spandsp-0.0.6/spandsp-sim/")

LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/SpanDsp/spandsp-0.0.6/src/.libs/")
LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/SpanDsp/spandsp-0.0.6/spandsp-sim/.libs/")
LINK_DIRECTORIES("/usr/lib/x86_64-linux-gnu/")

MESSAGE(STATUS "Including dir is ${PROJECT_SOURCE_DIR}/spandsp/spandsp-0.0.6/src/")
MESSAGE(STATUS "Including dir is ${PROJECT_SOURCE_DIR}/spandsp/spandsp-0.0.6/spandsp-sim/")

#ADD_EXECUTABLE(test_xx test.cpp)

ADD_EXECUTABLE(pcm_parse fax_decode.c fax_utils.c udptl.c)
TARGET_LINK_LIBRARIES(pcm_parse spandsp spandsp-sim sndfile pcap tiff)

ADD_EXECUTABLE(t38_pcap_parse t38_decode.c fax_utils.c udptl.c pcap_parse.c)
TARGET_LINK_LIBRARIES(t38_pcap_parse spandsp spandsp-sim sndfile pcap tiff)

ADD_EXECUTABLE(modem_connect_tones_detect modem_connect_tones_tests.c)
TARGET_LINK_LIBRARIES(modem_connect_tones_detect spandsp spandsp-sim sndfile pcap tiff)

ADD_EXECUTABLE(fax_tool fax_tool.c)
TARGET_LINK_LIBRARIES(fax_tool pthread spandsp spandsp-sim sndfile pcap tiff)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

INSTALL(TARGETS pcm_parse t38_pcap_parse modem_connect_tones_detect fax_tool DESTINATION bin)

