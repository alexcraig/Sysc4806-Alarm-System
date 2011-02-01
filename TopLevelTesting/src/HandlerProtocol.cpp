// {{{RME classifier 'Logical View::HandlerProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "HandlerProtocol.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <HandlerProtocol.h>

const RTProtocolDescriptor HandlerProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &HandlerProtocol::Conjugate::rt_class
  , "HandlerProtocol"
  , 0
  , 4
  , HandlerProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor HandlerProtocol::Base::rt_signals[] =
{
	{
		"breakin"
	  , &RTType_void
	  , HandlerProtocol::Base::rti_breakin
	}
  , {
		"heartbeat"
	  , &RTType_void
	  , HandlerProtocol::Base::rti_heartbeat
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , HandlerProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , HandlerProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor HandlerProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &HandlerProtocol::Base::rt_class
  , "HandlerProtocol"
  , 0
  , 6
  , HandlerProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor HandlerProtocol::Conjugate::rt_signals[] =
{
	{
		"arm"
	  , &RTType_void
	  , HandlerProtocol::Conjugate::rti_arm
	}
  , {
		"disarm"
	  , &RTType_void
	  , HandlerProtocol::Conjugate::rti_disarm
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , HandlerProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , HandlerProtocol::Conjugate::rti_rtUnbound
	}
  , {
		"selftest"
	  , &RTType_void
	  , HandlerProtocol::Conjugate::rti_selftest
	}
  , {
		"trigger"
	  , &RTType_void
	  , HandlerProtocol::Conjugate::rti_trigger
	}
};

// }}}RME
