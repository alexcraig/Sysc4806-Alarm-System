// {{{RME classifier 'Logical View::PeripheralTest'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PeripheralTest.h"
#endif

#include <RTSystem/TestCellHandler.h>
#include <PeripheralTest.h>

const RTProtocolDescriptor PeripheralTest::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &PeripheralTest::Conjugate::rt_class
  , "PeripheralTest"
  , 0
  , 5
  , PeripheralTest::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PeripheralTest::Base::rt_signals[] =
{
	{
		"fail"
	  , &RTType_void
	  , PeripheralTest::Base::rti_fail
	}
  , {
		"recover"
	  , &RTType_void
	  , PeripheralTest::Base::rti_recover
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PeripheralTest::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PeripheralTest::Base::rti_rtUnbound
	}
  , {
		"trigger"
	  , &RTType_void
	  , PeripheralTest::Base::rti_trigger
	}
};

const RTProtocolDescriptor PeripheralTest::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &PeripheralTest::Base::rt_class
  , "PeripheralTest"
  , 0
  , 2
  , PeripheralTest::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PeripheralTest::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , PeripheralTest::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PeripheralTest::Conjugate::rti_rtUnbound
	}
};

// }}}RME
