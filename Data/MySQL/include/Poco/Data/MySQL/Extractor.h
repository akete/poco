//
// Extractor.h
//
// $Id: //poco/1.3/Data/MySQL/include/Poco/Data/MySQL/Extractor.h#1 $
//
// Library: Data
// Package: MySQL
// Module:  Extractor
//
// Definition of the Extractor class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Data_MySQL_Extractor_INCLUDED
#define Data_MySQL_Extractor_INCLUDED


#include "Poco/Data/MySQL/MySQL.h"
#include "Poco/Data/MySQL/StatementExecutor.h"
#include "Poco/Data/MySQL/ResultMetadata.h"
#include "Poco/Data/AbstractExtractor.h"
#include "Poco/Data/BLOB.h"


namespace Poco {
namespace Data {
namespace MySQL {


class MySQL_API Extractor: public Poco::Data::AbstractExtractor
	/// Extracts and converts data values from the result row returned by MySQL.
	/// If NULL is received, the incoming val value is not changed and false is returned
{
public:
	Extractor(StatementExecutor& st, ResultMetadata& md);
		/// Creates the Extractor.

	virtual ~Extractor();
		/// Destroys the Extractor.

	virtual bool extract(std::size_t pos, Poco::Int8& val);
		/// Extracts an Int8.
		
	virtual bool extract(std::size_t pos, Poco::UInt8& val);
		/// Extracts an UInt8.
		
	virtual bool extract(std::size_t pos, Poco::Int16& val);
		/// Extracts an Int16.
		
	virtual bool extract(std::size_t pos, Poco::UInt16& val);
		/// Extracts an UInt16.
		
	virtual bool extract(std::size_t pos, Poco::Int32& val);
		/// Extracts an Int32.
		
	virtual bool extract(std::size_t pos, Poco::UInt32& val);
		/// Extracts an UInt32.
		
	virtual bool extract(std::size_t pos, Poco::Int64& val);
		/// Extracts an Int64.
		
	virtual bool extract(std::size_t pos, Poco::UInt64& val);
		/// Extracts an UInt64.
		
	virtual bool extract(std::size_t pos, bool& val);
		/// Extracts a boolean.
		
	virtual bool extract(std::size_t pos, float& val);
		/// Extracts a float.
		
	virtual bool extract(std::size_t pos, double& val);
		/// Extracts a double.
		
	virtual bool extract(std::size_t pos, char& val);
		/// Extracts a single character.
		
	virtual bool extract(std::size_t pos, std::string& val);
		/// Extracts a string.
		
	virtual bool extract(std::size_t pos, Poco::Data::BLOB& val);
		/// Extracts a BLOB.

private:

	bool realExtractFixed(std::size_t pos, enum_field_types type, void* buffer, size_t length = 0);

	// Prevent VC8 warning "operator= could not be generated"
	Extractor& operator=(const Extractor&);

private:

	StatementExecutor& _stmt;
	ResultMetadata& _metadata;
};

} } } // namespace Poco::Data::MySQL


#endif // Data_MySQL_Extractor_INCLUDED
