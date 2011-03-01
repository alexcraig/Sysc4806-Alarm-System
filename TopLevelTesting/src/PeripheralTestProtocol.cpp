// {{{RME classifier 'Logical View::PeripheralTestProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PeripheralTestProtocol.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <PeripheralTestProtocol.h>

const RTProtocolDescriptor PeripheralTestProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &PeripheralTestProtocol::Conjugate::rt_class
  , "PeripheralTestProtocol"
  , 0
  , 5
  , PeripheralTestProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PeripheralTestProtocol::Base::rt_signals[] =
{
	{
		"fail"
	  , &RTType_void
	  , PeripheralTestProtocol::Base::rti_fail
	}
  , {
		"recover"
	  , &RTType_void
	  , PeripheralTestProtocol::Base::rti_recover
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PeripheralTestProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PeripheralTestProtocol::Base::rti_rtUnbound
	}
  , {
		"trigger"
	  , &RTType_void
	  , PeripheralTestProtocol::Base::rti_trigger
	}
};

const RTProtocolDescriptor PeripheralTestProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &PeripheralTestProtocol::Base::rt_class
  , "PeripheralTestProtocol"
  , 0
  , 2
  , PeripheralTestProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PeripheralTestProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , PeripheralTestProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PeripheralTestProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
