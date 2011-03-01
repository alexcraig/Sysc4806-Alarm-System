// {{{RME classifier 'Logical View::DisplayProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DisplayProtocol.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <DisplayProtocol.h>

const RTProtocolDescriptor DisplayProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &DisplayProtocol::Conjugate::rt_class
  , "DisplayProtocol"
  , 0
  , 3
  , DisplayProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor DisplayProtocol::Base::rt_signals[] =
{
	{
		"display_string"
	  , &RTType_RTString
	  , DisplayProtocol::Base::rti_display_string
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , DisplayProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , DisplayProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor DisplayProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &DisplayProtocol::Base::rt_class
  , "DisplayProtocol"
  , 0
  , 2
  , DisplayProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor DisplayProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , DisplayProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , DisplayProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
