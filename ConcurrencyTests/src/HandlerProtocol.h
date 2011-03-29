// {{{RME classifier 'Logical View::HandlerProtocol'

#ifndef HandlerProtocol_H
#define HandlerProtocol_H

#ifdef PRAGMA
#pragma interface "HandlerProtocol.h"
#endif

#include <RTSystem/ConcurrencyTests.h>
#include <PeripheralIdentifier.h>

struct HandlerProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_heartbeat = rtiLast_RTRootProtocol + 1
		  , rti_breakin
		  , rti_failed
		};

	protected:
		enum { rtiLast_HandlerProtocol = rti_failed };

	public:
		inline RTInSignal heartbeat( void );
		inline RTInSignal breakin( void );
		inline RTInSignal failed( void );
		inline RTOutSignal arm( void );
		inline RTOutSignal disarm( void );
		inline RTOutSignal selftest( void );
		inline RTOutSignal trigger( void );
		inline RTOutSignal set_cell_index( const int & data );
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
			rti_arm = rtiLast_RTRootProtocol + 1
		  , rti_disarm
		  , rti_selftest
		  , rti_trigger
		  , rti_set_cell_index
		};

	protected:
		enum { rtiLast_HandlerProtocol = rti_set_cell_index };

	public:
		inline RTInSignal arm( void );
		inline RTInSignal disarm( void );
		inline RTInSignal selftest( void );
		inline RTInSignal trigger( void );
		inline RTInSignal set_cell_index( void );
		inline RTOutSignal heartbeat( void );
		inline RTOutSignal breakin( const RTTypedValue_PeripheralIdentifier & data );
		inline RTOutSignal failed( const RTTypedValue_PeripheralIdentifier & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline HandlerProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline HandlerProtocol::Base::~Base( void )
{
}

inline RTInSignal HandlerProtocol::Base::heartbeat( void )
{
	return RTInSignal( this, rti_heartbeat );
}

inline RTInSignal HandlerProtocol::Base::breakin( void )
{
	return RTInSignal( this, rti_breakin );
}

inline RTInSignal HandlerProtocol::Base::failed( void )
{
	return RTInSignal( this, rti_failed );
}

inline RTOutSignal HandlerProtocol::Base::arm( void )
{
	return RTOutSignal( this, Conjugate::rti_arm, (const void *)0, &RTType_void );
}

inline RTOutSignal HandlerProtocol::Base::disarm( void )
{
	return RTOutSignal( this, Conjugate::rti_disarm, (const void *)0, &RTType_void );
}

inline RTOutSignal HandlerProtocol::Base::selftest( void )
{
	return RTOutSignal( this, Conjugate::rti_selftest, (const void *)0, &RTType_void );
}

inline RTOutSignal HandlerProtocol::Base::trigger( void )
{
	return RTOutSignal( this, Conjugate::rti_trigger, (const void *)0, &RTType_void );
}

inline RTOutSignal HandlerProtocol::Base::set_cell_index( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_set_cell_index, &data, &RTType_int );
}

inline HandlerProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline HandlerProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal HandlerProtocol::Conjugate::arm( void )
{
	return RTInSignal( this, rti_arm );
}

inline RTInSignal HandlerProtocol::Conjugate::disarm( void )
{
	return RTInSignal( this, rti_disarm );
}

inline RTInSignal HandlerProtocol::Conjugate::selftest( void )
{
	return RTInSignal( this, rti_selftest );
}

inline RTInSignal HandlerProtocol::Conjugate::trigger( void )
{
	return RTInSignal( this, rti_trigger );
}

inline RTInSignal HandlerProtocol::Conjugate::set_cell_index( void )
{
	return RTInSignal( this, rti_set_cell_index );
}

inline RTOutSignal HandlerProtocol::Conjugate::heartbeat( void )
{
	return RTOutSignal( this, Base::rti_heartbeat, (const void *)0, &RTType_void );
}

inline RTOutSignal HandlerProtocol::Conjugate::breakin( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Base::rti_breakin, data.data, data.type );
}

inline RTOutSignal HandlerProtocol::Conjugate::failed( const RTTypedValue_PeripheralIdentifier & data )
{
	return RTOutSignal( this, Base::rti_failed, data.data, data.type );
}

#endif /* HandlerProtocol_H */

// }}}RME
