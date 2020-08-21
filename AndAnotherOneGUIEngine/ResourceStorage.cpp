#include "ResourceStorage.h"

ResourceStorage::ResourceStorage()
{
	for (int i = 0; i != last; i++)
		storage.push_back(0);
}

ResourceStorage::ResourceStorage(std::vector<int> storage)
{
	for (auto a : storage)
		this->storage.push_back(a);
}

void ResourceStorage::add(Resource type, unsigned int value)
{
	storage[type] += value;
}

bool ResourceStorage::trySpend(Resource type, unsigned int value)
{
	if (storage[type] < value) 
		return false;
	storage[type] -= value;
	return true;
}

void ResourceStorage::spend(Resource type, unsigned int value)
{
	storage[type] -= value;
}

int ResourceStorage::getValue(Resource type)
{
	return storage[type];
}

std::vector<int> ResourceStorage::getStorage()
{
	return storage;
}
