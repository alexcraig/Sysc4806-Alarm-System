// {{{RME classifier 'Logical View::NewProtocol2'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "NewProtocol2.h"
#endif

#include <RTSystem/TestCellHandler.h>
#include <NewProtocol2.h>

const RTProtocolDescriptor NewProtocol2::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &NewProtocol2::Conjugate::rt_class
  , "NewProtocol2"
  , 0
  , 2
  , NewProtocol2::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor NewProtocol2::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , NewProtocol2::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , NewProtocol2::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor NewProtocol2::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &NewProtocol2::Base::rt_class
  , "NewProtocol2"
  , 0
  , 2
  , NewProtocol2::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor NewProtocol2::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , NewProtocol2::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , NewProtocol2::Conjugate::rti_rtUnbound
	}
};

// }}}RME
