RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = M:/SYSC4805/Sysc4806-Alarm-System/4806_Alarm_System.rtmdl
COMPONENT = "Component View::TestSystemHandler"
RTGEN_FLAGS = -codesync -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/TestSystemHandler.dep>
CODESYNC_TARGETS = $(TestSystemHandler_SYSTARGET_CS)
RTCODESYNC_TARGET = $(CODESYNC_TARGETS)

RTcodesync : $(RTCODESYNC_TARGET)

.PRECIOUS : $(CODESYNC_TARGETS)

$(TestSystemHandler_SYSTARGET_CS) : $(TestSystemHandler_SYSDEPS_CS)
	$(RTGEN) $(RTGEN_FLAGS) -system

