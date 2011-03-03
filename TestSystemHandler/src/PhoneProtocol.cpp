// {{{RME classifier 'Logical View::PhoneProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PhoneProtocol.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <PhoneProtocol.h>

const RTProtocolDescriptor PhoneProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &PhoneProtocol::Conjugate::rt_class
  , "PhoneProtocol"
  , 0
  , 3
  , PhoneProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PhoneProtocol::Base::rt_signals[] =
{
	{
		"place_call"
	  , &RTType_RTString
	  , PhoneProtocol::Base::rti_place_call
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PhoneProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PhoneProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor PhoneProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &PhoneProtocol::Base::rt_class
  , "PhoneProtocol"
  , 0
  , 4
  , PhoneProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PhoneProtocol::Conjugate::rt_signals[] =
{
	{
		"call_failed"
	  , &RTType_void
	  , PhoneProtocol::Conjugate::rti_call_failed
	}
  , {
		"call_placed"
	  , &RTType_void
	  , PhoneProtocol::Conjugate::rti_call_placed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PhoneProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PhoneProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
