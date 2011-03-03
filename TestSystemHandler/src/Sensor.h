// {{{RME classifier 'Logical View::Sensor'

#ifndef Sensor_H
#define Sensor_H

#ifdef PRAGMA
#pragma interface "Sensor.h"
#endif

#include <RTSystem/TestSystemHandler.h>
#include <HandlerProtocol.h>
#include <PeripheralTest.h>
class CellConfiguration;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Sensor;

#define SUPER RTActor
class Sensor_Actor : public RTActor
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

public:
	Sensor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Sensor_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Disarmed:J4D6D3EC802CD:ArmSensor'
	INLINE_METHODS void transition2_ArmSensor( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Armed:J4D6D3F0B0223:DisarmSensor'
	INLINE_METHODS void transition3_DisarmSensor( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Armed:J4D6D3F2101F6:DetectBreakin'
	INLINE_METHODS void transition4_DetectBreakin( const void * rtdata, PeripheralTest::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Failed:J4D6D40E80177:RecoverDisarmed' guard '1'
	INLINE_METHODS int guard5_RecoverDisarmed_event1( const void * rtdata, PeripheralTest::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Failed:J4D6D41150272:RecoverArmed' guard '1'
	INLINE_METHODS int guard6_RecoverArmed_event1( const void * rtdata, PeripheralTest::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Disarmed:J4D6E871202B6:SelfTestDisarmed'
	INLINE_METHODS void transition9_SelfTestDisarmed( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Armed:J4D6E872801AD:SelfTestArmed'
	INLINE_METHODS void transition10_SelfTestArmed( const void * rtdata, HandlerProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_ArmSensor( void );
	INLINE_CHAINS void chain9_SelfTestDisarmed( void );
	INLINE_CHAINS void chain8_FailDisarmed( void );
	INLINE_CHAINS void chain3_DisarmSensor( void );
	INLINE_CHAINS void chain10_SelfTestArmed( void );
	INLINE_CHAINS void chain7_FailArmed( void );
	INLINE_CHAINS void chain4_DetectBreakin( void );
	INLINE_CHAINS void chain5_RecoverDisarmed( void );
	INLINE_CHAINS void chain6_RecoverArmed( void );

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
	static const RTFieldDescriptor rtg_Sensor_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Sensor_H */

// }}}RME
