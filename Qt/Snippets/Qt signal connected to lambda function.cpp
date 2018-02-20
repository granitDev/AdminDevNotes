connect(&object, &object::signal,[=](optional arguments){ body of function here; });

//some that have actual return values must use this
connect(&object, static_cast<void(object::*)(args)>(&object::signal),
	[=](args){ body of function here; });