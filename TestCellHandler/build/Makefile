RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
PLATFORM = NT40
THREADED = T
LIBRARY_SET = x86-VisualC++-6.0
USER_CC = $(CC)
USER_CCFLAGS = $(DEBUG_TAG)
USER_INCPATHS = $(INCLUDE_TAG)../src
USER_DEPPATHS = $(DEPEND_TAG) ../src
TOP_CAPSULE = TestCellHandler
BUILD_TARGET = TestCellHandler$(EXEC_EXT)
USER_LD = $(LD)
USER_LDFLAGS =
USER_OBJS =
USER_LIBS =
RTCOMPONENT_LIBS =
RTCOMPONENT_LIBS_DEP = $(RTCOMPONENT_LIBS)
SOURCE_DIR = ../src
RTCOMPILE_DAT = rtcompile.dat
RTLINK_DAT = rtlink.dat
ALL_OBJS = \
	Alarm$(OBJ_EXT) \
	CellConfiguration$(OBJ_EXT) \
	CellHandler$(OBJ_EXT) \
	Display$(OBJ_EXT) \
	DisplayProtocol$(OBJ_EXT) \
	HandlerProtocol$(OBJ_EXT) \
	PeripheralIdentifier$(OBJ_EXT) \
	PeripheralTest$(OBJ_EXT) \
	Sensor$(OBJ_EXT) \
	TestCellHandler$(OBJ_EXT) \
	TestProtocol$(OBJ_EXT) \
	RTSystem/TestCellHandler$(OBJ_EXT)

ALL_OBJS_LISTFILE = ALL_OBJS.olist
COMPILE_TARGET = $(BUILD_TARGET)
PURIFY_TARGET = Purify_TestCellHandler$(EXEC_EXT)
PURIFY = purify $(PURIFY_OPTIONS)
PURIFY_OPTIONS = "-log-file=$(PURIFY_TARGET).txt" -windows=no
RTCOMPONENT = "Component View::TestCellHandler"
USER_OBJS_LIST = $(USER_OBJS)
SPACEDEPS = -spacify dq
include <Alarm.dep>
include <CellConfiguration.dep>
include <CellHandler.dep>
include <Display.dep>
include <DisplayProtocol.dep>
include <HandlerProtocol.dep>
include <PeripheralIdentifier.dep>
include <PeripheralTest.dep>
include <Sensor.dep>
include <TestCellHandler.dep>
include <TestProtocol.dep>
include <RTSystem/TestCellHandler.dep>
include <$(RTS_HOME)/codegen/ms_nmake.mk>

RTcompile : $(COMPILE_TARGET)

RTpurify : $(PURIFY_TARGET)

$(BUILD_TARGET) : $(ALL_OBJS) $(USER_OBJS) $(RTCOMPONENT_LIBS_DEP) $(ALL_OBJS_LISTFILE) $(RTLINK_DAT)
	$(RTLINK) -vendor $(VENDOR) -exe "$(BUILD_TARGET)" -component $(RTCOMPONENT) -- \
		$(USER_LD) $(LD_HEAD) $(USER_LDFLAGS) \
		$(ALL_OBJS_LIST) $(USER_OBJS_LIST) \
		$(RTCOMPONENT_LIBS) $(USER_LIBS) $(LD_TAIL)

$(PURIFY_TARGET) : $(ALL_OBJS) $(USER_OBJS) $(RTCOMPONENT_LIBS_DEP) $(ALL_OBJS_LISTFILE) $(RTLINK_DAT)
	$(RTLINK) -vendor $(VENDOR) -purify -exe "$(PURIFY_TARGET)" -component $(RTCOMPONENT) -- \
		$(PURIFY) $(USER_LD) $(LD_HEAD) $(USER_LDFLAGS) \
		$(ALL_OBJS_LIST) $(USER_OBJS_LIST) \
		$(RTCOMPONENT_LIBS) $(USER_LIBS) $(LD_TAIL)

Alarm$(OBJ_EXT) : $(Alarm_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Alarm $(SOURCE_DIR)/Alarm.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Alarm.cpp $(CC_TAIL)

CellConfiguration$(OBJ_EXT) : $(CellConfiguration_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src CellConfiguration $(SOURCE_DIR)/CellConfiguration.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/CellConfiguration.cpp $(CC_TAIL)

CellHandler$(OBJ_EXT) : $(CellHandler_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src CellHandler $(SOURCE_DIR)/CellHandler.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/CellHandler.cpp $(CC_TAIL)

Display$(OBJ_EXT) : $(Display_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Display $(SOURCE_DIR)/Display.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Display.cpp $(CC_TAIL)

DisplayProtocol$(OBJ_EXT) : $(DisplayProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src DisplayProtocol $(SOURCE_DIR)/DisplayProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/DisplayProtocol.cpp $(CC_TAIL)

HandlerProtocol$(OBJ_EXT) : $(HandlerProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src HandlerProtocol $(SOURCE_DIR)/HandlerProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/HandlerProtocol.cpp $(CC_TAIL)

PeripheralIdentifier$(OBJ_EXT) : $(PeripheralIdentifier_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src PeripheralIdentifier $(SOURCE_DIR)/PeripheralIdentifier.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/PeripheralIdentifier.cpp $(CC_TAIL)

PeripheralTest$(OBJ_EXT) : $(PeripheralTest_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src PeripheralTest $(SOURCE_DIR)/PeripheralTest.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/PeripheralTest.cpp $(CC_TAIL)

Sensor$(OBJ_EXT) : $(Sensor_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Sensor $(SOURCE_DIR)/Sensor.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Sensor.cpp $(CC_TAIL)

TestCellHandler$(OBJ_EXT) : $(TestCellHandler_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src TestCellHandler $(SOURCE_DIR)/TestCellHandler.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/TestCellHandler.cpp $(CC_TAIL)

TestProtocol$(OBJ_EXT) : $(TestProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src TestProtocol $(SOURCE_DIR)/TestProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/TestProtocol.cpp $(CC_TAIL)

RTSystem/TestCellHandler$(OBJ_EXT) : $(TestCellHandler_SYSDEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-dep TestCellHandler_SYSDEPS RTSystem/TestCellHandler.dep \
		-component $(RTCOMPONENT) -src TestCellHandler ../src/RTSystem/TestCellHandler.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		../src/RTSystem/TestCellHandler.cpp $(CC_TAIL)

