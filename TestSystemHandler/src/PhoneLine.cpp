// {{{RME classifier 'Logical View::PhoneLine'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PhoneLine.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <PhoneLine.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"toSystem"
	  , &PhoneProtocol::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"testPort"
	  , &PhoneTest::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_PhoneLine_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new PhoneLine_Actor( _rts, _ref );
}

const RTActorClass PhoneLine =
{
	(const RTActorClass *)0
  , "PhoneLine"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_PhoneLine_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Active"
  , "Failed"
};

#define SUPER RTActor

PhoneLine_Actor::PhoneLine_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

PhoneLine_Actor::~PhoneLine_Actor( void )
{
}

int PhoneLine_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
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

// {{{RME transition ':TOP:Failed:J4D6D4B220080:FailedCall'
INLINE_METHODS void PhoneLine_Actor::transition4_FailedCall( const RTString * rtdata, PhoneProtocol::Base * rtport )
{
	// {{{USR
	toSystem.call_failed().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Active:J4D6D4B3B00BD:SuccessfulCall'
INLINE_METHODS void PhoneLine_Actor::transition5_SuccessfulCall( const RTString * rtdata, PhoneProtocol::Base * rtport )
{
	// {{{USR
	// PHONE CALL HAPPENS HERE

	toSystem.call_placed().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void PhoneLine_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void PhoneLine_Actor::chain5_SuccessfulCall( void )
{
	// transition ':TOP:Active:J4D6D4B3B00BD:SuccessfulCall'
	rtgChainBegin( 2, "SuccessfulCall" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_SuccessfulCall( (const RTString *)msg->data, (PhoneProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void PhoneLine_Actor::chain2_Fail( void )
{
	// transition ':TOP:Active:J4D6D4B0202EF:Fail'
	rtgChainBegin( 2, "Fail" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void PhoneLine_Actor::chain4_FailedCall( void )
{
	// transition ':TOP:Failed:J4D6D4B220080:FailedCall'
	rtgChainBegin( 3, "FailedCall" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_FailedCall( (const RTString *)msg->data, (PhoneProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void PhoneLine_Actor::chain3_Recover( void )
{
	// transition ':TOP:Failed:J4D6D4B0C004F:Recover'
	rtgChainBegin( 3, "Recover" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

void PhoneLine_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Active'
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
			case 1:
				// {{{RME port 'toSystem'
				switch( signalIndex )
				{
				case PhoneProtocol::Base::rti_place_call:
					chain5_SuccessfulCall();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'testPort'
				switch( signalIndex )
				{
				case PhoneTest::Base::rti_fail:
					chain2_Fail();
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
		case 3:
			// {{{RME state ':TOP:Failed'
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
			case 1:
				// {{{RME port 'toSystem'
				switch( signalIndex )
				{
				case PhoneProtocol::Base::rti_place_call:
					chain4_FailedCall();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'testPort'
				switch( signalIndex )
				{
				case PhoneTest::Base::rti_recover:
					chain3_Recover();
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

const RTActor_class * PhoneLine_Actor::getActorData( void ) const
{
	return &PhoneLine_Actor::rtg_class;
}

const RTActor_class PhoneLine_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , PhoneLine_Actor::rtg_parent_state
  , &PhoneLine
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , PhoneLine_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId PhoneLine_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTPortDescriptor PhoneLine_Actor::rtg_ports[] =
{
	{
		"toSystem"
	  , (const char *)0
	  , &PhoneProtocol::Base::rt_class
	  , RTOffsetOf( PhoneLine_Actor, PhoneLine_Actor::toSystem )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"testPort"
	  , (const char *)0
	  , &PhoneTest::Base::rt_class
	  , RTOffsetOf( PhoneLine_Actor, PhoneLine_Actor::testPort )
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
