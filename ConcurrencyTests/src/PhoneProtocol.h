// {{{RME classifier 'Logical View::PhoneProtocol'

#ifndef PhoneProtocol_H
#define PhoneProtocol_H

#ifdef PRAGMA
#pragma interface "PhoneProtocol.h"
#endif

#include <RTSystem/ConcurrencyTests.h>

struct PhoneProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_place_call = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_PhoneProtocol = rti_place_call };

	public:
		inline RTInSignal place_call( void );
		inline RTOutSignal call_placed( void );
		inline RTOutSignal call_failed( void );
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
			rti_call_placed = rtiLast_RTRootProtocol + 1
		  , rti_call_failed
		};

	protected:
		enum { rtiLast_PhoneProtocol = rti_call_failed };

	public:
		inline RTInSignal call_placed( void );
		inline RTInSignal call_failed( void );
		inline RTOutSignal place_call( const RTTypedValue_RTString & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline PhoneProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline PhoneProtocol::Base::~Base( void )
{
}

inline RTInSignal PhoneProtocol::Base::place_call( void )
{
	return RTInSignal( this, rti_place_call );
}

inline RTOutSignal PhoneProtocol::Base::call_placed( void )
{
	return RTOutSignal( this, Conjugate::rti_call_placed, (const void *)0, &RTType_void );
}

inline RTOutSignal PhoneProtocol::Base::call_failed( void )
{
	return RTOutSignal( this, Conjugate::rti_call_failed, (const void *)0, &RTType_void );
}

inline PhoneProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline PhoneProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal PhoneProtocol::Conjugate::call_placed( void )
{
	return RTInSignal( this, rti_call_placed );
}

inline RTInSignal PhoneProtocol::Conjugate::call_failed( void )
{
	return RTInSignal( this, rti_call_failed );
}

inline RTOutSignal PhoneProtocol::Conjugate::place_call( const RTTypedValue_RTString & data )
{
	return RTOutSignal( this, Base::rti_place_call, data.data, data.type );
}

#endif /* PhoneProtocol_H */

// }}}RME
