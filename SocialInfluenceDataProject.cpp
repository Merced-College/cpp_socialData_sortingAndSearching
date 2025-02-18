//============================================================================
// Name        : socialInfluenceDataProject.cpp
// Author      : Professor Kanemoto
// Edited By   :
// Version     : 1
// Copyright   : Your copyright notice
// Description : A class to create a vector of records of type Social Influence data
//	used ChatGPT to assist in the creation of this code :)
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "SocialInfluenceDataRecord.h"

using namespace std;

//added this function to sort our data to use the binary search
bool sortByCount(const SocialInfluenceDataRecord& a, const SocialInfluenceDataRecord& b) {
	return a.getCount() < b.getCount();
}

int main() {
    vector<SocialInfluenceDataRecord> records;

    // open the file
    ifstream file("Whatsgoodlydata.csv");
    if (!file.is_open()) {
        cerr << "Error: Could not open file" << endl;
        return 1;
    }

    // ignore the header line
    string header;
    getline(file, header);

    // read each line and create a SocialInfluenceDataRecord object
    string line;
    while (getline(file, line)) {
     
        SocialInfluenceDataRecord record(line);

        // add the record to the vector
        records.push_back(record);
    }

    // close the file
    file.close();

    // print the records
    for (const auto& record : records) {
        cout << record.toString() << endl;
    }
    
	// Sort the vector by count in descending order
	std::sort(records.begin(), records.end(), sortByCount);

	//we will put our binary and linear search tests here

    return 0;
}
