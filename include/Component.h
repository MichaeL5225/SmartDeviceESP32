#pragma once

#include <string>
using namespace std;

class Component
{
	private:
		static int nextId_;
		const int id_;
		const string name_;
	public:
		int getId() const;
		const string& getName() const;
		virtual ~Component();
		virtual void printStatus() const = 0;
		Component(const Component&) = delete;
		Component& operator=(const Component&) = delete;
	protected:
		Component(const string& kind, const string& name = "");
		void log(const string& message) const;
};

