// {{{RME classifier 'Logical View::TestProtocol'

#ifndef TestProtocol_H
#define TestProtocol_H

#ifdef PRAGMA
#pragma interface "TestProtocol.h"
#endif

#include <RTSystem/TestSystemHandler.h>
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
		  , rti_disarm
		  , rti_failed
		  , rti_armed
		};

	protected:
		enum { rtiLast_TestProtocol = rti_armed };

	public:
		inline RTInSignal breakin( void );
		inline RTSymmetricSignal disarm( void );
		inline RTInSignal failed( void );
		inline RTInSignal armed( void );
		inline RTOutSignal password_entered( const RTTypedValue_RTString & data );
		inline RTOutSignal arm_pressed( void );
		inline RTOutSignal disarm_pressed( void );
		inline RTOutSignal failed( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal enabled_pressed( void );
		inline RTOutSignal disabled_pressed( void );
		inline RTOutSignal breakin( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal call_failed( void );
		inline RTOutSignal arm( void );
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
		};

	protected:
		enum { rtiLast_TestProtocol = rti_arm };

	public:
		inline RTInSignal password_entered( void );
		inline RTInSignal arm_pressed( void );
		inline RTInSignal disarm_pressed( void );
		inline RTInSignal failed( void );
		inline RTInSignal enabled_pressed( void );
		inline RTInSignal disabled_pressed( void );
		inline RTInSignal breakin( void );
		inline RTSymmetricSignal disarm( void );
		inline RTInSignal call_failed( void );
		inline RTInSignal arm( void );
		inline RTOutSignal breakin( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal failed( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal armed( const RTTypedValue_PeripheralIdentifier & data );
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

inline RTSymmetricSignal TestProtocol::Base::disarm( void )
{
	return RTSymmetricSignal( this, rti_disarm, Conjugate::rti_disarm );
}

inline RTInSignal TestProtocol::Base::failed( void )
{
	return RTInSignal( this, rti_failed );
}

inline RTInSignal TestProtocol::Base::armed( void )
{
	return RTInSignal( this, rti_armed );
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

inline RTOutSignal TestProtocol::Base::call_failed( void )
{
	return RTOutSignal( this, Conjugate::rti_call_failed, (const void *)0, &RTType_void );
}

inline RTOutSignal TestProtocol::Base::arm( void )
{
	return RTOutSignal( this, Conjugate::rti_arm, (const void *)0, &RTType_void );
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

inline RTSymmetricSignal TestProtocol::Conjugate::disarm( void )
{
	return RTSymmetricSignal( this, rti_disarm, Base::rti_disarm );
}

inline RTInSignal TestProtocol::Conjugate::call_failed( void )
{
	return RTInSignal( this, rti_call_failed );
}

inline RTInSignal TestProtocol::Conjugate::arm( void )
{
	return RTInSignal( this, rti_arm );
}

inline RTOutSignal TestProtocol::Conjugate::breakin( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Base::rti_breakin, data.data, data.type );
}

inline RTOutSignal TestProtocol::Conjugate::failed( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Base::rti_failed, data.data, data.type );
}

inline RTOutSignal TestProtocol::Conjugate::armed( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Base::rti_armed, data.data, data.type );
}

#endif /* TestProtocol_H */

// }}}RME
