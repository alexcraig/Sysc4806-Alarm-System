// {{{RME classifier 'Logical View::NewProtocol3'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "NewProtocol3.h"
#endif

#include <RTSystem/TestCellHandler.h>
#include <NewProtocol3.h>

const RTProtocolDescriptor NewProtocol3::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &NewProtocol3::Conjugate::rt_class
  , "NewProtocol3"
  , 0
  , 2
  , NewProtocol3::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor NewProtocol3::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , NewProtocol3::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , NewProtocol3::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor NewProtocol3::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &NewProtocol3::Base::rt_class
  , "NewProtocol3"
  , 0
  , 2
  , NewProtocol3::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor NewProtocol3::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , NewProtocol3::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , NewProtocol3::Conjugate::rti_rtUnbound
	}
};

// }}}RME
