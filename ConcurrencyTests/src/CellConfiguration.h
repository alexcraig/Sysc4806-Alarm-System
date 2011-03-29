// {{{RME classifier 'Logical View::CellConfiguration'

#ifndef CellConfiguration_H
#define CellConfiguration_H

#ifdef PRAGMA
#pragma interface "CellConfiguration.h"
#endif

#include <RTSystem/ConcurrencyTests.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'NUMBER_OF_CELLS'
#define NUMBER_OF_CELLS 3
// }}}RME

// {{{RME classAttribute 'SENSORS_PER_CELL'
#define SENSORS_PER_CELL 3
// }}}RME

// {{{RME classAttribute 'ALARMS_PER_CELL'
#define ALARMS_PER_CELL 3
// }}}RME

// {{{RME classAttribute 'CELL_SELFTEST_TIMEOUT'
#define CELL_SELFTEST_TIMEOUT 2
// }}}RME

// {{{RME classAttribute 'SYSTEM_SELFTEST_TIMEOUT'
#define SYSTEM_SELFTEST_TIMEOUT 3
// }}}RME

// {{{RME classAttribute 'TYPE_ALARM'
#define TYPE_ALARM 0
// }}}RME

// {{{RME classAttribute 'TYPE_SENSOR'
#define TYPE_SENSOR 1
// }}}RME

// {{{RME classAttribute 'SYSTEM_SELFTEST_INTERVAL'
#define SYSTEM_SELFTEST_INTERVAL 6
// }}}RME

// {{{RME classAttribute 'SYSTEM_BREAKIN_TIMEOUT'
#define SYSTEM_BREAKIN_TIMEOUT 10
// }}}RME

// {{{RME classAttribute 'TOTAL_SENSORS'
#define TOTAL_SENSORS NUMBER_OF_CELLS * SENSORS_PER_CELL
// }}}RME

// {{{RME classAttribute 'TOTAL_ALARMS'
#define TOTAL_ALARMS NUMBER_OF_CELLS * ALARMS_PER_CELL
// }}}RME

class CellConfiguration
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	CellConfiguration( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~CellConfiguration( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	CellConfiguration( const CellConfiguration & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	CellConfiguration & operator=( const CellConfiguration & rtg_arg );
	// }}}RME
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* CellConfiguration_H */

// }}}RME
