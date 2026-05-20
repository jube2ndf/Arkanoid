#pragma once
#include <vector>
#include <string>
#include "Record.h"
namespace Arkanoid::App {
	class RecordSystem
	{
	public: 
		static void addRecord(Record rec);
		static std::vector<Record> getTop();
	private:
		static std::vector<Record> load(std::string file);
		static void save(std::string file, std::vector<Record> top);
	};
}