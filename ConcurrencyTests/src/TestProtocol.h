// {{{RME classifier 'Logical View::TestProtocol'

#ifndef TestProtocol_H
#define TestProtocol_H

#ifdef PRAGMA
#pragma interface "TestProtocol.h"
#endif

#include <RTSystem/ConcurrencyTests.h>
#include <PeripheralIdentifier.h>

struct TestProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_breakin = rtiLast_RTRootProtocol + 1
		  , rti_disarmed
		  , rti_failed
		  , rti_armed
		  , rti_selfTestComplete
		  , rti_display_string
		  , rti_enabled
		  , rti_disabled
		  , rti_selftest_passed
		  , rti_alarms_triggered
		  , rti_selftest_triggered
		};

	protected:
		enum { rtiLast_TestProtocol = rti_selftest_triggered };

	public:
		inline RTInSignal breakin( void );
		inline RTInSignal disarmed( void );
		inline RTInSignal failed( void );
		inline RTInSignal armed( void );
		inline RTInSignal selfTestComplete( void );
		inline RTInSignal display_string( void );
		inline RTInSignal enabled( void );
		inline RTInSignal disabled( void );
		inline RTInSignal selftest_passed( void );
		inline RTInSignal alarms_triggered( void );
		inline RTInSignal selftest_triggered( void );
		inline RTOutSignal password_entered( const RTTypedValue_RTString & data );
		inline RTOutSignal arm_pressed( void );
		inline RTOutSignal disarm_pressed( void );
		inline RTOutSignal failed( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal enabled_pressed( void );
		inline RTOutSignal disabled_pressed( void );
		inline RTOutSignal breakin( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal disarm( void );
		inline RTOutSignal call_failed( void );
		inline RTOutSignal arm( void );
		inline RTOutSignal alarm( void );
		inline RTOutSignal selfTest( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum
		{
			rti_password_entered = rtiLast_RTRootProtocol + 1
		  , rti_arm_pressed
		  , rti_disarm_pressed
		  , rti_failed
		  , rti_enabled_pressed
		  , rti_disabled_pressed
		  , rti_breakin
		  , rti_disarm
		  , rti_call_failed
		  , rti_arm
		  , rti_alarm
		  , rti_selfTest
		};

	protected:
		enum { rtiLast_TestProtocol = rti_selfTest };

	public:
		inline RTInSignal password_entered( void );
		inline RTInSignal arm_pressed( void );
		inline RTInSignal disarm_pressed( void );
		inline RTInSignal failed( void );
		inline RTInSignal enabled_pressed( void );
		inline RTInSignal disabled_pressed( void );
		inline RTInSignal breakin( void );
		inline RTInSignal disarm( void );
		inline RTInSignal call_failed( void );
		inline RTInSignal arm( void );
		inline RTInSignal alarm( void );
		inline RTInSignal selfTest( void );
		inline RTOutSignal breakin( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal disarmed( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal failed( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal armed( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal selfTestComplete( void );
		inline RTOutSignal display_string( const RTTypedValue_RTString & data );
		inline RTOutSignal enabled( void );
		inline RTOutSignal disabled( void );
		inline RTOutSignal selftest_passed( void );
		inline RTOutSignal alarms_triggered( void );
		inline RTOutSignal selftest_triggered( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline TestProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline TestProtocol::Base::~Base( void )
{
}

inline RTInSignal TestProtocol::Base::breakin( void )
{
	return RTInSignal( this, rti_breakin );
}

inline RTInSignal TestProtocol::Base::disarmed( void )
{
	return RTInSignal( this, rti_disarmed );
}

inline RTInSignal TestProtocol::Base::failed( void )
{
	return RTInSignal( this, rti_failed );
}

inline RTInSignal TestProtocol::Base::armed( void )
{
	return RTInSignal( this, rti_armed );
}

inline RTInSignal TestProtocol::Base::selfTestComplete( void )
{
	return RTInSignal( this, rti_selfTestComplete );
}

inline RTInSignal TestProtocol::Base::display_string( void )
{
	return RTInSignal( this, rti_display_string );
}

inline RTInSignal TestProtocol::Base::enabled( void )
{
	return RTInSignal( this, rti_enabled );
}

inline RTInSignal TestProtocol::Base::disabled( void )
{
	return RTInSignal( this, rti_disabled );
}

inline RTInSignal TestProtocol::Base::selftest_passed( void )
{
	return RTInSignal( this, rti_selftest_passed );
}

inline RTInSignal TestProtocol::Base::alarms_triggered( void )
{
	return RTInSignal( this, rti_alarms_triggered );
}

inline RTInSignal TestProtocol::Base::selftest_triggered( void )
{
	return RTInSignal( this, rti_selftest_triggered );
}

inline RTOutSignal TestProtocol::Base::password_entered( const RTTypedValue_RTString & data )
{
	return RTOutSignal( this, Conjugate::rti_password_entered, data.data, data.type );
}

inline RTOutSignal TestProtocol::Base::arm_pressed( void )
{
	return RTOutSignal( this, Conjugate::rti_arm_pressed, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Base::disarm_pressed( void )
{
	return RTOutSignal( this, Conjugate::rti_disarm_pressed, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Base::failed( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Conjugate::rti_failed, data.data, data.type );
}

inline RTOutSignal TestProtocol::Base::enabled_pressed( void )
{
	return RTOutSignal( this, Conjugate::rti_enabled_pressed, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Base::disabled_pressed( void )
{
	return RTOutSignal( this, Conjugate::rti_disabled_pressed, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Base::breakin( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Conjugate::rti_breakin, data.data, data.type );
}

inline RTOutSignal TestProtocol::Base::disarm( void )
{
	return RTOutSignal( this, Conjugate::rti_disarm, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Base::call_failed( void )
{
	return RTOutSignal( this, Conjugate::rti_call_failed, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Base::arm( void )
{
	return RTOutSignal( this, Conjugate::rti_arm, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Base::alarm( void )
{
	return RTOutSignal( this, Conjugate::rti_alarm, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Base::selfTest( void )
{
	return RTOutSignal( this, Conjugate::rti_selfTest, (const void *)0, &RTType_void );
}

inline TestProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline TestProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal TestProtocol::Conjugate::password_entered( void )
{
	return RTInSignal( this, rti_password_entered );
}

inline RTInSignal TestProtocol::Conjugate::arm_pressed( void )
{
	return RTInSignal( this, rti_arm_pressed );
}

inline RTInSignal TestProtocol::Conjugate::disarm_pressed( void )
{
	return RTInSignal( this, rti_disarm_pressed );
}

inline RTInSignal TestProtocol::Conjugate::failed( void )
{
	return RTInSignal( this, rti_failed );
}

inline RTInSignal TestProtocol::Conjugate::enabled_pressed( void )
{
	return RTInSignal( this, rti_enabled_pressed );
}

inline RTInSignal TestProtocol::Conjugate::disabled_pressed( void )
{
	return RTInSignal( this, rti_disabled_pressed );
}

inline RTInSignal TestProtocol::Conjugate::breakin( void )
{
	return RTInSignal( this, rti_breakin );
}

inline RTInSignal TestProtocol::Conjugate::disarm( void )
{
	return RTInSignal( this, rti_disarm );
}

inline RTInSignal TestProtocol::Conjugate::call_failed( void )
{
	return RTInSignal( this, rti_call_failed );
}

inline RTInSignal TestProtocol::Conjugate::arm( void )
{
	return RTInSignal( this, rti_arm );
}

inline RTInSignal TestProtocol::Conjugate::alarm( void )
{
	return RTInSignal( this, rti_alarm );
}

inline RTInSignal TestProtocol::Conjugate::selfTest( void )
{
	return RTInSignal( this, rti_selfTest );
}

inline RTOutSignal TestProtocol::Conjugate::breakin( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Base::rti_breakin, data.data, data.type );
}

inline RTOutSignal TestProtocol::Conjugate::disarmed( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Base::rti_disarmed, data.data, data.type );
}

inline RTOutSignal TestProtocol::Conjugate::failed( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Base::rti_failed, data.data, data.type );
}

inline RTOutSignal TestProtocol::Conjugate::armed( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Base::rti_armed, data.data, data.type );
}

inline RTOutSignal TestProtocol::Conjugate::selfTestComplete( void )
{
	return RTOutSignal( this, Base::rti_selfTestComplete, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Conjugate::display_string( const RTTypedValue_RTString & data )
{
	return RTOutSignal( this, Base::rti_display_string, data.data, data.type );
}

inline RTOutSignal TestProtocol::Conjugate::enabled( void )
{
	return RTOutSignal( this, Base::rti_enabled, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Conjugate::disabled( void )
{
	return RTOutSignal( this, Base::rti_disabled, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Conjugate::selftest_passed( void )
{
	return RTOutSignal( this, Base::rti_selftest_passed, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Conjugate::alarms_triggered( void )
{
	return RTOutSignal( this, Base::rti_alarms_triggered, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Conjugate::selftest_triggered( void )
{
	return RTOutSignal( this, Base::rti_selftest_triggered, (const void *)0, &RTType_void );
}

#endif /* TestProtocol_H */

// }}}RME
