// {{{RME classifier 'Logical View::SystemHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SystemHandler.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <SystemHandler.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"toCells"
	  , &HandlerProtocol::Base::rt_class
	  , 3 // cardinality
	}
};

static RTActor * new_SystemHandler_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new SystemHandler_Actor( _rts, _ref );
}

const RTActorClass SystemHandler =
{
	(const RTActorClass *)0
  , "SystemHandler"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_SystemHandler_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
};

#define SUPER RTActor

SystemHandler_Actor::SystemHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

SystemHandler_Actor::~SystemHandler_Actor( void )
{
}

int SystemHandler_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// toCells
		if( rtg_repIndex < 3 )
		{
			rtg_end.port = &toCells;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

void SystemHandler_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; )
		switch( stateIndex )
		{
		case 1:
			// {{{RME state ':TOP'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			unexpectedMessage();
			return;
			// }}}RME
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * SystemHandler_Actor::getActorData( void ) const
{
	return &SystemHandler_Actor::rtg_class;
}

const RTActor_class SystemHandler_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 1
  , SystemHandler_Actor::rtg_parent_state
  , &SystemHandler
  , 0
  , (const RTComponentDescriptor *)0
  , 1
  , SystemHandler_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId SystemHandler_Actor::rtg_parent_state[] =
{
	0
};

const RTPortDescriptor SystemHandler_Actor::rtg_ports[] =
{
	{
		"toCells"
	  , (const char *)0
	  , &HandlerProtocol::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toCells )
	  , 3 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
