// {{{RME classifier 'Logical View::PeripheralTest'

#ifndef PeripheralTest_H
#define PeripheralTest_H

#ifdef PRAGMA
#pragma interface "PeripheralTest.h"
#endif

#include <RTSystem/TestSystemHandler.h>

struct PeripheralTest
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
		enum { rtiLast_PeripheralTest = rti_recover };

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
		enum { rtiLast_PeripheralTest = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal fail( void );
		inline RTOutSignal trigger( void );
		inline RTOutSignal recover( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline PeripheralTest::Base::Base( void )
	: RTRootProtocol()
{
}

inline PeripheralTest::Base::~Base( void )
{
}

inline RTInSignal PeripheralTest::Base::fail( void )
{
	return RTInSignal( this, rti_fail );
}

inline RTInSignal PeripheralTest::Base::trigger( void )
{
	return RTInSignal( this, rti_trigger );
}

inline RTInSignal PeripheralTest::Base::recover( void )
{
	return RTInSignal( this, rti_recover );
}

inline PeripheralTest::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline PeripheralTest::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal PeripheralTest::Conjugate::fail( void )
{
	return RTOutSignal( this, Base::rti_fail, (const void *)0, &RTType_void );
}

inline RTOutSignal PeripheralTest::Conjugate::trigger( void )
{
	return RTOutSignal( this, Base::rti_trigger, (const void *)0, &RTType_void );
}

inline RTOutSignal PeripheralTest::Conjugate::recover( void )
{
	return RTOutSignal( this, Base::rti_recover, (const void *)0, &RTType_void );
}

#endif /* PeripheralTest_H */

// }}}RME
