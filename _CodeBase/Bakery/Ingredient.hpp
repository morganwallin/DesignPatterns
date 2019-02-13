//------------------------------------------------------------------------------
// Ingredient.hpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#pragma once
#include <string>
#include <iostream>
#include <utility>
using std::string;
using std::ostream;

class Ingredient {
private:
    string name;

public:
	explicit Ingredient(string name) : name(std::move(name)) {}

    string getName() const { return name; }

	explicit operator string() const { return name; }

	inline bool operator==(const Ingredient& rhs) const {
		return name == rhs.getName();
	}

	inline bool operator<(const Ingredient& rhs) const {
        return name < rhs.getName();
    }

	inline friend ostream& operator<<(ostream& os, const Ingredient& ing);
};

inline ostream& operator<<(ostream& os, const Ingredient& ing) {
	os << ing.name;
	return os;
}