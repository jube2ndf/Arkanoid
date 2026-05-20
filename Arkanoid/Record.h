#pragma once

struct Record {
	int record;
	bool operator<(const Record& other) const
	{
		return record < other.record;
	}
};