// {{{RME classifier 'Logical View::Sensor'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Sensor.h"
#endif

#include <RTSystem/TopLevelTesting.h>
#include <Sensor.h>
#include <CellConfiguration.h>

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
};

static RTActor * new_Sensor_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Sensor_Actor( _rts, _ref );
}

const RTActorClass Sensor =
{
	(const RTActorClass *)0
  , "Sensor"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_Sensor_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Disarmed"
  , "Armed"
  , "Failed"
};

#define SUPER RTActor

Sensor_Actor::Sensor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Sensor_Actor::~Sensor_Actor( void )
{
}

int Sensor_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
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
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void Sensor_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	this->armedState = false;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Disarmed:J4D6D3EC802CD:ArmSensor'
INLINE_METHODS void Sensor_Actor::transition2_ArmSensor( const void * rtdata, HandlerProtocol::Conjugate * rtport )
{
	// {{{USR
	this->armedState = true;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Armed:J4D6D3F0B0223:DisarmSensor'
INLINE_METHODS void Sensor_Actor::transition3_DisarmSensor( const void * rtdata, HandlerProtocol::Conjugate * rtport )
{
	// {{{USR
	this->armedState = false;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Armed:J4D6D3F2101F6:DetectBreakin'
INLINE_METHODS void Sensor_Actor::transition4_DetectBreakin( const void * rtdata, PeripheralTest::Base * rtport )
{
	// {{{USR
	PeripheralIdentifier ident;
	ident.peripheralType = TYPE_SENSOR;
	ident.cellIndex = 0;
	ident.peripheralIndex = 0;

	// NOTE: This PeripheralIdentifier is meaningless and will be
	// discarded without being read by the CellHandler.

	fromCell.breakin(ident).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Failed:J4D6D40E80177:RecoverDisarmed' guard '1'
INLINE_METHODS int Sensor_Actor::guard5_RecoverDisarmed_event1( const void * rtdata, PeripheralTest::Base * rtport )
{
	// {{{USR
	return (this->armedState == false);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Failed:J4D6D41150272:RecoverArmed' guard '1'
INLINE_METHODS int Sensor_Actor::guard6_RecoverArmed_event1( const void * rtdata, PeripheralTest::Base * rtport )
{
	// {{{USR
	return (this->armedState == true);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Sensor_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Sensor_Actor::chain2_ArmSensor( void )
{
	// transition ':TOP:Disarmed:J4D6D3EC802CD:ArmSensor'
	rtgChainBegin( 2, "ArmSensor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_ArmSensor( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Sensor_Actor::chain8_FailDisarmed( void )
{
	// transition ':TOP:Disarmed:J4D6D431903E6:FailDisarmed'
	rtgChainBegin( 2, "FailDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Sensor_Actor::chain3_DisarmSensor( void )
{
	// transition ':TOP:Armed:J4D6D3F0B0223:DisarmSensor'
	rtgChainBegin( 3, "DisarmSensor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_DisarmSensor( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Sensor_Actor::chain7_FailArmed( void )
{
	// transition ':TOP:Armed:J4D6D4300006B:FailArmed'
	rtgChainBegin( 3, "FailArmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Sensor_Actor::chain4_DetectBreakin( void )
{
	// transition ':TOP:Armed:J4D6D3F2101F6:DetectBreakin'
	rtgChainBegin( 3, "DetectBreakin" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_DetectBreakin( msg->data, (PeripheralTest::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Sensor_Actor::chain5_RecoverDisarmed( void )
{
	// transition ':TOP:Failed:J4D6D40E80177:RecoverDisarmed'
	rtgChainBegin( 4, "RecoverDisarmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Sensor_Actor::chain6_RecoverArmed( void )
{
	// transition ':TOP:Failed:J4D6D41150272:RecoverArmed'
	rtgChainBegin( 4, "RecoverArmed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

void Sensor_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Disarmed'
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
					chain2_ArmSensor();
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
					chain8_FailDisarmed();
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
			// {{{RME state ':TOP:Armed'
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
					chain3_DisarmSensor();
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
					chain4_DetectBreakin();
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
			case 2:
				// {{{RME port 'testPort'
				switch( signalIndex )
				{
				case PeripheralTest::Base::rti_recover:
					if( guard5_RecoverDisarmed_event1( msg->data, (PeripheralTest::Base *)msg->sap() ) )
					{
						chain5_RecoverDisarmed();
						return;
					}
					if( guard6_RecoverArmed_event1( msg->data, (PeripheralTest::Base *)msg->sap() ) )
					{
						chain6_RecoverArmed();
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
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * Sensor_Actor::getActorData( void ) const
{
	return &Sensor_Actor::rtg_class;
}

const RTActor_class Sensor_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 4
  , Sensor_Actor::rtg_parent_state
  , &Sensor
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , Sensor_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , Sensor_Actor::rtg_Sensor_fields
};

const RTStateId Sensor_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
};

const RTPortDescriptor Sensor_Actor::rtg_ports[] =
{
	{
		"fromCell"
	  , (const char *)0
	  , &HandlerProtocol::Conjugate::rt_class
	  , RTOffsetOf( Sensor_Actor, Sensor_Actor::fromCell )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"testPort"
	  , (const char *)0
	  , &PeripheralTest::Base::rt_class
	  , RTOffsetOf( Sensor_Actor, Sensor_Actor::testPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor Sensor_Actor::rtg_Sensor_fields[] =
{
	// {{{RME classAttribute 'armedState'
	{
		"armedState"
	  , RTOffsetOf( Sensor_Actor, armedState )
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
