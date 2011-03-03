// {{{RME classifier 'Logical View::CellHandler'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "CellHandler.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <CellHandler.h>
#include <PeripheralIdentifier.h>
extern const RTActorClass Alarm;
extern const RTActorClass Sensor;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"fromSystem"
	  , &HandlerProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_CellHandler_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new CellHandler_Actor( _rts, _ref );
}

const RTActorClass CellHandler =
{
	(const RTActorClass *)0
  , "CellHandler"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_CellHandler_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Idle"
};

static const RTInterfaceDescriptor rtg_interfaces_alarmR1[] =
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

static const RTBindingDescriptor rtg_bindings_alarmR1[] =
{
	{
		0
	  , &HandlerProtocol::Base::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_sensorR1[] =
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

static const RTBindingDescriptor rtg_bindings_sensorR1[] =
{
	{
		0
	  , &HandlerProtocol::Base::rt_class
	}
};

const RTTypeModifier rtg_tm_CellHandler_Actor_alarmResponded =
{
	RTNumberConstant
  , (ALARMS_PER_CELL)
  , 0
};

const RTTypeModifier rtg_tm_CellHandler_Actor_sensorResponded =
{
	RTNumberConstant
  , (SENSORS_PER_CELL)
  , 0
};

#define SUPER RTActor

CellHandler_Actor::CellHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

CellHandler_Actor::~CellHandler_Actor( void )
{
}

int CellHandler_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// fromSystem
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &fromSystem;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int CellHandler_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// alarmR1
		switch( rtg_portId )
		{
		case 0:
			// fromCell
			if( rtg_repIndex < 3 )
			{
				// toAlarms
				rtg_end.port = &toAlarms;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 2:
		// sensorR1
		switch( rtg_portId )
		{
		case 0:
			// fromCell
			if( rtg_repIndex < 3 )
			{
				// toSensors
				rtg_end.port = &toSensors;
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

// {{{RME transition ':TOP:Idle:J4D6D55480002:AlarmResponded'
INLINE_METHODS void CellHandler_Actor::transition1_AlarmResponded( const void * rtdata, HandlerProtocol::Base * rtport )
{
	// {{{USR
	int alarmIndex = msg->sapIndex0();
	this->alarmResponded[alarmIndex] = true; 
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J4D6D5594019B:SensorResponded'
INLINE_METHODS void CellHandler_Actor::transition2_SensorResponded( const void * rtdata, HandlerProtocol::Base * rtport )
{
	// {{{USR
	int sensorIndex = msg->sapIndex0();
	this->sensorResponded[sensorIndex] = true; 
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void CellHandler_Actor::transition3_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	int i;

	this->cellIndex = 0;

	for(i = 0; i < ALARMS_PER_CELL; i++) {
		this->alarmResponded[i] = false;
	}

	for(i = 0; i < SENSORS_PER_CELL; i++) {
		this->sensorResponded[i] = false;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J4D6D5A9E003E:LaunchSelfTest'
INLINE_METHODS void CellHandler_Actor::transition4_LaunchSelfTest( const void * rtdata, HandlerProtocol::Conjugate * rtport )
{
	// {{{USR
	int i;

	for(i = 0; i < ALARMS_PER_CELL; i++) {
		this->alarmResponded[i] = false;
	}

	for(i = 0; i < SENSORS_PER_CELL; i++) {
		this->sensorResponded[i] = false;
	}

	toAlarms.selftest().send();
	toSensors.selftest().send();

	toTimer.informIn(RTTimespec(CELL_SELFTEST_TIMEOUT, 0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J4D6D5B13013C:SelfTestComplete'
INLINE_METHODS void CellHandler_Actor::transition5_SelfTestComplete( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	int i;

	for(i = 0; i < ALARMS_PER_CELL; i++) {
		if(this->alarmResponded[i] == false) {
			PeripheralIdentifier failedAlarm;
			failedAlarm.peripheralType = TYPE_ALARM;
			failedAlarm.cellIndex = this->cellIndex;
			failedAlarm.peripheralIndex = i;
			fromSystem.failed(failedAlarm).send();
		}
	}

	for(i = 0; i < SENSORS_PER_CELL; i++) {
		if(this->sensorResponded[i] == false) {
			PeripheralIdentifier failedSensor;
			failedSensor.peripheralType = TYPE_SENSOR;
			failedSensor.cellIndex = this->cellIndex;
			failedSensor.peripheralIndex = i;
			fromSystem.failed(failedSensor).send();
		}
	}

	fromSystem.heartbeat().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J4D6D5EA20159:Arm'
INLINE_METHODS void CellHandler_Actor::transition6_Arm( const void * rtdata, HandlerProtocol::Conjugate * rtport )
{
	// {{{USR
	toAlarms.arm().send();
	toSensors.arm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J4D6D5ED400ED:Disarm'
INLINE_METHODS void CellHandler_Actor::transition7_Disarm( const void * rtdata, HandlerProtocol::Conjugate * rtport )
{
	// {{{USR
	toAlarms.disarm().send();
	toSensors.disarm().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J4D6D5EF80284:SetCellIndex'
INLINE_METHODS void CellHandler_Actor::transition8_SetCellIndex( const int * rtdata, HandlerProtocol::Conjugate * rtport )
{
	// {{{USR
	const int & index = *rtdata;
	this->cellIndex = index;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J4D6D5F8802F6:BreakInTriggered'
INLINE_METHODS void CellHandler_Actor::transition9_BreakInTriggered( const PeripheralIdentifier * rtdata, HandlerProtocol::Base * rtport )
{
	// {{{USR
	int portIndex = msg->sapIndex0();
	String identifier = char(cellIndex) + "test";
	PeripheralIdentifier ident;
	ident.peripheralType = TYPE_SENSOR;
	ident.cellIndex = this->cellIndex;
	ident.peripheralIndex = portIndex;
	fromSystem.breakin(ident).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J4D6D5FF900B8:SoundAlarms'
INLINE_METHODS void CellHandler_Actor::transition10_SoundAlarms( const void * rtdata, HandlerProtocol::Conjugate * rtport )
{
	// {{{USR
	toAlarms.trigger().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void CellHandler_Actor::chain3_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition3_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CellHandler_Actor::chain6_Arm( void )
{
	// transition ':TOP:Idle:J4D6D5EA20159:Arm'
	rtgChainBegin( 2, "Arm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_Arm( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CellHandler_Actor::chain7_Disarm( void )
{
	// transition ':TOP:Idle:J4D6D5ED400ED:Disarm'
	rtgChainBegin( 2, "Disarm" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_Disarm( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CellHandler_Actor::chain4_LaunchSelfTest( void )
{
	// transition ':TOP:Idle:J4D6D5A9E003E:LaunchSelfTest'
	rtgChainBegin( 2, "LaunchSelfTest" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_LaunchSelfTest( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CellHandler_Actor::chain10_SoundAlarms( void )
{
	// transition ':TOP:Idle:J4D6D5FF900B8:SoundAlarms'
	rtgChainBegin( 2, "SoundAlarms" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition10_SoundAlarms( msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CellHandler_Actor::chain8_SetCellIndex( void )
{
	// transition ':TOP:Idle:J4D6D5EF80284:SetCellIndex'
	rtgChainBegin( 2, "SetCellIndex" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_SetCellIndex( (const int *)msg->data, (HandlerProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CellHandler_Actor::chain1_AlarmResponded( void )
{
	// transition ':TOP:Idle:J4D6D55480002:AlarmResponded'
	rtgChainBegin( 2, "AlarmResponded" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition1_AlarmResponded( msg->data, (HandlerProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CellHandler_Actor::chain2_SensorResponded( void )
{
	// transition ':TOP:Idle:J4D6D5594019B:SensorResponded'
	rtgChainBegin( 2, "SensorResponded" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_SensorResponded( msg->data, (HandlerProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CellHandler_Actor::chain9_BreakInTriggered( void )
{
	// transition ':TOP:Idle:J4D6D5F8802F6:BreakInTriggered'
	rtgChainBegin( 2, "BreakInTriggered" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition9_BreakInTriggered( (const PeripheralIdentifier *)msg->data, (HandlerProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CellHandler_Actor::chain5_SelfTestComplete( void )
{
	// transition ':TOP:Idle:J4D6D5B13013C:SelfTestComplete'
	rtgChainBegin( 2, "SelfTestComplete" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_SelfTestComplete( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void CellHandler_Actor::rtsBehavior( int signalIndex, int portIndex )
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
					chain3_Initial();
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
			// {{{RME state ':TOP:Idle'
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
				// {{{RME port 'fromSystem'
				switch( signalIndex )
				{
				case HandlerProtocol::Conjugate::rti_arm:
					chain6_Arm();
					return;
				case HandlerProtocol::Conjugate::rti_disarm:
					chain7_Disarm();
					return;
				case HandlerProtocol::Conjugate::rti_selftest:
					chain4_LaunchSelfTest();
					return;
				case HandlerProtocol::Conjugate::rti_trigger:
					chain10_SoundAlarms();
					return;
				case HandlerProtocol::Conjugate::rti_set_cell_index:
					chain8_SetCellIndex();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'toAlarms'
				switch( signalIndex )
				{
				case HandlerProtocol::Base::rti_heartbeat:
					chain1_AlarmResponded();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'toSensors'
				switch( signalIndex )
				{
				case HandlerProtocol::Base::rti_heartbeat:
					chain2_SensorResponded();
					return;
				case HandlerProtocol::Base::rti_breakin:
					chain9_BreakInTriggered();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'toTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain5_SelfTestComplete();
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

const RTActor_class * CellHandler_Actor::getActorData( void ) const
{
	return &CellHandler_Actor::rtg_class;
}

const RTActor_class CellHandler_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , CellHandler_Actor::rtg_parent_state
  , &CellHandler
  , 2
  , CellHandler_Actor::rtg_capsule_roles
  , 4
  , CellHandler_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 3
  , CellHandler_Actor::rtg_CellHandler_fields
};

const RTStateId CellHandler_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor CellHandler_Actor::rtg_capsule_roles[] =
{
	{
		"alarmR1"
	  , &Alarm
	  , RTOffsetOf( CellHandler_Actor, alarmR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 3 // cardinality
	  , 2
	  , rtg_interfaces_alarmR1
	  , 1
	  , rtg_bindings_alarmR1
	}
  , {
		"sensorR1"
	  , &Sensor
	  , RTOffsetOf( CellHandler_Actor, sensorR1 )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 3 // cardinality
	  , 2
	  , rtg_interfaces_sensorR1
	  , 1
	  , rtg_bindings_sensorR1
	}
};

const RTPortDescriptor CellHandler_Actor::rtg_ports[] =
{
	{
		"fromSystem"
	  , (const char *)0
	  , &HandlerProtocol::Conjugate::rt_class
	  , RTOffsetOf( CellHandler_Actor, CellHandler_Actor::fromSystem )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"toAlarms"
	  , (const char *)0
	  , &HandlerProtocol::Base::rt_class
	  , RTOffsetOf( CellHandler_Actor, CellHandler_Actor::toAlarms )
	  , 3 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toSensors"
	  , (const char *)0
	  , &HandlerProtocol::Base::rt_class
	  , RTOffsetOf( CellHandler_Actor, CellHandler_Actor::toSensors )
	  , 3 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"toTimer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( CellHandler_Actor, CellHandler_Actor::toTimer )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor CellHandler_Actor::rtg_CellHandler_fields[] =
{
	// {{{RME classAttribute 'cellIndex'
	{
		"cellIndex"
	  , RTOffsetOf( CellHandler_Actor, cellIndex )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'alarmResponded'
  , {
		"alarmResponded"
	  , RTOffsetOf( CellHandler_Actor, alarmResponded[ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_CellHandler_Actor_alarmResponded
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'sensorResponded'
  , {
		"sensorResponded"
	  , RTOffsetOf( CellHandler_Actor, sensorResponded[ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_CellHandler_Actor_sensorResponded
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
