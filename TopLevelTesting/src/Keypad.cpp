// {{{RME classifier 'Logical View::Keypad'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Keypad.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <Keypad.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"toSystem"
	  , &KeypadProtocol::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"testPort"
	  , &KeypadProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Keypad_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Keypad_Actor( _rts, _ref );
}

const RTActorClass Keypad =
{
	(const RTActorClass *)0
  , "Keypad"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_Keypad_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Waiting"
};

#define SUPER RTActor

Keypad_Actor::Keypad_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Keypad_Actor::~Keypad_Actor( void )
{
}

int Keypad_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// toSystem
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &toSystem;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// testPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &testPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Waiting:J4D6D46FB01E4:ArmPressed'
INLINE_METHODS void Keypad_Actor::transition2_ArmPressed( const void * rtdata, KeypadProtocol::Conjugate * rtport )
{
	// {{{USR
	toSystem.arm_pressed().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Waiting:J4D6D476B0052:DisarmPressed'
INLINE_METHODS void Keypad_Actor::transition3_DisarmPressed( const void * rtdata, KeypadProtocol::Conjugate * rtport )
{
	// {{{USR
	toSystem.disarm_pressed().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Waiting:J4D6D477F0237:EnabledPressed'
INLINE_METHODS void Keypad_Actor::transition4_EnabledPressed( const void * rtdata, KeypadProtocol::Conjugate * rtport )
{
	// {{{USR
	toSystem.enabled_pressed().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Waiting:J4D6D479B0266:DisabledPressed'
INLINE_METHODS void Keypad_Actor::transition5_DisabledPressed( const void * rtdata, KeypadProtocol::Conjugate * rtport )
{
	// {{{USR
	toSystem.disabled_pressed().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Waiting:J4D6D47E103B1:PasswordEntered'
INLINE_METHODS void Keypad_Actor::transition6_PasswordEntered( const RTString * rtdata, KeypadProtocol::Conjugate * rtport )
{
	// {{{USR
	const String & password = *rtdata;
	toSystem.password_entered(password).send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Keypad_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Keypad_Actor::chain6_PasswordEntered( void )
{
	// transition ':TOP:Waiting:J4D6D47E103B1:PasswordEntered'
	rtgChainBegin( 2, "PasswordEntered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_PasswordEntered( (const RTString *)msg->data, (KeypadProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Keypad_Actor::chain2_ArmPressed( void )
{
	// transition ':TOP:Waiting:J4D6D46FB01E4:ArmPressed'
	rtgChainBegin( 2, "ArmPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_ArmPressed( msg->data, (KeypadProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Keypad_Actor::chain3_DisarmPressed( void )
{
	// transition ':TOP:Waiting:J4D6D476B0052:DisarmPressed'
	rtgChainBegin( 2, "DisarmPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_DisarmPressed( msg->data, (KeypadProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Keypad_Actor::chain4_EnabledPressed( void )
{
	// transition ':TOP:Waiting:J4D6D477F0237:EnabledPressed'
	rtgChainBegin( 2, "EnabledPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_EnabledPressed( msg->data, (KeypadProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Keypad_Actor::chain5_DisabledPressed( void )
{
	// transition ':TOP:Waiting:J4D6D479B0266:DisabledPressed'
	rtgChainBegin( 2, "DisabledPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_DisabledPressed( msg->data, (KeypadProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Keypad_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; stateIndex = rtg_parent_state[ stateIndex - 1 ] )
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
					chain1_Initial();
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
		case 2:
			// {{{RME state ':TOP:Waiting'
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
			case 2:
				// {{{RME port 'testPort'
				switch( signalIndex )
				{
				case KeypadProtocol::Conjugate::rti_password_entered:
					chain6_PasswordEntered();
					return;
				case KeypadProtocol::Conjugate::rti_arm_pressed:
					chain2_ArmPressed();
					return;
				case KeypadProtocol::Conjugate::rti_disarm_pressed:
					chain3_DisarmPressed();
					return;
				case KeypadProtocol::Conjugate::rti_enabled_pressed:
					chain4_EnabledPressed();
					return;
				case KeypadProtocol::Conjugate::rti_disabled_pressed:
					chain5_DisabledPressed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * Keypad_Actor::getActorData( void ) const
{
	return &Keypad_Actor::rtg_class;
}

const RTActor_class Keypad_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , Keypad_Actor::rtg_parent_state
  , &Keypad
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , Keypad_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId Keypad_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor Keypad_Actor::rtg_ports[] =
{
	{
		"toSystem"
	  , (const char *)0
	  , &KeypadProtocol::Base::rt_class
	  , RTOffsetOf( Keypad_Actor, Keypad_Actor::toSystem )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"testPort"
	  , (const char *)0
	  , &KeypadProtocol::Conjugate::rt_class
	  , RTOffsetOf( Keypad_Actor, Keypad_Actor::testPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
