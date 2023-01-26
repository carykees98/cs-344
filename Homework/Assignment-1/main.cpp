#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

struct Person
{
public:
	std::string name = {};
	int arrivalTime;
	int meetingLength;
};

std::vector<Person> readInArrivals();

void createFairSchedule(const std::vector<Person> people);

void createUnfairSchedule(const std::vector<Person> people);

int main(int argc, char const *argv[])
{
	const auto people = readInArrivals();

	createFairSchedule(people);
	createUnfairSchedule(people);

	return 0;
}

std::vector<Person> readInArrivals()
{
	std::ifstream arrivals("personin.txt");
	std::vector<Person> people;
	Person temp;

	while (arrivals >> temp.name >> temp.arrivalTime >> temp.meetingLength)
	{
		people.push_back(temp);
	}

	arrivals.close();
	return people;
}

void createFairSchedule(const std::vector<Person> people)
{
	std::cout << "Fair Schedule" << std::endl
			  << "----------------------------" << std::endl;
	std::queue<Person> fairPeople;
	int nextAvailableTime = 0, currentTime = 0, meetingsCompleted = 0;
	Person currentMeeting;

	while (meetingsCompleted < people.size())
	{
		for (auto &person : people)
		{
			if (person.arrivalTime == currentTime)
			{
				fairPeople.push(person);
				std::cout << person.name << " arrived at " << person.arrivalTime << std::endl;
			}
		}
		if (currentTime == nextAvailableTime && !currentMeeting.name.empty())
		{
			std::cout << currentMeeting.name << "'s meeting finished at " << currentTime << std::endl;
			meetingsCompleted++;
		}
		if (currentTime >= fairPeople.front().arrivalTime && currentTime >= nextAvailableTime && !fairPeople.empty())
		{
			std::cout << fairPeople.front().name << "'s meeting starts at " << currentTime << std::endl;
			nextAvailableTime = fairPeople.front().meetingLength + currentTime;
			currentMeeting = fairPeople.front();
			fairPeople.pop();
		}
		currentTime++;
	}
}

void createUnfairSchedule(const std::vector<Person> people)
{
	std::cout << "Unfair Schedule" << std::endl
			  << "----------------------------" << std::endl;
	std::stack<Person> unfairPeople;
	int nextAvailableTime = 0, currentTime = 0, meetingsCompleted = 0;
	Person currentMeeting;

	while (meetingsCompleted < people.size())
	{
		for (auto &person : people)
		{
			if (person.arrivalTime == currentTime)
			{
				unfairPeople.push(person);
				std::cout << person.name << " arrived at " << person.arrivalTime << std::endl;
			}
		}
		if (currentTime == nextAvailableTime && !currentMeeting.name.empty())
		{
			std::cout << currentMeeting.name << "'s meeting finished at " << currentTime << std::endl;
			meetingsCompleted++;
		}
		if (currentTime >= unfairPeople.top().arrivalTime && currentTime >= nextAvailableTime && !unfairPeople.empty())
		{
			std::cout << unfairPeople.top().name << "'s meeting starts at " << currentTime << std::endl;
			nextAvailableTime = unfairPeople.top().meetingLength + currentTime;
			currentMeeting = unfairPeople.top();
			unfairPeople.pop();
		}
		currentTime++;
	}
}
