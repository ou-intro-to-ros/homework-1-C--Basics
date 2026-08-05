// =============================================================
// test_problem_4.cpp -- Instructor autograder for Problem 4
// =============================================================
//
// This file is compiled together with the STUDENT's problem4.cpp
// and a fresh (instructor-provided) copy of problem4.hpp.
//
// It does not print pass/fail per test on purpose -- if ANY assert
// fails, the program aborts with a non-zero exit code and a message
// naming the failed condition + file/line, which is enough to grade
// on exit code alone. On full success it prints ALL TESTS PASSED.
//
// Build:
//   g++ -std=c++17 -Wall test_problem_4.cpp problem4.cpp -o test_problem_4
// Run:
//   ./test_problem_4 ; echo "Exit code: $?"

#include "problem4.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>

namespace {

bool approxEqual(double a, double b, double tol = 0.01) {
    return std::fabs(a - b) < tol;
}

void test_robot_construction_valid() {
    Robot r("Atlas", 150000.0f);
    assert(r.getName() == "Atlas");
    assert(approxEqual(r.getCost(), 150000.0f));
}

void test_robot_construction_rejects_empty_name() {
    bool threw = false;
    try {
        Robot bad("", 100.0f);
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw && "Robot constructor should throw on empty name");
}

void test_robot_construction_rejects_negative_cost() {
    bool threw = false;
    try {
        Robot bad("Bad", -1.0f);
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw && "Robot constructor should throw on negative cost");
}

void test_robot_setters_validate() {
    Robot r("Spot", 74500.0f);

    bool threwName = false;
    try {
        r.setName("");
    } catch (const std::invalid_argument&) {
        threwName = true;
    }
    assert(threwName && "setName should throw on empty name");
    assert(r.getName() == "Spot" && "name should be unchanged after rejected setName");

    bool threwCost = false;
    try {
        r.setCost(-5.0f);
    } catch (const std::invalid_argument&) {
        threwCost = true;
    }
    assert(threwCost && "setCost should throw on negative cost");
    assert(approxEqual(r.getCost(), 74500.0f) &&
           "cost should be unchanged after rejected setCost");

    r.setName("SpotMini");
    r.setCost(80000.0f);
    assert(r.getName() == "SpotMini");
    assert(approxEqual(r.getCost(), 80000.0f));
}

void test_inventory_empty_state() {
    RobotInventory inv;
    assert(inv.size() == 0);
    assert(inv.findMostExpensiveRobot() == nullptr);
    assert(approxEqual(inv.getAverageCost(), 0.0));
}

void test_inventory_add_and_size() {
    RobotInventory inv;
    inv.addRobot("Atlas", 150000.0f);
    inv.addRobot("Spot", 74500.0f);
    inv.addRobot("Ghost", 98000.0f);
    assert(inv.size() == 3);
}

void test_inventory_rejects_invalid_add() {
    RobotInventory inv;
    bool threw = false;
    try {
        inv.addRobot("", 100.0f);
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw && "addRobot should throw on empty name");
    assert(inv.size() == 0 && "rejected robot should not be added");

    threw = false;
    try {
        inv.addRobot("Bad", -50.0f);
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw && "addRobot should throw on negative cost");
    assert(inv.size() == 0 && "rejected robot should not be added");
}

void test_inventory_most_expensive() {
    RobotInventory inv;
    inv.addRobot("Atlas", 150000.0f);
    inv.addRobot("Spot", 74500.0f);
    inv.addRobot("Ghost", 98000.0f);

    const Robot* best = inv.findMostExpensiveRobot();
    assert(best != nullptr);
    assert(best->getName() == "Atlas");
    assert(approxEqual(best->getCost(), 150000.0f));
}

void test_inventory_most_expensive_tie_breaks_to_first_added() {
    RobotInventory inv;
    inv.addRobot("First", 100000.0f);
    inv.addRobot("Second", 100000.0f);

    const Robot* best = inv.findMostExpensiveRobot();
    assert(best != nullptr);
    assert(best->getName() == "First" &&
           "tie should resolve to the robot added first");
}

void test_inventory_average_cost() {
    RobotInventory inv;
    inv.addRobot("Pepper", 150000.0f);
    inv.addRobot("Salt", 74500.0f);
    inv.addRobot("Wall-E", 98000.0f);

    double expectedAvg = (150000.0 + 74500.0 + 98000.0) / 3.0;
    assert(approxEqual(inv.getAverageCost(), expectedAvg, 0.5));
}

void test_print_does_not_crash() {
    // We don't grade on exact printed formatting here (that's covered
    // by the written spec + manual spot checks), but print() must be
    // callable on both an empty and non-empty inventory without
    // crashing, including for const references.
    RobotInventory inv;
    inv.printAll();

    inv.addRobot("Atlas", 150000.0f);
    const RobotInventory& constRef = inv;
    constRef.printAll();

    Robot r("Atlas", 150000.0f);
    const Robot& constRobotRef = r;
    constRobotRef.print();
}

}  // namespace

int main() {
    test_robot_construction_valid();
    test_robot_construction_rejects_empty_name();
    test_robot_construction_rejects_negative_cost();
    test_robot_setters_validate();
    test_inventory_empty_state();
    test_inventory_add_and_size();
    test_inventory_rejects_invalid_add();
    test_inventory_most_expensive();
    test_inventory_most_expensive_tie_breaks_to_first_added();
    test_inventory_average_cost();
    test_print_does_not_crash();

    std::cout << "ALL TESTS PASSED" << std::endl;
    return 0;
}
