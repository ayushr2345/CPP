#pragma once

#include "utils.h"
#include "Basics.h"
#include "PointersAndReferences.h"
#include "CStyleStrings.h"

namespace handlers
{
	void Handle(basics::Basics&);
	void Handle(pointersAndReferences::PointersAndReferences&);
	void Handle(cStyleStrings::CStyleStrings&);
} // namespace handlers
