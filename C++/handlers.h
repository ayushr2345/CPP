#pragma once

#include "utils.h"
#include "Basics.h"
#include "PointersAndReferences.h"
#include "CStyleStrings.h"
#include "CPPStrings.h"

namespace handlers
{
	void Handle(basics::Basics&);
	void Handle(pointersAndReferences::PointersAndReferences&);
	void Handle(cStyleStrings::CStyleStrings&);
	void Handle(cppStrings::CPPStrings&);
} // namespace handlers
