// {{{RME classifier 'Logical View::KeypadProtocol'

#ifndef KeypadProtocol_H
#define KeypadProtocol_H

#ifdef PRAGMA
#pragma interface "KeypadProtocol.h"
#endif

#include <RTSystem/TestSystemHandler.h>

struct KeypadProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_KeypadProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal password_entered( const RTTypedValue_RTString & data );
		inline RTOutSignal arm_pressed( void );
		inline RTOutSignal disarm_pressed( void );
		inline RTOutSignal enabled_pressed( void );
		inline RTOutSignal disabled_pressed( void );
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
		  , rti_enabled_pressed
		  , rti_disabled_pressed
		};

	protected:
		enum { rtiLast_KeypadProtocol = rti_disabled_pressed };

	public:
		inline RTInSignal password_entered( void );
		inline RTInSignal arm_pressed( void );
		inline RTInSignal disarm_pressed( void );
		inline RTInSignal enabled_pressed( void );
		inline RTInSignal disabled_pressed( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline KeypadProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline KeypadProtocol::Base::~Base( void )
{
}

inline RTOutSignal KeypadProtocol::Base::password_entered( const RTTypedValue_RTString & data )
{
	return RTOutSignal( this, Conjugate::rti_password_entered, data.data, data.type );
}

inline RTOutSignal KeypadProtocol::Base::arm_pressed( void )
{
	return RTOutSignal( this, Conjugate::rti_arm_pressed, (const void *)0, &RTType_void );
}

inline RTOutSignal KeypadProtocol::Base::disarm_pressed( void )
{
	return RTOutSignal( this, Conjugate::rti_disarm_pressed, (const void *)0, &RTType_void );
}

inline RTOutSignal KeypadProtocol::Base::enabled_pressed( void )
{
	return RTOutSignal( this, Conjugate::rti_enabled_pressed, (const void *)0, &RTType_void );
}

inline RTOutSignal KeypadProtocol::Base::disabled_pressed( void )
{
	return RTOutSignal( this, Conjugate::rti_disabled_pressed, (const void *)0, &RTType_void );
}

inline KeypadProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline KeypadProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal KeypadProtocol::Conjugate::password_entered( void )
{
	return RTInSignal( this, rti_password_entered );
}

inline RTInSignal KeypadProtocol::Conjugate::arm_pressed( void )
{
	return RTInSignal( this, rti_arm_pressed );
}

inline RTInSignal KeypadProtocol::Conjugate::disarm_pressed( void )
{
	return RTInSignal( this, rti_disarm_pressed );
}

inline RTInSignal KeypadProtocol::Conjugate::enabled_pressed( void )
{
	return RTInSignal( this, rti_enabled_pressed );
}

inline RTInSignal KeypadProtocol::Conjugate::disabled_pressed( void )
{
	return RTInSignal( this, rti_disabled_pressed );
}

#endif /* KeypadProtocol_H */

// }}}RME
