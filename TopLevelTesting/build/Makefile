RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
PLATFORM = NT40
THREADED = T
LIBRARY_SET = x86-VisualC++-6.0
USER_CC = $(CC)
USER_CCFLAGS = $(DEBUG_TAG)
USER_INCPATHS = $(INCLUDE_TAG)../src
USER_DEPPATHS = $(DEPEND_TAG) ../src
TOP_CAPSULE = SystemHandler
BUILD_TARGET = TopLevelTesting$(EXEC_EXT)
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
	HandlerProtocol$(OBJ_EXT) \
	SystemHandler$(OBJ_EXT) \
	RTSystem/TopLevelTesting$(OBJ_EXT)

ALL_OBJS_LISTFILE = ALL_OBJS.olist
COMPILE_TARGET = $(BUILD_TARGET)
PURIFY_TARGET = Purify_TopLevelTesting$(EXEC_EXT)
PURIFY = purify $(PURIFY_OPTIONS)
PURIFY_OPTIONS = "-log-file=$(PURIFY_TARGET).txt" -windows=no
RTCOMPONENT = "Component View::TopLevelTesting"
USER_OBJS_LIST = $(USER_OBJS)
SPACEDEPS = -spacify dq
include <HandlerProtocol.dep>
include <SystemHandler.dep>
include <RTSystem/TopLevelTesting.dep>
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

HandlerProtocol$(OBJ_EXT) : $(HandlerProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src HandlerProtocol $(SOURCE_DIR)/HandlerProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/HandlerProtocol.cpp $(CC_TAIL)

SystemHandler$(OBJ_EXT) : $(SystemHandler_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src SystemHandler $(SOURCE_DIR)/SystemHandler.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/SystemHandler.cpp $(CC_TAIL)

RTSystem/TopLevelTesting$(OBJ_EXT) : $(TopLevelTesting_SYSDEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-dep TopLevelTesting_SYSDEPS RTSystem/TopLevelTesting.dep \
		-component $(RTCOMPONENT) -src TopLevelTesting ../src/RTSystem/TopLevelTesting.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		../src/RTSystem/TopLevelTesting.cpp $(CC_TAIL)

