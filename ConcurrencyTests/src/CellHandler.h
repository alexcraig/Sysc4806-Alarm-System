// {{{RME classifier 'Logical View::CellHandler'

#ifndef CellHandler_H
#define CellHandler_H

#ifdef PRAGMA
#pragma interface "CellHandler.h"
#endif

#include <RTSystem/ConcurrencyTests.h>
#include <CellConfiguration.h>
#include <HandlerProtocol.h>
#include <TestProtocol.h>
class PeripheralIdentifier;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass CellHandler;

#define SUPER RTActor
class CellHandler_Actor : public RTActor
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME
	// {{{RME classAttribute 'cellIndex'
	int cellIndex;
	// }}}RME
	// {{{RME classAttribute 'alarmResponded'
	mutable bool alarmResponded[ ALARMS_PER_CELL ];
	// }}}RME
	// {{{RME classAttribute 'sensorResponded'
	mutable bool sensorResponded[ SENSORS_PER_CELL ];
	// }}}RME

protected:
	// {{{RME capsuleRole 'alarmR1'
	RTActorRef alarmR1;
	// }}}RME
	// {{{RME capsuleRole 'sensorR1'
	RTActorRef sensorR1;
	// }}}RME
	// {{{RME port 'fromSystem'
	HandlerProtocol::Conjugate fromSystem;
	// }}}RME
	// {{{RME port 'toAlarms'
	HandlerProtocol::Base toAlarms;
	// }}}RME
	// {{{RME port 'toSensors'
	HandlerProtocol::Base toSensors;
	// }}}RME
	// {{{RME port 'toTimer'
	Timing::Base toTimer;
	// }}}RME
	// {{{RME port 'testSystem'
	TestProtocol::Conjugate testSystem;
	// }}}RME
	// {{{RME port 'debugLog'
	Log::Base debugLog;
	// }}}RME
	// {{{RME port 'testSensors'
	TestProtocol::Base testSensors;
	// }}}RME
	// {{{RME port 'testAlarms'
	TestProtocol::Base testAlarms;
	// }}}RME

public:
	CellHandler_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~CellHandler_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Idle:J4D6D55480002:AlarmResponded'
	INLINE_METHODS void transition1_AlarmResponded( const void * rtdata, HandlerProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D6D5594019B:SensorResponded'
	INLINE_METHODS void transition2_SensorResponded( const void * rtdata, HandlerProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition3_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D6D5A9E003E:LaunchSelfTest'
	INLINE_METHODS void transition4_LaunchSelfTest( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D767B6C0125:SelfTestComplete'
	INLINE_METHODS void transition5_SelfTestComplete( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D767B300193:Arm'
	INLINE_METHODS void transition6_Arm( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D767B420116:Disarm'
	INLINE_METHODS void transition7_Disarm( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D6D5EF80284:SetCellIndex'
	INLINE_METHODS void transition8_SetCellIndex( const int * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D767B750154:BreakInTriggered'
	INLINE_METHODS void transition9_BreakInTriggered( const PeripheralIdentifier * rtdata, HandlerProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D767B7D0358:SoundAlarms'
	INLINE_METHODS void transition10_SoundAlarms( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D767BA6025D:testSensorArmed'
	INLINE_METHODS void transition11_testSensorArmed( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D76839C0194:testAlarmActive'
	INLINE_METHODS void transition12_testAlarmActive( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D7FC7AF003F:testAlarmArmed'
	INLINE_METHODS void transition13_testAlarmArmed( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D7FD059008C:testAlarmDisarmed'
	INLINE_METHODS void transition14_testAlarmDisarmed( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J4D7FD0790109:testSensorDisarmed'
	INLINE_METHODS void transition15_testSensorDisarmed( const PeripheralIdentifier * rtdata, TestProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain3_Initial( void );
	INLINE_CHAINS void chain6_Arm( void );
	INLINE_CHAINS void chain7_Disarm( void );
	INLINE_CHAINS void chain4_LaunchSelfTest( void );
	INLINE_CHAINS void chain10_SoundAlarms( void );
	INLINE_CHAINS void chain8_SetCellIndex( void );
	INLINE_CHAINS void chain1_AlarmResponded( void );
	INLINE_CHAINS void chain2_SensorResponded( void );
	INLINE_CHAINS void chain9_BreakInTriggered( void );
	INLINE_CHAINS void chain5_SelfTestComplete( void );
	INLINE_CHAINS void chain15_testSensorDisarmed( void );
	INLINE_CHAINS void chain11_testSensorArmed( void );
	INLINE_CHAINS void chain12_testAlarmActive( void );
	INLINE_CHAINS void chain14_testAlarmDisarmed( void );
	INLINE_CHAINS void chain13_testAlarmArmed( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTComponentDescriptor rtg_capsule_roles[];
	static const RTPortDescriptor rtg_ports[];

public:
	static const RTFieldDescriptor rtg_CellHandler_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* CellHandler_H */

// }}}RME
