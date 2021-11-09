#pragma once
#include"Error.h"
#include<iostream>
#include<fstream>
using namespace std;

template <class T>
class Repository {
	T* entities;
	int max_value;
	int current_value;
	bool sync = true;

	void SyncWrite()
	{
		if (sync)
			WriteToFile();
	}

	void SyncRead()
	{
		if (sync)
		{
			current_value = 0;
			ReadFromFile();
		}
	}
public:
	Repository(int max_value = 100)
	{
		this->max_value = max_value;
		current_value = 0;
		entities = new T[max_value];
	}

	~Repository()
	{
		delete[] entities;
	}

	void Add(T& item)
	{
		if (current_value >= max_value)
			throw Error(ErrorCode::MaxSizeReached);

		entities[current_value++] = item;
		SyncWrite();
	}
	void Remove(int index)
	{
		if (index < 0 || index >= current_value)
			throw Error(ErrorCode::IndexOutsideLimit);

		for (int i = index; i < (current_value - 1); i++)
			entities[i] = entities[i + 1];

		current_value--;
		SyncWrite();
	}
	void Print()
	{
		SyncRead();
		cout << GetTitle() << endl;
		for (int i = 0; i < current_value; i++)
		{
			cout << entities[i];
		}
	}
	Repository& operator[](int index)
	{
		return this->entities[index];
	}
	string GetMostPopularDroneBrand()
	{
		int res = 0;
		int count = 1;
		for (int i = 0; i < current_value; i++) {
			if (entities[i].GetBrand() == entities[i].GetBrand()) {
				count++;
				return entities[i].GetBrand();
			}
			else {
				count--;
			}
			if (count == 0) {
				res = i;
				count = 1;
			}
		}
		return entities[res].GetBrand();
	}
	int GetTheCheapestDrone() {
		int min = entities[0].GetPrice();
		for (int i = 0; i < current_value; i++) {
			if (entities[i].GetPrice() < min) {
				min = entities[i].GetPrice();
				if (entities[i].GetQuantity() == 0) {
					cout << "Sorry this drone/robot" << entities[i].GetBrand() << "is not available" << endl;
				}
			}
		}
		return min;
	}
	int GetQuantityOfDronesMadeThisYear(int year) {
		int s = 0;
		for (int i = 0; i < current_value; i++) {
			if (entities[i].GetYear() == year) {
				s += entities[i].GetQuantity();
			}
		}
		if (s == 0) {
			throw Error(ErrorCode::ZeroQuantity);
		}
		return s;
	}
	int GetQuantityOfRobotMadeThisYear(int year) {
		int s = 0;
		for (int i = 0; i < current_value; i++) {
			if (entities[i].GetYear() == year) {
				s += entities[i].GetQuantity();
			}
		}
		if (s == 0) {
			throw Error(ErrorCode::ZeroQuantity);
		}
		return s;
	}
protected:
	virtual string GetTitle() { return ""; }
	virtual string GetFileName() { return ""; }

	void WriteToFile()
	{
		ofstream Write_in_File(GetFileName());
		for (int i = 0; i < current_value; i++)
		{
			Write_in_File << entities[i].to_str();
			if (i + 1 != current_value)
				Write_in_File << endl;
		}
		Write_in_File.close();
	
	}
	void ReadFromFile()
	{
		bool prevSync = sync;
		sync = false;

		ifstream fin(GetFileName());
		while (!fin.eof())
		{
			T item;
			fin >> item;
			Add(item);
		}
		fin.close();

		sync = prevSync;
	}
};
