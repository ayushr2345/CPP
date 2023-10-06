#pragma once

#include "utils.h"
#include "Basics.h"
#include "PointersAndReferences.h"
#include "CStyleStrings.h"
#include "CPPStrings.h"
#include "Functions.h"

namespace handlers
{
	void Handle(basics::Basics&);
	void Handle(pointersAndReferences::PointersAndReferences&);
	void Handle(cStyleStrings::CStyleStrings&);
	void Handle(cppStrings::CPPStrings&);
	void Handle(functions::Functions&);
} // namespace handlers
