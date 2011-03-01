// {{{RME classifier 'Logical View::KeypadProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "KeypadProtocol.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <KeypadProtocol.h>

const RTProtocolDescriptor KeypadProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &KeypadProtocol::Conjugate::rt_class
  , "KeypadProtocol"
  , 0
  , 2
  , KeypadProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor KeypadProtocol::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , KeypadProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , KeypadProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor KeypadProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &KeypadProtocol::Base::rt_class
  , "KeypadProtocol"
  , 0
  , 7
  , KeypadProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor KeypadProtocol::Conjugate::rt_signals[] =
{
	{
		"arm_pressed"
	  , &RTType_void
	  , KeypadProtocol::Conjugate::rti_arm_pressed
	}
  , {
		"disabled_pressed"
	  , &RTType_void
	  , KeypadProtocol::Conjugate::rti_disabled_pressed
	}
  , {
		"disarm_pressed"
	  , &RTType_void
	  , KeypadProtocol::Conjugate::rti_disarm_pressed
	}
  , {
		"enabled_pressed"
	  , &RTType_void
	  , KeypadProtocol::Conjugate::rti_enabled_pressed
	}
  , {
		"password_entered"
	  , &RTType_RTString
	  , KeypadProtocol::Conjugate::rti_password_entered
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , KeypadProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , KeypadProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
