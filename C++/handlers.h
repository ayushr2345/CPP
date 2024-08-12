#pragma once

#include "utils.h"
#include "Language/Basics.h"
#include "Language/PointersAndReferences.h"
#include "Language/CStyleStrings.h"
#include "Language/CPPStrings.h"
#include "Language/Functions.h"
#include "Language/Object Oriented Programming/ClassesAndObjects.h"
#include "Language/IOStreams.h"

namespace handlers
{
	void Handle(basics::Basics&);
	void Handle(pointersAndReferences::PointersAndReferences&);
	void Handle(cStyleStrings::CStyleStrings&);
	void Handle(cppStrings::CPPStrings&);
	void Handle(functions::Functions&);
	void Handle(classesAndObjects::ClassesAndObjects&);
	void Handle(iostreams::IOStreams&);
} // namespace handlers
