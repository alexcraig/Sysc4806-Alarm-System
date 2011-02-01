RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = M:/SYSC4806/Sysc4806-Alarm-System/4806_Alarm_System.rtmdl
COMPONENT = "Component View::TopLevelTesting"
RTGEN_FLAGS = -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/TopLevelTesting.dep>
TARGETS = $(TopLevelTesting_SYSTARGET)
RTGENERATE_TARGET = $(TARGETS)
RTGENERATE_DAT = rtgenerate.dat

RTgenerate : $(RTGENERATE_TARGET)

.PRECIOUS : $(TARGETS)

$(TopLevelTesting_SYSTARGET) : $(TopLevelTesting_SYSDEPS) $(RTGENERATE_DAT)
	$(RTGEN) $(RTGEN_FLAGS) -system

