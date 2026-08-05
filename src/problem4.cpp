#include "problem_4.hpp"
#include <iostream>

// =============================================================
// Problem 4 - Robot Inventory (Class-Based, with Pointers/Refs)
// =============================================================
//
// Implement every function declared in problem_4.hpp below.
// Do NOT change any function names, parameter types, return types,
// or the names/signature of the Robot / RobotInventory classes --
// the autograder depends on them matching exactly.
//
// You may add your own private helper functions if you want, as
// long as the public interface in problem_4.hpp is unchanged.
//
// A main() with your own manual testing/demo code is welcome in a
// SEPARATE file (e.g. main.cpp) -- do not put a main() in this file,
// since the autograder supplies its own.

// ---------------- Robot ----------------

Robot::Robot(const std::string& name, float cost) {
    // TODO: validate name/cost, throw std::invalid_argument if invalid,
    // otherwise store into name_ and cost_.
}

std::string Robot::getName() const {
    // TODO
    return "";
}

float Robot::getCost() const {
    // TODO
    return 0.0f;
}

void Robot::setName(const std::string& name) {
    // TODO
}

void Robot::setCost(float cost) {
    // TODO
}

void Robot::print() const {
    // TODO: print in the exact format described in problem_4.hpp
}

// ---------------- RobotInventory ----------------

void RobotInventory::addRobot(const std::string& name, float cost) {
    // TODO
}

void RobotInventory::printAll() const {
    // TODO
}

const Robot* RobotInventory::findMostExpensiveRobot() const {
    // TODO
    return nullptr;
}

double RobotInventory::getAverageCost() const {
    // TODO
    return 0.0;
}

size_t RobotInventory::size() const {
    // TODO
    return 0;
}
