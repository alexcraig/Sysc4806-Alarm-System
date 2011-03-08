// {{{RME classifier 'Logical View::PeripheralIdentifier'

#ifndef PeripheralIdentifier_H
#define PeripheralIdentifier_H

#ifdef PRAGMA
#pragma interface "PeripheralIdentifier.h"
#endif

#include <RTSystem/TestCellHandler.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_PeripheralIdentifier;

class PeripheralIdentifier
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'peripheralType'
	int peripheralType;
	// }}}RME
	// {{{RME classAttribute 'cellIndex'
	int cellIndex;
	// }}}RME
	// {{{RME classAttribute 'peripheralIndex'
	int peripheralIndex;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	PeripheralIdentifier( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~PeripheralIdentifier( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	PeripheralIdentifier( const PeripheralIdentifier & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	PeripheralIdentifier & operator=( const PeripheralIdentifier & rtg_arg );
	// }}}RME
};

struct RTTypedValue_PeripheralIdentifier
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_PeripheralIdentifier( const PeripheralIdentifier & rtg_value )
		: data( &rtg_value ), type( &RTType_PeripheralIdentifier )
	{
	}
	inline RTTypedValue_PeripheralIdentifier( const PeripheralIdentifier & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_PeripheralIdentifier( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* PeripheralIdentifier_H */

// }}}RME
