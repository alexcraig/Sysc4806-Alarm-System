// {{{RME classifier 'Logical View::SystemHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SystemHandler.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <SystemHandler.h>
extern const RTActorClass CellHandler;
extern const RTActorClass Display;
extern const RTActorClass Keypad;
extern const RTActorClass PhoneLine;
extern const RTActorClass SoundAlarm;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_SystemHandler_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new SystemHandler_Actor( _rts, _ref );
}

const RTActorClass SystemHandler =
{
	(const RTActorClass *)0
  , "SystemHandler"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_SystemHandler_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
};

static const RTInterfaceDescriptor rtg_interfaces_displayR1[] =
{
	{
		"toSystem"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_displayR1[] =
{
	{
		0
	  , &DisplayProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_keypadR1[] =
{
	{
		"toSystem"
	  , 1
	}
  , {
		"testPort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_keypadR1[] =
{
	{
		0
	  , &KeypadProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_soundAlarmR1[] =
{
	{
		"fromCell"
	  , 1
	}
  , {
		"testPort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_soundAlarmR1[] =
{
	{
		0
	  , &HandlerProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_cellHandlerR1[] =
{
	{
		"fromSystem"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_cellHandlerR1[] =
{
	{
		0
	  , &HandlerProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_phoneLineR1[] =
{
	{
		"toSystem"
	  , 1
	}
  , {
		"testPort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_phoneLineR1[] =
{
	{
		0
	  , &PhoneProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

SystemHandler_Actor::SystemHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

SystemHandler_Actor::~SystemHandler_Actor( void )
{
}

// {{{RME operation 'setEnabled(bool)'
void SystemHandler_Actor::setEnabled( bool enabled )
{
	// {{{USR

	// }}}USR
}
// }}}RME

int SystemHandler_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// displayR1
		switch( rtg_portId )
		{
		case 0:
			// toSystem
			if( rtg_repIndex < 1 )
			{
				// toDisplay
				rtg_end.port = &toDisplay;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 2:
		// keypadR1
		switch( rtg_portId )
		{
		case 0:
			// toSystem
			if( rtg_repIndex < 1 )
			{
				// toKeypad
				rtg_end.port = &toKeypad;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 3:
		// soundAlarmR1
		switch( rtg_portId )
		{
		case 0:
			// fromCell
			if( rtg_repIndex < 1 )
			{
				// toInternalAlarm
				rtg_end.port = &toInternalAlarm;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 4:
		// cellHandlerR1
		switch( rtg_portId )
		{
		case 0:
			// fromSystem
			if( rtg_repIndex < 3 )
			{
				// toCells
				rtg_end.port = &toCells;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 5:
		// phoneLineR1
		switch( rtg_portId )
		{
		case 0:
			// toSystem
			if( rtg_repIndex < 1 )
			{
				// toPhone
				rtg_end.port = &toPhone;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	default:
		break;
	}
	return RTActor::_followOutV( rtg_end, rtg_compId, rtg_portId, rtg_repIndex );
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
  , 5
  , SystemHandler_Actor::rtg_capsule_roles
  , 7
  , SystemHandler_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , SystemHandler_Actor::rtg_SystemHandler_fields
};

const RTStateId SystemHandler_Actor::rtg_parent_state[] =
{
	0
};

const RTComponentDescriptor SystemHandler_Actor::rtg_capsule_roles[] =
{
	{
		"displayR1"
	  , &Display
	  , RTOffsetOf( SystemHandler_Actor, displayR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_displayR1
	  , 1
	  , rtg_bindings_displayR1
	}
  , {
		"keypadR1"
	  , &Keypad
	  , RTOffsetOf( SystemHandler_Actor, keypadR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_keypadR1
	  , 1
	  , rtg_bindings_keypadR1
	}
  , {
		"soundAlarmR1"
	  , &SoundAlarm
	  , RTOffsetOf( SystemHandler_Actor, soundAlarmR1 )
	  , 3
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_soundAlarmR1
	  , 1
	  , rtg_bindings_soundAlarmR1
	}
  , {
		"cellHandlerR1"
	  , &CellHandler
	  , RTOffsetOf( SystemHandler_Actor, cellHandlerR1 )
	  , 4
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 3 // cardinality
	  , 1
	  , rtg_interfaces_cellHandlerR1
	  , 1
	  , rtg_bindings_cellHandlerR1
	}
  , {
		"phoneLineR1"
	  , &PhoneLine
	  , RTOffsetOf( SystemHandler_Actor, phoneLineR1 )
	  , 5
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_phoneLineR1
	  , 1
	  , rtg_bindings_phoneLineR1
	}
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
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toKeypad"
	  , (const char *)0
	  , &KeypadProtocol::Conjugate::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toKeypad )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toDisplay"
	  , (const char *)0
	  , &DisplayProtocol::Conjugate::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toDisplay )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toInternalAlarm"
	  , (const char *)0
	  , &HandlerProtocol::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toInternalAlarm )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toLog"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toLog )
	  , 1 // cardinality
	  , 5
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toTimer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toTimer )
	  , 1 // cardinality
	  , 6
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toPhone"
	  , (const char *)0
	  , &PhoneProtocol::Conjugate::rt_class
	  , RTOffsetOf( SystemHandler_Actor, SystemHandler_Actor::toPhone )
	  , 1 // cardinality
	  , 7
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor SystemHandler_Actor::rtg_SystemHandler_fields[] =
{
	// {{{RME classAttribute 'enabled'
	{
		"enabled"
	  , RTOffsetOf( SystemHandler_Actor, enabled )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
