RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = M:/Sysc4806-Alarm-System/4806_Alarm_System.rtmdl
COMPONENT = "Component View::ConcurrencyTests"
RTGEN_FLAGS = -codesync -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/ConcurrencyTests.dep>
CODESYNC_TARGETS = $(ConcurrencyTests_SYSTARGET_CS)
RTCODESYNC_TARGET = $(CODESYNC_TARGETS)

RTcodesync : $(RTCODESYNC_TARGET)

.PRECIOUS : $(CODESYNC_TARGETS)

$(ConcurrencyTests_SYSTARGET_CS) : $(ConcurrencyTests_SYSDEPS_CS)
	$(RTGEN) $(RTGEN_FLAGS) -system

