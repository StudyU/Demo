#include "F:\GitHub\rapidjson\include\rapidjson\rapidjson.h"
#include "F:\GitHub\rapidjson\include\rapidjson\document.h"
#include "F:\GitHub\rapidjson\include\rapidjson\writer.h"
#include "F:\GitHub\rapidjson\include\rapidjson\stringbuffer.h"
#include <fstream>
#include <string>
#include <assert.h>
#include <iostream>
#include <windows.h>

using namespace std;
using namespace rapidjson;

#define Print(x) cout << #x " = " << (x) << endl

void testSimpleDoc() 
{
	// read json content into string.
	string      stringFromStream;
	ifstream    in;
	in.open("test.json", ifstream::in);
	if (!in.is_open())
		return;
	string line;
	while (getline(in, line)) {
		stringFromStream.append(line + "\n");
	}
	in.close();

	// ---------------------------- read json --------------------
	// parse json from string.
	Document doc;
	doc.Parse<0>(stringFromStream.c_str());
	if (doc.HasParseError()) {
		ParseErrorCode code = doc.GetParseError();
		Print(code);
		return;
	}

	// use values in parse result.
	Value & v = doc["dictVersion"];
	if (v.IsInt()) {
		Print(v.GetInt());
	}

	Value & contents = doc["content"];
	if (contents.IsArray()) {
		for (size_t i = 0; i < contents.Size(); ++i)
		{
			Value & v = contents[i];
			assert(v.IsObject());
			if (v.HasMember("key") && v["key"].IsString())
			{
				Print(v["key"].GetString());
			}

			if (v.HasMember("value") && v["value"].IsString()) 
			{
				Print(v["value"].GetString());
			}
		}
	}
	// ---------------------------- write json --------------------
	Print("add a value into array");

	Value item(Type::kObjectType);
	item.AddMember("key", "word5", doc.GetAllocator());
	item.AddMember("value", "µ¥´Ê5", doc.GetAllocator());
	contents.PushBack(item, doc.GetAllocator());

	// convert dom to string.
	StringBuffer buffer;      // in rapidjson/stringbuffer.h
	Writer<StringBuffer> writer(buffer); // in rapidjson/writer.h
	doc.Accept(writer);

	Print(buffer.GetString());
}

int main1()
{
	testSimpleDoc();

	system("pause");
	return 1;
}
