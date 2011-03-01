// {{{RME classifier 'Logical View::DisplayProtocol'

#ifndef DisplayProtocol_H
#define DisplayProtocol_H

#ifdef PRAGMA
#pragma interface "DisplayProtocol.h"
#endif

#include <RTSystem/TopLevelTesting.h>

struct DisplayProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_display_string = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_DisplayProtocol = rti_display_string };

	public:
		inline RTInSignal display_string( void );
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
		enum { rtiLast_DisplayProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal display_string( const RTTypedValue_RTString & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline DisplayProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline DisplayProtocol::Base::~Base( void )
{
}

inline RTInSignal DisplayProtocol::Base::display_string( void )
{
	return RTInSignal( this, rti_display_string );
}

inline DisplayProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline DisplayProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal DisplayProtocol::Conjugate::display_string( const RTTypedValue_RTString & data )
{
	return RTOutSignal( this, Base::rti_display_string, data.data, data.type );
}

#endif /* DisplayProtocol_H */

// }}}RME
