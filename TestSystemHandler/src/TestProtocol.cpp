// {{{RME classifier 'Logical View::TestProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TestProtocol.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <TestProtocol.h>

const RTProtocolDescriptor TestProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &TestProtocol::Conjugate::rt_class
  , "TestProtocol"
  , 0
  , 6
  , TestProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor TestProtocol::Base::rt_signals[] =
{
	{
		"armed"
	  , &RTType_PeripheralIdentifier
	  , TestProtocol::Base::rti_armed
	}
  , {
		"breakin"
	  , &RTType_PeripheralIdentifier
	  , TestProtocol::Base::rti_breakin
	}
  , {
		"disarm"
	  , &RTType_void
	  , TestProtocol::Base::rti_disarm
	}
  , {
		"failed"
	  , &RTType_PeripheralIdentifier
	  , TestProtocol::Base::rti_failed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , TestProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , TestProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor TestProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &TestProtocol::Base::rt_class
  , "TestProtocol"
  , 0
  , 12
  , TestProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor TestProtocol::Conjugate::rt_signals[] =
{
	{
		"arm"
	  , &RTType_void
	  , TestProtocol::Conjugate::rti_arm
	}
  , {
		"arm_pressed"
	  , &RTType_void
	  , TestProtocol::Conjugate::rti_arm_pressed
	}
  , {
		"breakin"
	  , &RTType_PeripheralIdentifier
	  , TestProtocol::Conjugate::rti_breakin
	}
  , {
		"call_failed"
	  , &RTType_void
	  , TestProtocol::Conjugate::rti_call_failed
	}
  , {
		"disabled_pressed"
	  , &RTType_void
	  , TestProtocol::Conjugate::rti_disabled_pressed
	}
  , {
		"disarm"
	  , &RTType_void
	  , TestProtocol::Conjugate::rti_disarm
	}
  , {
		"disarm_pressed"
	  , &RTType_void
	  , TestProtocol::Conjugate::rti_disarm_pressed
	}
  , {
		"enabled_pressed"
	  , &RTType_void
	  , TestProtocol::Conjugate::rti_enabled_pressed
	}
  , {
		"failed"
	  , &RTType_PeripheralIdentifier
	  , TestProtocol::Conjugate::rti_failed
	}
  , {
		"password_entered"
	  , &RTType_RTString
	  , TestProtocol::Conjugate::rti_password_entered
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , TestProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , TestProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
