// {{{RME classifier 'Logical View::PhoneTest'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PhoneTest.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <PhoneTest.h>

const RTProtocolDescriptor PhoneTest::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &PhoneTest::Conjugate::rt_class
  , "PhoneTest"
  , 0
  , 4
  , PhoneTest::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PhoneTest::Base::rt_signals[] =
{
	{
		"fail"
	  , &RTType_void
	  , PhoneTest::Base::rti_fail
	}
  , {
		"recover"
	  , &RTType_void
	  , PhoneTest::Base::rti_recover
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , PhoneTest::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PhoneTest::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor PhoneTest::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &PhoneTest::Base::rt_class
  , "PhoneTest"
  , 0
  , 2
  , PhoneTest::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor PhoneTest::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , PhoneTest::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , PhoneTest::Conjugate::rti_rtUnbound
	}
};

// }}}RME
