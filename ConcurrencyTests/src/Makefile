RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = M:/Sysc4806-Alarm-System/4806_Alarm_System.rtmdl
COMPONENT = "Component View::ConcurrencyTests"
RTGEN_FLAGS = -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/ConcurrencyTests.dep>
TARGETS = $(ConcurrencyTests_SYSTARGET)
RTGENERATE_TARGET = $(TARGETS)
RTGENERATE_DAT = rtgenerate.dat

RTgenerate : $(RTGENERATE_TARGET)

.PRECIOUS : $(TARGETS)

$(ConcurrencyTests_SYSTARGET) : $(ConcurrencyTests_SYSDEPS) $(RTGENERATE_DAT)
	$(RTGEN) $(RTGEN_FLAGS) -system

