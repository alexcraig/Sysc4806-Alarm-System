// {{{RME classifier 'Logical View::PhoneTest'

#ifndef PhoneTest_H
#define PhoneTest_H

#ifdef PRAGMA
#pragma interface "PhoneTest.h"
#endif

#include <RTSystem/TopLevelTesting.h>

struct PhoneTest
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_fail = rtiLast_RTRootProtocol + 1
		  , rti_recover
		};

	protected:
		enum { rtiLast_PhoneTest = rti_recover };

	public:
		inline RTInSignal fail( void );
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
		enum { rtiLast_PhoneTest = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal fail( void );
		inline RTOutSignal recover( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline PhoneTest::Base::Base( void )
	: RTRootProtocol()
{
}

inline PhoneTest::Base::~Base( void )
{
}

inline RTInSignal PhoneTest::Base::fail( void )
{
	return RTInSignal( this, rti_fail );
}

inline RTInSignal PhoneTest::Base::recover( void )
{
	return RTInSignal( this, rti_recover );
}

inline PhoneTest::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline PhoneTest::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal PhoneTest::Conjugate::fail( void )
{
	return RTOutSignal( this, Base::rti_fail, (const void *)0, &RTType_void );
}

inline RTOutSignal PhoneTest::Conjugate::recover( void )
{
	return RTOutSignal( this, Base::rti_recover, (const void *)0, &RTType_void );
}

#endif /* PhoneTest_H */

// }}}RME
