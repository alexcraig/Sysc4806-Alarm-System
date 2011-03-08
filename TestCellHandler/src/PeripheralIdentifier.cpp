// {{{RME classifier 'Logical View::PeripheralIdentifier'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "PeripheralIdentifier.h"
#endif

#include <RTSystem/TestCellHandler.h>
#include <PeripheralIdentifier.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_PeripheralIdentifier_init( const RTObject_class * type, PeripheralIdentifier * target )
{
	(void)new( target ) PeripheralIdentifier;
}

static void rtg_PeripheralIdentifier_copy( const RTObject_class * type, PeripheralIdentifier * target, const PeripheralIdentifier * source )
{
	(void)new( target ) PeripheralIdentifier( *source );
}

static void rtg_PeripheralIdentifier_destroy( const RTObject_class * type, PeripheralIdentifier * target )
{
	target->~PeripheralIdentifier();
}

const RTFieldDescriptor rtg_PeripheralIdentifier_fields[] =
{
	// {{{RME classAttribute 'peripheralType'
	{
		"peripheralType"
	  , RTOffsetOf( PeripheralIdentifier, peripheralType )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'cellIndex'
  , {
		"cellIndex"
	  , RTOffsetOf( PeripheralIdentifier, cellIndex )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'peripheralIndex'
  , {
		"peripheralIndex"
	  , RTOffsetOf( PeripheralIdentifier, peripheralIndex )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

const RTObject_class RTType_PeripheralIdentifier =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "PeripheralIdentifier"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( PeripheralIdentifier )
  , (RTInitFunction)rtg_PeripheralIdentifier_init
  , (RTCopyFunction)rtg_PeripheralIdentifier_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_PeripheralIdentifier_destroy
  , 3
  , rtg_PeripheralIdentifier_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
PeripheralIdentifier::PeripheralIdentifier( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
PeripheralIdentifier::~PeripheralIdentifier( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
PeripheralIdentifier::PeripheralIdentifier( const PeripheralIdentifier & rtg_arg )
	: peripheralType( rtg_arg.peripheralType )
	, cellIndex( rtg_arg.cellIndex )
	, peripheralIndex( rtg_arg.peripheralIndex )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
PeripheralIdentifier & PeripheralIdentifier::operator=( const PeripheralIdentifier & rtg_arg )
{
	if( this != &rtg_arg )
	{
		peripheralType = rtg_arg.peripheralType;
		cellIndex = rtg_arg.cellIndex;
		peripheralIndex = rtg_arg.peripheralIndex;
	}
	return *this;
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_PeripheralIdentifier_installer( RTType_PeripheralIdentifier );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
