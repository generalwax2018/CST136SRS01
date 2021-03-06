// Exceptional.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RangeInt.h"


using namespace std; 

int main()
{
	auto errors{ 0 };
	auto unaccounted_errors{ 0 };
	

	try
	{

		
		RangeInt test(0, 4);
		test.set_value(10);
		
	}

	catch (std::out_of_range &e)
	{
		e.what();
		++errors;
	}

	try
	{

		
		RangeInt test(5, 10);
		test.set_value(1);
		
	}

	catch (std::out_of_range &e)
	{
		e.what();
		++errors;
	}

	try
	{
		
		RangeInt test(0, 15);
		test.set_value(10);
		
	}

	catch (out_of_range &e)
	{
		e.what();
		++errors;
	}

	try
	{
	
		RangeInt test(0, 15);
		test.set_value(10.0);
		
	}
	catch (out_of_range &e)
	{
		e.what();
		++errors;
	}

	try
	{
		//good
		
		RangeInt test(0, 15);
		test.set_value(10L);
		
	}

	catch (std::out_of_range &e)
	{
		e.what();
		++errors;
	}

	try
	{
		
		
		RangeInt test(0, 15);
		test.set_value(10.f);
		
	}

	catch (std::out_of_range &e)
	{
		e.what();
		++errors;
	}

	try
	{

		
		RangeInt test(0, 15);
		test.set_value(string("Junk")); //error
	
	}

	catch (std::invalid_argument &e)
	{
		e.what();
		++errors;
	}

	try
	{

		
		RangeInt test(0, 15);
		test.set_value(10L);
		test.set_upper(7); //error
		
	}

	catch (std::out_of_range &e)
	{
		e.what();
		++errors;
	}

	try
	{
		
		RangeInt test;
		test.set_value(10L);
		
	}

	catch (std::out_of_range &e)
	{
		e.what();
		++errors;
	}

	try
	{

	
		RangeInt test(15, 25);
		auto const uns_int = 17;
		test.set_value(uns_int);
		test.set_lower(18); //error
		
	}

	catch (std::out_of_range &e)
	{
		e.what();
		++errors;
	}

	try
	{
		
		
		RangeInt test(0, 15);
		test.set_value("Junk");
		
	}

	catch (std::out_of_range &e)
	{
		
		e.what();
		++errors;
	}

	catch (...)
	{
		
		++unaccounted_errors;
	}

	return errors;
}


