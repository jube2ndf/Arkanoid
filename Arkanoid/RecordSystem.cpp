#include <fstream>
#include <filesystem>
#include "RecordSystem.h"
#include "AppSettings.h"
#include <algorithm>

void Arkanoid::App::RecordSystem::addRecord(Record rec)
{
	auto top = load(App::Settings::FILE_SAVE_TOP);
	top.push_back(rec);
	std::sort(top.begin(), top.end());
	save(App::Settings::FILE_SAVE_TOP, top);
}

std::vector<Record> Arkanoid::App::RecordSystem::getTop()
{
	return load(App::Settings::FILE_SAVE_TOP);
}

std::vector<Record> Arkanoid::App::RecordSystem::load(std::string file)
{
	std::ifstream readfile(file);
	std::vector<Record> res;
	Record b;
	while (readfile >> b.record)
	{
		res.push_back(b);
	}
	return res;
}

void Arkanoid::App::RecordSystem::save(std::string file, std::vector<Record> top)
{
	std::ofstream readfile(file);
	for (auto iter : top)
	{
		readfile << iter.record
			<< "\n";
	}
}
