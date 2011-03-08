// {{{RME classifier 'Logical View::NewProtocol2'

#ifndef NewProtocol2_H
#define NewProtocol2_H

#ifdef PRAGMA
#pragma interface "NewProtocol2.h"
#endif

#include <RTSystem/TestCellHandler.h>

struct NewProtocol2
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_NewProtocol2 = rtiLast_RTRootProtocol };

	public:
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
		enum { rtiLast_NewProtocol2 = rtiLast_RTRootProtocol };

	public:
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline NewProtocol2::Base::Base( void )
	: RTRootProtocol()
{
}

inline NewProtocol2::Base::~Base( void )
{
}

inline NewProtocol2::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline NewProtocol2::Conjugate::~Conjugate( void )
{
}

#endif /* NewProtocol2_H */

// }}}RME
