RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = M:/SYSC4805/Sysc4806-Alarm-System/4806_Alarm_System.rtmdl
COMPONENT = "Component View::TestSystemHandler"
RTGEN_FLAGS = -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/TestSystemHandler.dep>
TARGETS = $(TestSystemHandler_SYSTARGET)
RTGENERATE_TARGET = $(TARGETS)
RTGENERATE_DAT = rtgenerate.dat

RTgenerate : $(RTGENERATE_TARGET)

.PRECIOUS : $(TARGETS)

$(TestSystemHandler_SYSTARGET) : $(TestSystemHandler_SYSDEPS) $(RTGENERATE_DAT)
	$(RTGEN) $(RTGEN_FLAGS) -system

