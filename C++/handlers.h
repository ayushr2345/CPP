#pragma once

#include "utils.h"
#include "Language/Basics.h"
#include "Language/PointersAndReferences.h"
#include "Language/CStyleStrings.h"
#include "Language/CPPStrings.h"
#include "Language/Functions.h"
#include "Language/Object Oriented Programming/ClassesAndObjects.h"
#include "Language/IOStreams.h"
#include "DSA/Recursion/Recursions.h"
#include "DSA/ArrayADT/ArrayADT.h"

namespace handlers
{
	// Language Handlers
	void Handle(basics::Basics&);
	void Handle(pointersAndReferences::PointersAndReferences&);
	void Handle(cStyleStrings::CStyleStrings&);
	void Handle(cppStrings::CPPStrings&);
	void Handle(functions::Functions&);
	void Handle(classesAndObjects::ClassesAndObjects&);
	void Handle(iostreams::IOStreams&);

	// DSA Handlers
	void Handle(recursions::Recursions&);

	template<class T>
	void Handle(arrayAdt::ArrayADT<T>&);
} // namespace handlers

#include "handlers.tpp"
