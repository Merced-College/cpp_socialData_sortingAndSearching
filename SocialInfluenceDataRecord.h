/*
 * SocialInfluenceDataRecord.h
 *
 *  Created on: Mar 4, 2023
 *      Author: kathleenkanemoto
 */
#ifndef SOCIAL_INFLUENCE_DATA_RECORD_H
#define SOCIAL_INFLUENCE_DATA_RECORD_H

#include <string>
#include <vector>

class SocialInfluenceDataRecord {
private:
    std::string question;
    std::string segmentType;
    std::string segmentDescription;
    std::string answer;
    int count;
    double percentage;

public:
    SocialInfluenceDataRecord(const std::string& csvLine);

    // Getters
    std::string getQuestion() const { return question; }
    std::string getSegmentType() const { return segmentType; }
    std::string getSegmentDescription() const { return segmentDescription; }
    std::string getAnswer() const { return answer; }
    int getCount() const { return count; }
    double getPercentage() const { return percentage; }

    // Setters
    void setQuestion(const std::string& q) { question = q; }
    void setSegmentType(const std::string& st) { segmentType = st; }
    void setSegmentDescription(const std::string& sd) { segmentDescription = sd; }
    void setAnswer(const std::string& a) { answer = a; }
    void setCount(int c) { count = c; }
    void setPercentage(double p) { percentage = p; }

    std::string toString() const;
    bool operator<(const SocialInfluenceDataRecord& other) const;
    int compareTo(const SocialInfluenceDataRecord& other) const;
};

#endif // SOCIAL_INFLUENCE_DATA_RECORD_H
