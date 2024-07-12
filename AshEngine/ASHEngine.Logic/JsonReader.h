#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <exception>

/// <summary>
/// Loads a json file and convets its data into a usable C++ object.
/// </summary>
/// <typeparam name="T">DTO object that is going to be created from the target json file.</typeparam>
template<class T>
class JsonReader
{

private:
	std::string _configType;
	std::string _filepath;
	std::ifstream _rawJson;
	nlohmann::json _parsedData;

public:
	/// <summary>
	/// Parameterized constructor containing the filepath that the JsonReader will be opening.
	/// </summary>
	/// <param name="filepath">The filepath of the json being read in.</param>
	JsonReader(std::string filepath) 
	{
		// Setting some of the base fields
		_configType = typeid(T).name();
		_filepath = filepath;

		try
		{
			// Attempting to instantiate both the ifstream and parse the read json data.
			_rawJson = std::ifstream(filepath);
			_parsedData = nlohmann::json::parse(_rawJson);

			// Closing the stream.
			_rawJson.close();
		}
		catch (std::exception error)
		{
			// Printing out the error code if the ifstream/json obj is not constructed properly.
			std::cout << "FAILURE: error while attempting to instantiate/read from json files // check your filepath" << std::endl;
		}
	}

	/// <summary>
	/// Constructs an instance of the templated type with the json data.
	/// </summary>
	/// <returns>An instance of the templated type with the loaded json data.</returns>
	T CreateConfig() 
	{
		// Set to a default of NULL
		T config = NULL;

		// >> IMPLEMENT CONVERSION LOGIC HERE <<
		// Conversion structure:
		// if (_configType == typeid(exampleDTO))
		// {
		//    config = exampleDTO(_parsedData["PropertyName"].get<PropertyDataType>())
		// }


		// If by the end of the method it is still NULL, then this 
		// method is missing the implementation for the conversion.
		if (config == NULL)
		{
			throw std::exception("FAILURE: No suitable conversion avaliable to construct a DTO.");
		}

		return config;
	}
};

