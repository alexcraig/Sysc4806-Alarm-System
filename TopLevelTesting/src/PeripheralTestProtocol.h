// {{{RME classifier 'Logical View::PeripheralTestProtocol'

#ifndef PeripheralTestProtocol_H
#define PeripheralTestProtocol_H

#ifdef PRAGMA
#pragma interface "PeripheralTestProtocol.h"
#endif

#include <RTSystem/TopLevelTesting.h>

struct PeripheralTestProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_fail = rtiLast_RTRootProtocol + 1
		  , rti_trigger
		  , rti_recover
		};

	protected:
		enum { rtiLast_PeripheralTestProtocol = rti_recover };

	public:
		inline RTInSignal fail( void );
		inline RTInSignal trigger( void );
		inline RTInSignal recover( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );

	protected:
		enum { rtiLast_PeripheralTestProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal fail( void );
		inline RTOutSignal trigger( void );
		inline RTOutSignal recover( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline PeripheralTestProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline PeripheralTestProtocol::Base::~Base( void )
{
}

inline RTInSignal PeripheralTestProtocol::Base::fail( void )
{
	return RTInSignal( this, rti_fail );
}

inline RTInSignal PeripheralTestProtocol::Base::trigger( void )
{
	return RTInSignal( this, rti_trigger );
}

inline RTInSignal PeripheralTestProtocol::Base::recover( void )
{
	return RTInSignal( this, rti_recover );
}

inline PeripheralTestProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline PeripheralTestProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal PeripheralTestProtocol::Conjugate::fail( void )
{
	return RTOutSignal( this, Base::rti_fail, (const void *)0, &RTType_void );
}

inline RTOutSignal PeripheralTestProtocol::Conjugate::trigger( void )
{
	return RTOutSignal( this, Base::rti_trigger, (const void *)0, &RTType_void );
}

inline RTOutSignal PeripheralTestProtocol::Conjugate::recover( void )
{
	return RTOutSignal( this, Base::rti_recover, (const void *)0, &RTType_void );
}

#endif /* PeripheralTestProtocol_H */

// }}}RME
