#pragma once
#include <vector>
//Don't move or delite last.
enum Resource {Oil = 0, RedResource, BlueResource, OrangeResource, YellowResource, RedGoods, BlueGoods, OrangeGoods, YellowGoods, last};

class ResourceStorage
{
public:
	ResourceStorage();
	ResourceStorage(std::vector<int> storage);
	void add(Resource type, unsigned int value);
	bool trySpend(Resource type, unsigned int value);
	void spend(Resource type, unsigned int value);
	int getValue(Resource type);
	std::vector<int> getStorage();
private:
	std::vector<int> storage;
};

