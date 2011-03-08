// {{{RME classifier 'Logical View::Alarm'

#ifndef Alarm_H
#define Alarm_H

#ifdef PRAGMA
#pragma interface "Alarm.h"
#endif

#include <RTSystem/TestCellHandler.h>
#include <HandlerProtocol.h>
#include <PeripheralTest.h>
#include <TestProtocol.h>
class CellConfiguration;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Alarm;

#define SUPER RTActor
class Alarm_Actor : public RTActor
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
	// {{{RME classAttribute 'armedState'
	bool armedState;
	// }}}RME

protected:
	// {{{RME port 'fromCell'
	HandlerProtocol::Conjugate fromCell;
	// }}}RME
	// {{{RME port 'testPort'
	PeripheralTest::Base testPort;
	// }}}RME
	// {{{RME port 'testSystem'
	TestProtocol::Conjugate testSystem;
	// }}}RME

public:
	Alarm_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Alarm_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:Triggered'
	INLINE_METHODS void enter5_Triggered( void );
	// }}}RME
	virtual void enterStateV( void );
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Disarmed:J4D6D43A803CC:ArmAlarm'
	INLINE_METHODS void transition2_ArmAlarm( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Armed:J4D6D43C30330:DisarmAlarm'
	INLINE_METHODS void transition3_DisarmAlarm( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Triggered:J4D6D44320298:DisarmTriggeredAlarm'
	INLINE_METHODS void transition5_DisarmTriggeredAlarm( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Failed:J4D6D44AF01F0:RecoverDisarmed' guard '1'
	INLINE_METHODS int guard8_RecoverDisarmed_event1( const void * rtdata, PeripheralTest::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Failed:J4D6D44CC0099:RecoverArmed' guard '1'
	INLINE_METHODS int guard9_RecoverArmed_event1( const void * rtdata, PeripheralTest::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Disarmed:J4D6E867901BB:SelfTestDisarmed'
	INLINE_METHODS void transition11_SelfTestDisarmed( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Armed:J4D6E86C40093:SelfTestArmed'
	INLINE_METHODS void transition12_SelfTestArmed( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Triggered:J4D6E86EB0287:SelfTestTriggered'
	INLINE_METHODS void transition13_SelfTestTriggered( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain3_DisarmAlarm( void );
	INLINE_CHAINS void chain12_SelfTestArmed( void );
	INLINE_CHAINS void chain4_TriggerAlarm( void );
	INLINE_CHAINS void chain7_FailArmed( void );
	INLINE_CHAINS void chain2_ArmAlarm( void );
	INLINE_CHAINS void chain11_SelfTestDisarmed( void );
	INLINE_CHAINS void chain6_FailDisarmed( void );
	INLINE_CHAINS void chain8_RecoverDisarmed( void );
	INLINE_CHAINS void chain9_RecoverArmed( void );
	INLINE_CHAINS void chain5_DisarmTriggeredAlarm( void );
	INLINE_CHAINS void chain13_SelfTestTriggered( void );
	INLINE_CHAINS void chain10_FailTriggered( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];

public:
	static const RTFieldDescriptor rtg_Alarm_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Alarm_H */

// }}}RME
