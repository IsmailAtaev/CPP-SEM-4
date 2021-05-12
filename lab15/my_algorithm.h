#pragma once
#include <iostream>
#include "party.h"

inline bool Last_Name_Equal(const teacher& a, const teacher& b,person temp) {
	return (a.getLastname() == b.getLastname());
}

inline bool Last_Name_Equal(const party& a, const party& b,party temp) {
	return (a.getLastname() == b.getLastname());
}