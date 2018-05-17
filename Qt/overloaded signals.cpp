connect(&object, static_cast<void(object::*)(type, return)>(&object::signal),
	[=](args){ body of function here; });