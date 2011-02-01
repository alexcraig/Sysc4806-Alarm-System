RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = M:/SYSC4806/Sysc4806-Alarm-System/4806_Alarm_System.rtmdl
COMPONENT = "Component View::TopLevelTesting"
RTGEN_FLAGS = -codesync -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/TopLevelTesting.dep>
CODESYNC_TARGETS = $(TopLevelTesting_SYSTARGET_CS)
RTCODESYNC_TARGET = $(CODESYNC_TARGETS)

RTcodesync : $(RTCODESYNC_TARGET)

.PRECIOUS : $(CODESYNC_TARGETS)

$(TopLevelTesting_SYSTARGET_CS) : $(TopLevelTesting_SYSDEPS_CS)
	$(RTGEN) $(RTGEN_FLAGS) -system

