/*
 * SocialInfluenceDataRecord.cpp
 *
 *  Created on: Mar 4, 2023
 *      Author: kathleenkanemoto
 */
#include "SocialInfluenceDataRecord.h"

#include <sstream>
#include <iostream>

SocialInfluenceDataRecord::SocialInfluenceDataRecord(const std::string& csvLine) {

	std::cout<< "CSVline  " <<csvLine<<std::endl;

	std::istringstream ss(csvLine);
	std::string field;
	int field_count = 0;
	bool in_quotes = false;
	while (std::getline(ss, field, ',')) {
		std::cout<<"field " <<field<<std::endl;

		if (field.empty()) continue;
		if (field.front() == '"' && !in_quotes) {
			// Start of quoted string
			in_quotes = true;
			field.erase(0, 1);
			std::string fieldBack;
			while(std::getline(ss, fieldBack, '"')) {
				field += fieldBack;
			}
		}

		//std::cout<<"field " <<field<<std::endl;

		switch (field_count) {
		case 0:
			question = field;
			break;
		case 1:
			segmentType = field;
			break;
		case 2:
			segmentDescription = field;
			break;
		case 3:
			answer = field;
			break;
		case 4:
			count = std::stoi(field);
			break;
		case 5:
			percentage = std::stod(field);
			break;
		default:
			break;
		}
		++field_count;
	}
}

std::string SocialInfluenceDataRecord::toString() const {
	std::stringstream ss;
	ss << question << ',' << segmentType << ','
			<< '\"' << segmentDescription << '\"' << ','
			<< answer << ',' << count << ',' << percentage << ';';
	return ss.str();
}

bool SocialInfluenceDataRecord::operator<(const SocialInfluenceDataRecord& other) const {
	return percentage < other.percentage;
}

int SocialInfluenceDataRecord::compareTo(const SocialInfluenceDataRecord& other) const {
	if (question != other.question) {
		return question < other.question ? -1 : 1;
	}
	if (segmentType != other.segmentType) {
		return segmentType < other.segmentType ? -1 : 1;
	}
	if (segmentDescription != other.segmentDescription) {
		return segmentDescription < other.segmentDescription ? -1 : 1;
	}
	if (answer != other.answer) {
		return answer < other.answer ? -1 : 1;
	}
	if (count != other.count) {
		return count < other.count ? -1 : 1;
	}
	if (percentage != other.percentage) {
		return percentage < other.percentage ? -1 : 1;
	}
	return 0;
}
