// {{{RME classifier 'Logical View::SoundAlarm'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "SoundAlarm.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <SoundAlarm.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"fromCell"
	  , &HandlerProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
  , {
		"testPort"
	  , &PeripheralTest::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"testSystem"
	  , &TestProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_SoundAlarm_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new SoundAlarm_Actor( _rts, _ref );
}

const RTActorClass SoundAlarm =
{
	&Alarm
  , "SoundAlarm"
  , (RTVersionId)0
  , 3
  , rtg_relays
  , new_SoundAlarm_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Armed"
  , "Disarmed"
  , "Failed"
  , "Triggered"
};

#define SUPER Alarm_Actor

SoundAlarm_Actor::SoundAlarm_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: Alarm_Actor( rtg_rts, rtg_ref )
{
}

SoundAlarm_Actor::~SoundAlarm_Actor( void )
{
}

int SoundAlarm_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// fromCell
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &fromCell;
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
	case 2:
		// testSystem
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &testSystem;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return Alarm_Actor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

INLINE_CHAINS void SoundAlarm_Actor::chain1_Initial( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain3_DisarmAlarm( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Armed:J4D6D43C30330:DisarmAlarm'
	rtgChainBegin( 2, "DisarmAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_DisarmAlarm( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain12_SelfTestArmed( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Armed:J4D6E86C40093:SelfTestArmed'
	rtgChainBegin( 2, "SelfTestArmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition12_SelfTestArmed( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain4_TriggerAlarm( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Armed:J4D6D43EA0218:TriggerAlarm'
	rtgChainBegin( 2, "TriggerAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain7_FailArmed( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Armed:J4D6D44A10077:FailArmed'
	rtgChainBegin( 2, "FailArmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain2_ArmAlarm( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Disarmed:J4D6D43A803CC:ArmAlarm'
	rtgChainBegin( 3, "ArmAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_ArmAlarm( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain11_SelfTestDisarmed( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Disarmed:J4D6E867901BB:SelfTestDisarmed'
	rtgChainBegin( 3, "SelfTestDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition11_SelfTestDisarmed( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain6_FailDisarmed( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Disarmed:J4D6D448C0058:FailDisarmed'
	rtgChainBegin( 3, "FailDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain8_RecoverDisarmed( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Failed:J4D6D44AF01F0:RecoverDisarmed'
	rtgChainBegin( 4, "RecoverDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain9_RecoverArmed( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Failed:J4D6D44CC0099:RecoverArmed'
	rtgChainBegin( 4, "RecoverArmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain5_DisarmTriggeredAlarm( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Triggered:J4D6D44320298:DisarmTriggeredAlarm'
	rtgChainBegin( 5, "DisarmTriggeredAlarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_DisarmTriggeredAlarm( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain13_SelfTestTriggered( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Triggered:J4D6E86EB0287:SelfTestTriggered'
	rtgChainBegin( 5, "SelfTestTriggered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition13_SelfTestTriggered( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void SoundAlarm_Actor::chain10_FailTriggered( void )
{
	// classifier 'Logical View::Alarm' transition ':TOP:Triggered:J4D6D44F503D6:FailTriggered'
	rtgChainBegin( 5, "FailTriggered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

void SoundAlarm_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; stateIndex = rtg_parent_state[ stateIndex - 1 ] )
		switch( stateIndex )
		{
		case 1:
			// {{{RME classifier 'Logical View::Alarm' state ':TOP'
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
			// {{{RME classifier 'Logical View::Alarm' state ':TOP:Armed'
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
				// {{{RME port 'fromCell'
				switch( signalIndex )
				{
				case HandlerProtocol::Conjugate::rti_disarm:
					chain3_DisarmAlarm();
					return;
				case HandlerProtocol::Conjugate::rti_selftest:
					chain12_SelfTestArmed();
					return;
				case HandlerProtocol::Conjugate::rti_trigger:
					chain4_TriggerAlarm();
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
				case PeripheralTest::Base::rti_fail:
					chain7_FailArmed();
					return;
				case PeripheralTest::Base::rti_trigger:
					chain4_TriggerAlarm();
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
			// {{{RME classifier 'Logical View::Alarm' state ':TOP:Disarmed'
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
				// {{{RME port 'fromCell'
				switch( signalIndex )
				{
				case HandlerProtocol::Conjugate::rti_arm:
					chain2_ArmAlarm();
					return;
				case HandlerProtocol::Conjugate::rti_selftest:
					chain11_SelfTestDisarmed();
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
				case PeripheralTest::Base::rti_fail:
					chain6_FailDisarmed();
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
		case 4:
			// {{{RME classifier 'Logical View::Alarm' state ':TOP:Failed'
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
				case PeripheralTest::Base::rti_recover:
					if( guard8_RecoverDisarmed_event1( msg->data, (PeripheralTest::Base *)msg->sap() ) )
					{
						chain8_RecoverDisarmed();
						return;
					}
					if( guard9_RecoverArmed_event1( msg->data, (PeripheralTest::Base *)msg->sap() ) )
					{
						chain9_RecoverArmed();
						return;
					}
					break;
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
		case 5:
			// {{{RME classifier 'Logical View::Alarm' state ':TOP:Triggered'
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
				// {{{RME port 'fromCell'
				switch( signalIndex )
				{
				case HandlerProtocol::Conjugate::rti_disarm:
					chain5_DisarmTriggeredAlarm();
					return;
				case HandlerProtocol::Conjugate::rti_selftest:
					chain13_SelfTestTriggered();
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
				case PeripheralTest::Base::rti_fail:
					chain10_FailTriggered();
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

const RTActor_class * SoundAlarm_Actor::getActorData( void ) const
{
	return &SoundAlarm_Actor::rtg_class;
}

const RTActor_class SoundAlarm_Actor::rtg_class =
{
	&Alarm_Actor::rtg_class
  , rtg_state_names
  , 5
  , SoundAlarm_Actor::rtg_parent_state
  , &SoundAlarm
  , 0
  , (const RTComponentDescriptor *)0
  , 3
  , SoundAlarm_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId SoundAlarm_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
};

const RTPortDescriptor SoundAlarm_Actor::rtg_ports[] =
{
	{
		"fromCell"
	  , (const char *)0
	  , &HandlerProtocol::Conjugate::rt_class
	  , RTOffsetOf( SoundAlarm_Actor, Alarm_Actor::fromCell )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"testPort"
	  , (const char *)0
	  , &PeripheralTest::Base::rt_class
	  , RTOffsetOf( SoundAlarm_Actor, Alarm_Actor::testPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"testSystem"
	  , (const char *)0
	  , &TestProtocol::Conjugate::rt_class
	  , RTOffsetOf( SoundAlarm_Actor, Alarm_Actor::testSystem )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
